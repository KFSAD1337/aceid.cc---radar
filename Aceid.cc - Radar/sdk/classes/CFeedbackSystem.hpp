#pragma once

#ifndef CFEEDBACKSYSTEM_HPP
#define CFEEDBACKSYSTEM_HPP

#include "../helpers/helpers.hpp"

struct Vec3 { float x, y, z; };

struct SFeedbackEventParams { virtual void Function0() { }; };
struct SMarkerParams : SFeedbackEventParams {

	EntityId m_entity;
	Vec3 m_pos;
};

struct SDynamicMarkerParams {

	float intensity;
	unsigned int time;
	char healthPercent;
	char armorPercent;
	char ammoPercent;
	float progress;
};

class CFeedbackSystem {
public:

	struct SMarker {

		int Id;
		int HUDIconID;
		int RaceIconID;
		int RadialHUDIconID;
		int MinimapIconID;
		int HUDSilhouetteID;
		int DistanceLabelID;
		int HUDTextLabelID;
		int HUDStatusInfoID;
		class CParticleMarker* particle;
		int HUDCountdownTimerID;
		int RadarIconID;
		int HUDBadgeID;
		bool TutorialHint;
		SDynamicMarkerParams params;
	};

	using fnReset = void(__fastcall*)(CFeedbackSystem*);
	using fnRemoveMarker = char(__fastcall*)(CFeedbackSystem*, int);
	using fnAddMarker = signed __int64(__fastcall*)(CFeedbackSystem*, const char*, const SMarkerParams*);

public:

	signed __int64 AddMarker(const char* name, const SMarkerParams* params) { 
		return fnAddMarker(0x141092340)(this, name, params);
	}

	char RemoveMarker(int id) {
		return fnRemoveMarker(0x141092560)(this, id); 
	}

public:

	std::byte padding[0x68];
	std::list< CFeedbackSystem::SMarker, std::allocator< SMarker > > m_markerInstances;
};

#endif // !CFEEDBACKSYSTEM_HPP