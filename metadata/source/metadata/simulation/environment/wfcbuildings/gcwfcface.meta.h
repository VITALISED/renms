#pragma once
#include <metadata/metadata_common.h>
enum eTransform
{
    ETransform_None = 0,
    ETransform_Rotated90 = 1,
    ETransform_Rotated180 = 2,
    ETransform_Rotated270 = 3,
    ETransform_FlippedHorizontally = 4,
}

class cGcWFCFace
{
    static unsigned long long muNameHash = 0xAD33210D14B166A3;
    static unsigned long long muTemplateHash = 0x95F7AB7D4A3778A0;

    cTkFixedString<32,char> macConnector;
    bool mbSymmetric;
    eTransform Transform;
    cTkDynamicArray<TkID<128>> maExcludedNeighboursR0;
    cTkDynamicArray<TkID<128>> maExcludedNeighboursR1;
    cTkDynamicArray<TkID<128>> maExcludedNeighboursR2;
    cTkDynamicArray<TkID<128>> maExcludedNeighboursR3;
    bool mbWalkable;
    bool mbIncomplete;
    bool mbIsEntrance;
    TkID<128> mName;
}
