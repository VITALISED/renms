#pragma once
#include <metadata/metadata_common.h>

class cGcMessageTrackTargetAlert
{
    static unsigned long long muNameHash = 0xACD740CC9B208196;
    static unsigned long long muTemplateHash = 0xF90EE308A4458A80;

    int miAttacker;
    int miVictim;
    cTkVector3 mAlertPos;
    bool mbPrimary;
}
