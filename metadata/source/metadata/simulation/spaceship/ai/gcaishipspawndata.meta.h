#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tkinputenum.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiproles.meta.h>
#include <metadata/simulation/spaceship/ai/gcaishipspawnmarkerdata.meta.h>
enum eSpawnShape
{
    ESpawnShape_Sphere = 0,
    ESpawnShape_Cone = 1,
}
#include <metadata/simulation/spaceship/gcshipaiperformancearray.meta.h>
#include <metadata/simulation/spaceship/ai/gcaishipspawndata.meta.h>

class cGcAIShipSpawnData
{
    static unsigned long long muNameHash = 0x35C91009067A6431;
    static unsigned long long muTemplateHash = 0x9CE6A6ED6DE9D4B5;

    TkID<256> mMessage;
    TkID<256> mCombatMessage;
    TkID<256> mOSDMessage;
    cTkInputEnum Shortcut;
    bool mbWarpIn;
    cGcAISpaceshipRoles Role;
    float mfMinRange;
    cTkVector2 mScale;
    TkID<128> mReward;
    TkID<256> mRewardMessage;
    cGcAIShipSpawnMarkerData MarkerData;
    bool mbAttackFreighter;
    cTkVector2 mSpread;
    cTkVector2 mCount;
    cTkVector2 mStartTime;
    eSpawnShape SpawnShape;
    cGcShipAIPerformanceArray Performances;
    cTkDynamicArray<cGcAIShipSpawnData> maChildSpawns;
}
