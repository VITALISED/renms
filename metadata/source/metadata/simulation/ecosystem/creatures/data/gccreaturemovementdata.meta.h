#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturemoveanimdata.meta.h>

class cGcCreatureMovementData
{
    static unsigned long long muNameHash = 0x1F15CCCBBBCEC86A;
    static unsigned long long muTemplateHash = 0x13D85FADF967EDC;

    cTkDynamicArray<cGcCreatureMoveAnimData> maAnims;
    float mfMoveRange;
    float mfMoveSpeedScale;
    float mfTurnRadiusScale;
    float mfHeightMin;
    float mfHeightMax;
    float mfHeightTime;
    bool mbHerd;
}
