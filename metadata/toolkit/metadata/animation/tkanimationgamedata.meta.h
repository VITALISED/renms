#pragma once
#include <metadata/metadata_common.h>
enum eBlockPlayerWeapon
{
    EBlockPlayerWeapon_Unblocked = 0,
    EBlockPlayerWeapon_Sheathed = 1,
    EBlockPlayerWeapon_OutButCannotFire = 2,
}

class cTkAnimationGameData
{
    static unsigned long long muNameHash = 0x4CC02B5A253167FD;
    static unsigned long long muTemplateHash = 0x2B2AAF52924FA65D;

    bool mbRootMotionEnabled;
    bool mbBlockPlayerMovement;
    eBlockPlayerWeapon BlockPlayerWeapon;
}
