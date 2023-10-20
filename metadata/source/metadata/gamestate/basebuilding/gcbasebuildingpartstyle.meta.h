#pragma once
#include <metadata/metadata_common.h>
enum eStyle
{
    EStyle_None = 0,
    EStyle_Wood = 1,
    EStyle_Metal = 2,
    EStyle_Concrete = 3,
    EStyle_Stone = 4,
    EStyle_Timber = 5,
    EStyle_Fibreglass = 6,
}

class cGcBaseBuildingPartStyle
{
    static unsigned long long muNameHash = 0xCEBA5F1259779D68;
    static unsigned long long muTemplateHash = 0xA63C1943EC1792A2;

    eStyle Style;
}
