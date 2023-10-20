#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturetypes.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiptypes.meta.h>
enum eSpawnerMode
{
    ESpawnerMode_Hidden = 0,
    ESpawnerMode_Visible = 1,
    ESpawnerMode_HideOnSpawn = 2,
    ESpawnerMode_HiddenTimer = 3,
}
#include <metadata/utilities/data/gcresourceelement.meta.h>
#include <metadata/simulation/ecosystem/gcspawncomponentoption.meta.h>

class cGcCreatureSpawnComponentData
{
    static unsigned long long muNameHash = 0xCC070D1A8B81739E;
    static unsigned long long muTemplateHash = 0x7D4866C5B23CFEE2;

    TkID<128> mTriggerID;
    cTkFixedString<128,char> macModel;
    TkID<128> mCreature;
    cGcCreatureTypes CreatureType;
    cGcAISpaceshipTypes ShipAIOverride;
    cTkSeed mSeed;
    int miFunctionKey;
    float mfTriggerDistance;
    float mfScale;
    float mfStartTimeMin;
    float mfStartTimeMax;
    bool mbSpawnAlert;
    eSpawnerMode SpawnerMode;
    cGcResourceElement SpecificModel;
    cTkDynamicArray<cGcSpawnComponentOption> maSpawnOptionList;
}
