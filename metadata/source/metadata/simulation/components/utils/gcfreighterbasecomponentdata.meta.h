#pragma once
#include <metadata/metadata_common.h>
enum eFreighterBaseGenerationMode
{
    EFreighterBaseGenerationMode_Prefab = 0,
    EFreighterBaseGenerationMode_WFC = 1,
}
#include <?>

class cGcFreighterBaseComponentData
{
    static unsigned long long muNameHash = 0x8201F7ADD0F5959D;
    static unsigned long long muTemplateHash = 0xF6A553967FD2E51B;

    eFreighterBaseGenerationMode FreighterBaseGenerationMode;
    cTkFixedArray<cGcFreighterBaseOptions> maFreighterBaseOptions;
    cTkFixedString<128,char> macFreighterBaseForPlayerReset;
    cTkFixedString<128,char> macWFCBuildingFile;
}
