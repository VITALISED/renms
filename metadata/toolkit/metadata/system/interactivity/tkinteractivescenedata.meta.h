#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkInteractiveSceneData
{
    static unsigned long long muNameHash = 0x89317714328CB341;
    static unsigned long long muTemplateHash = 0x71813D42DFD08760;

    cTkFixedString<32,char> macId;
    cTkDynamicArray<cTkInteractiveControlData> maControls;
}
