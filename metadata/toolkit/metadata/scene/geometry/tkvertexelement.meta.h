#pragma once
#include <metadata/metadata_common.h>
enum eInstancing
{
    EInstancing_PerVertex = 0,
    EInstancing_PerModel = 1,
}

class cTkVertexElement
{
    static unsigned long long muNameHash = 0x8687A0CA8457FC32;
    static unsigned long long muTemplateHash = 0x1E084E1510B4A072;

    int miSemanticID;
    int miSize;
    int miType;
    int miOffset;
    int miNormalise;
    eInstancing Instancing;
    long long mi64PlatformData;
}
