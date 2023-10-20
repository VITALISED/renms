#pragma once
#include <metadata/metadata_common.h>
enum eSucceedWhen
{
    ESucceedWhen_AllChildrenSucceed = 0,
    ESucceedWhen_AnyChildSucceeds = 1,
}

class cTkBehaviourTreeConcurrentSelectorData
{
    static unsigned long long muNameHash = 0x5A80A9FE39381A77;
    static unsigned long long muTemplateHash = 0x27BAAF4A069EC62C;

    TkID<128> mName;
    eSucceedWhen SucceedWhen;
    eFailWhen FailWhen;
    cTkDynamicArray<cTkClassPointer> maChildren;
}
