#pragma once
#include <metadata/metadata_common.h>

class cTkMaterialShaderMillComment
{
    static unsigned long long muNameHash = 0x69D7A72052C55F5E;
    static unsigned long long muTemplateHash = 0x5FBAD246CAD02FB4;

    cTkFixedString<1024,char> macText;
    int miPosMinX;
    int miPosMinY;
    int miPosMaxX;
    int miPosMaxY;
}
