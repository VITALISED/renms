#pragma once

#include <skyscraper.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/source/simulation/player/gcplayerhazardtable.meta.h>
#include <metadata/source/simulation/player/gcplayerhazardtype.meta.h>
#include <metadata/source/gamestate/gcinventoryelement.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerHazard
{
	cGcPlayerHazardTable* mpHazardTable;
	cTkBitArray<unsigned int, 32> mxHazardsActive;
	eHazard meHazardOverride;
	float mfHazardOverrideTarget;
	float mfHazardOverrideStrength;
	float mfLastHazardOverrideTime;
	cTkPhysRelVec3 mHazardOverridePosition;
	std::array<float, 6> mafHazardTimers;
	std::array<float, 6> mafHazardStateChangeTimes;
	std::array<int, 6> maiHazardChargeLastValues;
	std::array<float, 6> mafHazardLastPainTime;
	float mfLastWarningTime;
	float mfLastRestoreTime;
	std::array<cGcInventoryElement const*, 6> mapActiveShieldingItems;
	std::array<float, 6> mafLastEnergyDrainTime;
	std::array<bool, 6> mabTakenInitialHazardDamage;
	TkAudioObject mHazardAudioObject;
	TkAudioID mCurrentHazardAudioSwitch;
	bool mbHazardProtectionAudioLoopPlaying;
	cTkVector<std::pair<cGcInventoryElement const*, float>> mapActiveShieldingItemQueues[6];
};

SKYSCRAPER_END