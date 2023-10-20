#pragma once
#include <metadata/metadata_common.h>
enum eWealthClass
{
    EWealthClass_Poor = 0,
    EWealthClass_Average = 1,
    EWealthClass_Wealthy = 2,
    EWealthClass_Pirate = 3,
}

class cGcWealthClass
{
    static unsigned long long muNameHash = 0xC0B928F5E2599F60;
    static unsigned long long muTemplateHash = 0xEF25EE5283DBF5E4;

    eWealthClass WealthClass;
}
