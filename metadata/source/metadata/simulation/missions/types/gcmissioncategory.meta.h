#pragma once
#include <metadata/metadata_common.h>
enum eMissionCategory
{
    EMissionCategory_Info = 0,
    EMissionCategory_Mission = 1,
    EMissionCategory_Danger = 2,
    EMissionCategory_Urgent = 3,
}

class cGcMissionCategory
{
    static unsigned long long muNameHash = 0x7C883BFCF9D557D5;
    static unsigned long long muTemplateHash = 0xDC7EAA7B8B8B89D7;

    eMissionCategory MissionCategory;
}
