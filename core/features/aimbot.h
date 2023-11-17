#pragma once

#include "../../sdk/sdk.h"

struct Record_t {
	CEntity* m_entity;
	int m_tickCount;
	int m_flags;
	Vector_t m_origin;
	Vector_t m_eyePos;
	Vector_t m_mins;
	Vector_t m_maxs;
	Angle_t m_angle;

	Record_t() = default;
	Record_t(CEntity* e, int tick, Angle_t angle) {
		m_entity = e;
		m_tickCount = tick;
		m_flags = 0;//e->GetFlags(); crash
		m_origin = e->GetAbsOrigin();
		m_eyePos = e->EyePos();
		const auto collision = e->GetCollision();
		m_mins = collision->m_mins;
		m_maxs = collision->m_maxs;
		m_angle = angle;
	}

	bool IsValid() const {
		return m_entity && m_entity->IsAlive() && m_entity->GetHealth() > 0;
	}

	void Restore(CEntity* e) {
		// e->GetFlags() = m_flags;
		e->GetAbsOrigin() = m_origin;
		e->GetCollision()->m_mins = m_mins;
		e->GetCollision()->m_maxs = m_maxs;
		e->EyePos() = m_eyePos;
	}
};

namespace Aimbot {
	void OnCreateMove(CUserCmd* cmd);
	void Recoil(CUserCmd* cmd, const Angle_t& punch);
	void BulletPrediction(CWeaponX* weapon, CEntity* target, const Vector_t& localPos, Vector_t& targetPos);

	inline CEntity* m_target = nullptr;
	inline std::vector<Record_t> m_records[400];
	inline Trace_t* m_trace = nullptr;

	namespace Config {
		inline bool enabled = true;
		inline int fov = 20;
		inline int silentFov = 0;
		inline int smooth = 10;
		inline bool triggerbot = false;
	}
}
