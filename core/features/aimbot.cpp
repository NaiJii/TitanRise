#include "aimbot.h"

void Aimbot::OnCreateMove(CUserCmd* cmd)
{
	m_trace = nullptr;

	if (SDK::m_clientState->game_state < 2)
		return;

	CEntity* localClientPlayer = SDK::GetLocalClientPlayer();
	if (!localClientPlayer || !localClientPlayer->IsAlive()) {
		m_records->clear();
		return;
	}

	CWeaponX* weapon = localClientPlayer->GetActiveWeapon();
	if (!weapon) {
		m_records->clear();
		return;
	}

	const int wt = weapon->GetWeaponType();

	if (!Config::enabled)
		return;

	Vector_t localEyePos = localClientPlayer->EyePos();
	const bool isLocalTitan = localClientPlayer->IsTitan();
	//const bool isReadyToFire = weapon->IsReadyToFire();

	Angle_t targetAngle = {};
	Vector_t targetPos = {};
	float targetFov = (float)Config::fov;
	CEntity* target = nullptr;
	bool targetNPC = false;
	bool targetPlayer = false;
	bool targetTitan = false;

	for (int i = 1; i < SDK::m_entityList->GetHighestEntityIndex(); i++) {
		CEntity* e = SDK::m_entityList->GetClientEntity(i);
		if (!e || e == localClientPlayer)
			continue;

		if (e->GetTeam() == localClientPlayer->GetTeam())
			continue;

		if (!e->IsAlive())
			continue;

		if (!e->IsVisible())
			continue;

		const bool isPlayer = e->IsPlayer();
		const bool isNPC = e->IsNPC();
		const bool isTitan = e->IsTitan();
		const bool isDecoy = e->IsDecoy();
		const bool isHologram = e->IsHologram();
		const bool isCloaked = e->IsCloaked();

		if (isDecoy || isHologram || isCloaked)
			continue;

		if (!isLocalTitan && wt != WT_ANTITITAN && isTitan)
			continue;

		if (!isTitan && !isPlayer && !isNPC)
			continue;

		if (targetPlayer && isNPC || isTitan)
			continue;

		if (targetTitan && isNPC)
			continue;

		const Vector_t eyePos = e->EyePos();
		//const Vector_t posBetweenEyes = e->PosBetweenEyes(); crash

		const Angle_t angle = Math::CalcAngle(localEyePos, eyePos);
		const float fov = Math::Fov(cmd->m_worldViewAngles, angle);

#if 1
		if (isPlayer && i < 400) {
			Record_t record = {};
			record.m_entity = e;
			record.m_tickCount = cmd->m_tickCount;
			//record.m_flags = e->GetFlags();
			record.m_origin = e->GetAbsOrigin();
			record.m_eyePos = eyePos;
			record.m_mins = e->GetCollision()->m_mins;
			record.m_maxs = e->GetCollision()->m_maxs;
			record.m_angle = angle;
			auto& records = m_records[i];
			records.push_back(record);
			//if (records.size() > 50)
			//	records.erase(records.begin());
		}
#endif

		if (fov < targetFov) {
			targetFov = fov;
			targetAngle = angle;
			targetPos = eyePos;
			target = e;
			targetNPC = isNPC;
			targetPlayer = isPlayer;
		}

		// change team : E9 ? ? ? ? 33 C9 41 8B D0
	}

	// clean every record from each player to see if the tickcount is still valid using std::ranges
	for (std::vector<Record_t>& records : m_records) {
		records.erase(std::remove_if(records.begin(), records.end(), [cmd](const Record_t& record) {
			return record.m_tickCount + 150 < cmd->m_tickCount;
			}), records.end());
	}

	m_target = target;

	if (!target) {
		return Recoil(cmd, localClientPlayer->PunchBase() + localClientPlayer->WeaponPunch());
	}

	const bool inButtons = (true && cmd->m_buttons & EButtons::IN_ATTACK) || cmd->m_buttons & EButtons::IN_ZOOM;

	if (inButtons) {
		const bool silent = (isLocalTitan && targetTitan) || targetNPC || Config::silentFov >= targetFov;

		int tickCount = cmd->m_tickCount;
		if (!silent && m_target->GetIndex() < 400) {
			const auto& records = m_records[m_target->GetIndex()];
			if (records.size()) {
				float minFov = targetFov;

				for (const auto& record : records) {
					if (record.m_tickCount == cmd->m_tickCount) {
						break;
					}

					const float fov = Math::Fov(cmd->m_worldViewAngles, record.m_angle);
					if (fov < minFov) {
						minFov = fov;
						targetAngle = record.m_angle;
						targetPos = record.m_eyePos;
						tickCount = record.m_tickCount;
						printf("found record (%d) with fov %f\n", tickCount, fov);
					}
				}
			}
		}

		const Angle_t delta = (targetAngle - cmd->m_attackAngles).Normalize();

		if (silent) {
			cmd->m_attackAngles = targetAngle;
		}
		else {
			cmd->m_worldViewAngles += delta * (float)Config::smooth * 0.01f;
			cmd->m_tickCount = tickCount;
		}

		Recoil(cmd, localClientPlayer->PunchBase() + localClientPlayer->WeaponPunch());
	}

	const Vector_t& endPoint = localEyePos + cmd->m_worldViewAngles.ToVector().Normalized() * 8192.f;
	const Vector_t& newPos = localClientPlayer->GetAbsOrigin() + cmd->m_worldViewAngles.ToVector().Normalized() * 500.f;

	CollisionProperty_t* collision = target->GetCollision();
	const Vector_t& origin = target->GetAbsOrigin();
	//target->SetOrigin(newPos);
	const Angle_t& angles = target->GetAbsAngles();
	//target->SetAbsAngles(targetAngle);
	const Vector_t maxs = collision->m_maxs;
	const Vector_t mins = collision->m_mins;
	const Vector_t& delta = newPos - origin;
	//collision->m_maxs = maxs + delta;
	//collision->m_mins = mins + delta;

	Trace_t trace{};
	SDK::TraceSimpleLine(localEyePos, endPoint, 0x46404033, localClientPlayer, TRACE_EVERYTHING, 0, 0, trace);
	const bool onTarget = trace.entity == target;
	m_trace = &trace;

	//target->SetOrigin(origin);
	//target->SetAbsAngles(angles);
	//collision->m_maxs = maxs;
	//collision->m_mins = mins;

	if (onTarget && Config::triggerbot) {
		cmd->m_buttons |= EButtons::IN_ATTACK;
	}
}

void Aimbot::Recoil(CUserCmd* cmd, const Angle_t& punch)
{
	cmd->m_attackAngles -= punch;
}

void Aimbot::BulletPrediction(CWeaponX* weapon, CEntity* target, const Vector_t& localPos, Vector_t& targetPos)
{
	const auto bullet_speed = weapon->GetProjectileLaunchSpeed();
	const auto bullet_scale = weapon->GetProjectileGravityScale();
	const auto velocity = target->GetVelocity();
	const auto dist = targetPos.DistanceTo(localPos);
	const auto travel_time = dist / bullet_speed;

	targetPos.x += velocity.x * travel_time;
	targetPos.y += velocity.y * travel_time;
	targetPos.z += 750.f * bullet_scale * 0.5f * travel_time * travel_time;
}