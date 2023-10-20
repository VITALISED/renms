#pragma once
#include <metadata/metadata_common.h>
enum eMoveMode
{
    EMoveMode_Roll = 0,
    EMoveMode_Float = 1,
    EMoveMode_Drill = 2,
}

class cGcCreatureWeirdMovementData
{
    static unsigned long long muNameHash = 0xBE42E310FC94C8E3;
    static unsigned long long muTemplateHash = 0xE92FCC2DF81C6C7D;

    eMoveMode MoveMode;
    cTkFixedString<256,char> macNode;
    float mfBobSpeed;
    float mfBobAmount;
    float mfSpinSpeed;
    float mfJumpAngle;
    cTkDynamicArray<cTkFixedString<256,char>> maFeetNames;
}
