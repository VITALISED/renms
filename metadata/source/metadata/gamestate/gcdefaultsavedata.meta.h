#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcplayerstatedata.meta.h>
#include <metadata/gamestate/gcplayerspawnstatedata.meta.h>

class cGcDefaultSaveData
{
    static unsigned long long muNameHash = 0xF0829DCD8555A52E;
    static unsigned long long muTemplateHash = 0x9C67E3A79F37ACA0;

    cGcPlayerStateData State;
    cGcPlayerSpawnStateData Spawn;
}
