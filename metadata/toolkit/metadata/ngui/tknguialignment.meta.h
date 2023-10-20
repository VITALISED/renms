#pragma once
#include <metadata/metadata_common.h>
enum eVertical
{
    EVertical_Top = 0,
    EVertical_Middle = 1,
    EVertical_Bottom = 2,
}

class cTkNGuiAlignment
{
    static unsigned long long muNameHash = 0xD1E7F0BE0B98FD48;
    static unsigned long long muTemplateHash = 0x71FA853C1F36341F;

    eVertical Vertical;
    eHorizontal Horizontal;
}
