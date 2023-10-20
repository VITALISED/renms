#pragma once
#include <metadata/metadata_common.h>
enum eFaceDir
{
    EFaceDir_Random = 0,
    EFaceDir_TowardsPlayer = 1,
    EFaceDir_SpawnerAt = 2,
}

class cGcPlayerExperienceSpawnData
{
    static unsigned long long muNameHash = 0x76E523097495B90;
    static unsigned long long muTemplateHash = 0xB547ACA99002043A;

    TkID<128> mArchetype;
    TkID<128> mAppearAnim;
    TkID<128> mSpawnLocator;
    TkID<256> mSpawnLocatorScanEvent;
    eFaceDir FaceDir;
    float mfMinDist;
    float mfMaxDist;
    cTkFixedArray<int> maMinNum;
    cTkFixedArray<int> maMaxNum;
    float mfActiveTime;
}
