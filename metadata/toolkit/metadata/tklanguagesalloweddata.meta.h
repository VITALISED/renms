#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tklanguages.meta.h>

class cTkLanguagesAllowedData
{
    static unsigned long long muNameHash = 0xE421F6E8B9AA4E70;
    static unsigned long long muTemplateHash = 0xE3A1447498994FC3;

    cTkDynamicArray<cTkLanguages> maAllowed;
    cTkLanguages Fallback;
}
