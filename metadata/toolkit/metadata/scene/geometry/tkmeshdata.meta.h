#pragma once
#include <metadata/metadata_common.h>

class cTkMeshData
{
    static unsigned long long muNameHash = 0xF671716161E708E3;
    static unsigned long long muTemplateHash = 0xD3AC8F6F7A4D55FC;

    cTkFixedString<128,char> macIdString;
    unsigned long long mui64Hash;
    int miVertexDataSize;
    int miIndexDataSize;
    cTkDynamicArray<unsigned char> maMeshDataStream;
}
