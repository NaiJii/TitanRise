#pragma once

//struct CGlobalVars {
//	float realtime; // 0x0000
//	int framecount; // 0x0004
//	float absoluteframetime; // 0x0008
//	float curtime; // 0x000C
//	float frametime; // 0x0010
//	int tickcount;
//	float unk;
//	float interval_per_tick;
//	float interpolation_amount;
//	int simTicksThisFrame;
//	int network_protocol;
//};

struct CGlobalVars {
	PAD(0x8); // 0x0 (0x8) - realtime
	int m_frameCount; // 0x8 (0x4)
	PAD(0x4); // 0xC (0x4) - absoluteframetime
	float m_curTime; // 0x10 (0x4)
	PAD(0xC); // 0x14 (0xC)
	float m_float20; // 0x20 (0x4)
	int m_commandTick; // 0x24 (0x4)
	PAD(0x4); // 0x28 (0x4)
	float m_float2C; // 0x2C (0x4)
	float m_frameTime; // 0x30 (0x4)
	int m_playerCount; // 0x34 (0x4)
	PAD(0x4); // 0x38 (0x4)
	unsigned int m_tickCount; // 0x3C (0x4)
	float m_intervalPerTick; // 0x40 (0x4)
};