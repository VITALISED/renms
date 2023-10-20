#pragma once
#include <metadata/metadata_common.h>
enum eBaseAutoPowerSetting
{
    EBaseAutoPowerSetting_UseDefault = 0,
    EBaseAutoPowerSetting_ForceDisabled = 1,
    EBaseAutoPowerSetting_ForceEnabled = 2,
}

class cGcBaseAutoPowerSetting
{
    static unsigned long long muNameHash = 0x801DCAAD4B4FAC26;
    static unsigned long long muTemplateHash = 0xD00027FD44908DFE;

    eBaseAutoPowerSetting BaseAutoPowerSetting;
}
