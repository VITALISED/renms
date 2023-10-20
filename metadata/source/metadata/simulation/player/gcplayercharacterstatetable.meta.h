#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayercharacterstatedata.meta.h>

class cGcPlayerCharacterStateTable
{
    static unsigned long long muNameHash = 0xDE03C95CFD766DA8;
    static unsigned long long muTemplateHash = 0xB5A07A8BE7FF697F;

    cTkFixedArray<cGcPlayerCharacterStateData> maCharacterStates;
}
