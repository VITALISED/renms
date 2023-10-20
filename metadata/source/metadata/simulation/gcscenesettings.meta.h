#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcplayerspawnstatedata.meta.h>

class cGcSceneSettings
{
    static unsigned long long muNameHash = 0xF75874C269CFFEA3;
    static unsigned long long muTemplateHash = 0x3D244C4E181E581D;

    cTkFixedString<128,char> macNextSettingFile;
    cTkFixedString<128,char> macSceneFile;
    cTkDynamicArray<cTkFixedString<128,char>> maPlanetSceneFiles;
    cTkFixedString<128,char> macSolarSystemFile;
    cTkFixedArray<cTkFixedString<128,char>> maPlanetFiles;
    cTkDynamicArray<cTkFixedString<128,char>> maShipPreloadFiles;
    bool mbSpawnShip;
    bool mbSpawnInsideShip;
    cGcPlayerSpawnStateData PlayerState;
    cTkDynamicArray<cTkClassPointer> maEvents;
    cTkDynamicArray<cTkClassPointer> maPostWarpEvents;
    TkID<128> mSpawnerOptionId;
}
