#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcPlayerControlComponentData
{
    static unsigned long long muNameHash = 0xE15445D2CE8FD16D;
    static unsigned long long muTemplateHash = 0xA1DBD4B57660CA14;

    TkID<128> mInitialState;
    cGcPlayerControlInput BaseInput;
    TkID<128> mBaseCamera;
    cTkDynamicArray<cGcPlayerControlState> maStates;
    cTkBlackboardKey AimDir;
    cTkBlackboardKey TorchDir;
    cTkBlackboardKey CrosshairDir;
}
