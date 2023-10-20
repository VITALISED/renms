#pragma once
#include <metadata/metadata_common.h>
enum eInputHand
{
    EInputHand_None = 0,
    EInputHand_Left = 1,
    EInputHand_Right = 2,
}

class cTkInputHandEnum
{
    static unsigned long long muNameHash = 0xC47947D0C35F984E;
    static unsigned long long muTemplateHash = 0xCB7BDE80465F24BC;

    eInputHand InputHand;
}
