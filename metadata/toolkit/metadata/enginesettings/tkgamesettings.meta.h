#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/actions/gcinputactionmapping.meta.h>
#include <metadata/utilities/input/actions/gcinputactionmapping2.meta.h>

class cTkGameSettings
{
    static unsigned long long muNameHash = 0x18F53DCA811C8E56;
    static unsigned long long muTemplateHash = 0x64289A7C149B1115;

    cTkDynamicArray<cGcInputActionMapping> maKeyMapping;
    cTkDynamicArray<cGcInputActionMapping2> maKeyMapping2;
}
