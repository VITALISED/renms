#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcBehaviourLookData
{
    static unsigned long long muNameHash = 0x79CECC228E0EBC79;
    static unsigned long long muTemplateHash = 0xF530CA0023DD90CA;

    TkID<128> mLookTargetKey;
    bool mbLookWhenBeyondMaxAngle;
    cTkBlackboardDefaultValueBool FocusOnTarget;
    cTkBlackboardDefaultValueBool RelaxedLook;
    cTkBlackboardDefaultValueBool CanLook;
}
