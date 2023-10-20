#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcOutSnapSocketCondition
{
    static unsigned long long muNameHash = 0xC8A6AD07D6C1D49E;
    static unsigned long long muTemplateHash = 0x48F1C4ABA10746D7;

    cTkFixedString<128,char> macSnapPoint;
    cTkFixedString<128,char> macOutSocket;
    cGcBaseSnapState SnapState;
    TkID<128> mObjectId;
    int miSnapPointIndex;
    int miOutSocketIndex;
}
