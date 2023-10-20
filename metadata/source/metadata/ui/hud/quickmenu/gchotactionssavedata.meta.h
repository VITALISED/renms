#pragma once
#include <metadata/metadata_common.h>
#include <metadata/ui/hud/quickmenu/gcquickmenuactionsavedata.meta.h>

class cGcHotActionsSaveData
{
    static unsigned long long muNameHash = 0xE6D4EE849D2F9101;
    static unsigned long long muTemplateHash = 0x1E124BFF067C79EA;

    cTkFixedArray<cGcQuickMenuActionSaveData> maKeyActions;
}
