#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gctextpreset.meta.h>

class cGcTextPresetTable
{
    static unsigned long long muNameHash = 0x6567927C2DD8F89F;
    static unsigned long long muTemplateHash = 0x2EF09080D6638588;

    cTkDynamicArray<cGcTextPreset> maTable;
}
