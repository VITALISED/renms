#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>

class cGcPlayerHazardData
{
    static unsigned long long muNameHash = 0x18642126695741B5;
    static unsigned long long muTemplateHash = 0x362521D640B1A7DE;

    float mfProtectionInitialTime;
    cTkVector2 mProtectionTime;
    cTkVector2 mDamageRate;
    cTkVector2 mWoundRate;
    float mfRechargeInitialTime;
    float mfRechargeTime;
    TkID<128> mDamage;
    bool mbIncreases;
    cTkCurveType DisplayCurve;
    float mfTriggerValue;
    float mfCapValue;
    float mfCriticalValue;
    float mfOutputMultiplier;
    float mfOutputMinAddition;
    float mfOutputMaxAddition;
}
