#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCustomisationTextureOption
{
    static unsigned long long muNameHash = 0xCDB7AC6D11C9DF03;
    static unsigned long long muTemplateHash = 0xF263C6383800CDEF;

    TkID<128> mTextureOptionsID;
    TkID<128> mLayer;
    TkID<128> mGroup;
    cTkPaletteTexture Palette;
    cTkDynamicArray<TkID<256>> maOptions;
    cTkDynamicArray<TkID<256>> maTips;
}
