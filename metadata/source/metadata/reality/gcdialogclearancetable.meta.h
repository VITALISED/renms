#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcdialogclearanceinfo.meta.h>

class cGcDialogClearanceTable
{
    static unsigned long long muNameHash = 0xA2B1571E48DBF03D;
    static unsigned long long muTemplateHash = 0xB8AC30FB0591F727;

    cTkDynamicArray<cGcDialogClearanceInfo> maTable;
}
