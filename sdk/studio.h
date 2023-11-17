#pragma once

struct StudioBbox_t {
	uint16_t bone;
	uint16_t group;
	Vector_t min;
	Vector_t max;
	uint16_t nameIndex;
	uint16_t pad;
};

struct StudioHitboxSet_t {
	uint16_t hitboxSetNameIndex;
	uint16_t hitboxCount;
	uint16_t hitboxIndex;

	StudioBbox_t* Hitbox(int i) const {
		return (StudioBbox_t*)(this + hitboxIndex) + i;
	}
};

struct StudioHdr_t {
	uint16_t id;
	uint16_t version;
	PAD(48);
	uint16_t hitboxSetIndex;
	uint16_t hitboxSetCount;

	StudioHitboxSet_t* HitboxSet(int i) const {
		return (StudioHitboxSet_t*)(this + hitboxSetIndex) + i;
	}
};