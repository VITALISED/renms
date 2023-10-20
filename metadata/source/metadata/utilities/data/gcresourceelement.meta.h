#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkproceduraltexturechosenoptionlist.meta.h>

class cGcResourceElement
{
    static unsigned long long muNameHash = 0x91CAC70AC2792E2A;
    static unsigned long long muTemplateHash = 0x1F488BEDB7326A29;

    cTkFixedString<128,char> macFilename;
    cTkSmartResHandle mResHandle;
    cTkSeed mSeed;
    cTkFixedString<512,char> macAltId;
    cTkProceduralTextureChosenOptionList ProceduralTexture;
}
