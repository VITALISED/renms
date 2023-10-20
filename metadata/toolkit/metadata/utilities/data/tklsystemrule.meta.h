#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tklsysteminnerrule.meta.h>
enum eRuleType
{
    ERuleType_Default = 0,
    ERuleType_BaseRule = 1,
}

class cTkLSystemRule
{
    static unsigned long long muNameHash = 0xE09F11724D654285;
    static unsigned long long muTemplateHash = 0xEF32A99A1BE66F73;

    cTkFixedString<32,char> macName;
    cTkFixedString<128,char> macModel;
    cTkDynamicArray<cTkLSystemInnerRule> maRules;
    eRuleType RuleType;
}
