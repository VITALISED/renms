#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/tkcontrollerbuttonlookup.meta.h>

class cTkControllerList
{
    static unsigned long long muNameHash = 0x3542E107D9C3C98;
    static unsigned long long muTemplateHash = 0xC58FEE8B73C5D76D;

    cTkDynamicArray<cTkControllerButtonLookup> maControllers;
}
