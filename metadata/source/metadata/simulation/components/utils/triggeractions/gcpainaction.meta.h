#pragma once
#include <metadata/metadata_common.h>

class cGcPainAction
{
    static unsigned long long muNameHash = 0x9B8944FB55B77041;
    static unsigned long long muTemplateHash = 0x8BB641E9E7281432;

    TkID<128> mDamage;
    float mfRadius;
    bool mbRadiusBasedDamage;
    bool mbAffectsPlayer;
    float mfRetriggerTime;
}
