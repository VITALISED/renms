#pragma once
#include <metadata/metadata_common.h>
#include <metadata/ngui/tknguiforcedstyle.meta.h>
#include <metadata/graphics/ngui/metadata/gcnguilayoutdata.meta.h>

class cGcNGuiElementData
{
    static unsigned long long muNameHash = 0xF10587272870E7F4;
    static unsigned long long muTemplateHash = 0xD274DEB39D9026A1;

    TkID<128> mID;
    TkID<128> mPresetID;
    bool mbIsHidden;
    cTkNGuiForcedStyle ForcedStyle;
    cGcNGuiLayoutData Layout;
}
