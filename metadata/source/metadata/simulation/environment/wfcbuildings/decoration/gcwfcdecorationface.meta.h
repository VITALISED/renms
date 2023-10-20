#pragma once
#include <metadata/metadata_common.h>
enum eCanWalk
{
    ECanWalk_None = 0,
    ECanWalk_RequireCanWalk = 1,
    ECanWalk_RequireCanNotWalk = 2,
}

class cGcWFCDecorationFace
{
    static unsigned long long muNameHash = 0x7BCF7FA8AF0C694F;
    static unsigned long long muTemplateHash = 0x931FF264F649885B;

    cTkFixedString<128,char> macRequiredFace;
    eCanWalk CanWalk;
}
