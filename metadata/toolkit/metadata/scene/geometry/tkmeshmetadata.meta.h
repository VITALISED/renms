#pragma once
#include <metadata/metadata_common.h>

class cTkMeshMetaData
{
    static unsigned long long muNameHash = 0x4CF5A27A1458612D;
    static unsigned long long muTemplateHash = 0xCD95EDB97D142FC;

    cTkFixedString<128,char> macIdString;
    unsigned long long mui64Hash;
    int miVertexDataSize;
    int miVertexDataOffset;
    int miIndexDataSize;
    int miIndexDataOffset;
    bool mbDoubleBufferGeometry;
}
