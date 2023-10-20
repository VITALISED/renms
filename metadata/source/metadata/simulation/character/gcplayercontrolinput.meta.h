#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/actions/gcinputactions.meta.h>

class cGcPlayerControlInput
{
    static unsigned long long muNameHash = 0xD2873CCA9A0EDD77;
    static unsigned long long muTemplateHash = 0x3195411FB3EE778B;

    bool mbInterceptAllInputs;
    cTkDynamicArray<cGcInputActions> maInterceptInputWhitelist;
    cTkDynamicArray<cGcInputActions> maInterceptInputBlackList;
    cTkDynamicArray<cTkClassPointer> maInputs;
}
