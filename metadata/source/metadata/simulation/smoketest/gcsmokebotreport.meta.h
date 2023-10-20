#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/smoketest/gcsmokebotsystemreport.meta.h>

class cGcSmokeBotReport
{
    static unsigned long long muNameHash = 0x16AC643981D10CC9;
    static unsigned long long muTemplateHash = 0x79B1C8F92E065DCC;

    unsigned long long mui64StartingUA;
    cTkDynamicArray<cGcSmokeBotSystemReport> maSystems;
}
