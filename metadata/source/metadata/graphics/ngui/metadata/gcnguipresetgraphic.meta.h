#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcNGuiPresetGraphic
{
    static unsigned long long muNameHash = 0x247C56DDB7B4E25A;
    static unsigned long long muTemplateHash = 0xC63CBB76AABD52D4;

    TkID<128> mPresetID;
    cGcNGuiLayoutData Layout;
    cTkNGuiGraphicStyle Style;
    cTkFixedString<128,char> macImage;
}
