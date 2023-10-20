#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcWFCModuleSet
{
    static unsigned long long muNameHash = 0x12D00A471DB28074;
    static unsigned long long muTemplateHash = 0x717FDA53500C424;

    cTkFixedString<32,char> macName;
    cTkVector3 mBlockSize;
    bool mbApplyWallThemes;
    cTkDynamicArray<cGcWFCModulePrototype> maModulePrototypes;
    cTkDynamicArray<cTkFixedString<32,char>> maConnectorsOnUpperBoundary;
    cTkDynamicArray<cTkFixedString<32,char>> maConnectorsOnLowerBoundary;
    cTkDynamicArray<cTkFixedString<32,char>> maConnectorsOnHorizontalBoundary;
    cTkDynamicArray<TkID<128>> maDefaultGroups;
    cTkDynamicArray<cGcIDPair> maCompatibleConnectors;
    float mfVerticalOffset;
}
