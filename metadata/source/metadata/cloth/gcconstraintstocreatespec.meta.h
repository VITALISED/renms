#pragma once
#include <metadata/metadata_common.h>

class cGcConstraintsToCreateSpec
{
    static unsigned long long muNameHash = 0x6C0B3270B9591BB1;
    static unsigned long long muTemplateHash = 0x2796FFF182A8F194;

    bool mbHorizontal_1x0;
    float mfPushingStrength_Horizontal_1x0;
    bool mbVertical_1x0;
    float mfPushingStrength_Vertical_1x0;
    bool mbDiagonal_1x1_0011;
    float mfPushingStrength_Diagonal_1x1_0011;
    bool mbDiagonal_1x1_0110;
    float mfPushingStrength_Diagonal_1x1_0110;
    bool mbHorizontal_2x0;
    float mfPushingStrength_Horizontal_2x0;
    bool mbVertical_2x0;
    float mfPushingStrength_Vertical_2x0;
    bool mbSkewedDiagonal_2x1_0021;
    float mfPushingStrength_SkewedDiagonal_2x1_0021;
    bool mbSkewedDiagonal_2x1_2001;
    float mfPushingStrength_SkewedDiagonal_2x1_2001;
    bool mbSkewedDiagonal_2x1_1002;
    float mfPushingStrength_SkewedDiagonal_2x1_1002;
    bool mbSkewedDiagonal_2x1_0012;
    float mfPushingStrength_SkewedDiagonal_2x1_0012;
}
