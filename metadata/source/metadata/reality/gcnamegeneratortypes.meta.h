#pragma once
#include <metadata/metadata_common.h>
enum eMarkovSelector
{
    EMarkovSelector_Generic = 0,
    EMarkovSelector_Mineral = 1,
    EMarkovSelector_Region_NO = 2,
    EMarkovSelector_Region_RU = 3,
    EMarkovSelector_Region_CH = 4,
    EMarkovSelector_Region_JP = 5,
    EMarkovSelector_Region_LT = 6,
    EMarkovSelector_Region_FL = 7,
}

class cGcNameGeneratorTypes
{
    static unsigned long long muNameHash = 0xC9FA06A9CF2CE65D;
    static unsigned long long muTemplateHash = 0xF92787E043F5AC70;

    eMarkovSelector MarkovSelector;
}
