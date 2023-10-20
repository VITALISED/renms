#pragma once
#include <metadata/metadata_common.h>
enum eSignalScanType
{
    ESignalScanType_None = 0,
    ESignalScanType_DropPod = 1,
    ESignalScanType_Shelter = 2,
    ESignalScanType_Search = 3,
    ESignalScanType_Relic = 4,
    ESignalScanType_Industrial = 5,
    ESignalScanType_Alien = 6,
    ESignalScanType_CrashedFreighter = 7,
}

class cGcRewardSignalScan
{
    static unsigned long long muNameHash = 0xEDA5BCF252E3B6EF;
    static unsigned long long muTemplateHash = 0x84054D993BC6A79E;

    eSignalScanType SignalScanType;
}
