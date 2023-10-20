#pragma once
#include <metadata/metadata_common.h>

class cTkLocalisationEntry
{
    static unsigned long long muNameHash = 0xBCFA2AE11CD16318;
    static unsigned long long muTemplateHash = 0xD21A74F102B57C1A;

    TkID<256> mId;
    cTkDynamicString macEnglish;
    cTkDynamicString macFrench;
    cTkDynamicString macItalian;
    cTkDynamicString macGerman;
    cTkDynamicString macSpanish;
    cTkDynamicString macRussian;
    cTkDynamicString macPolish;
    cTkDynamicString macDutch;
    cTkDynamicString macPortuguese;
    cTkDynamicString macLatinAmericanSpanish;
    cTkDynamicString macBrazilianPortuguese;
    cTkDynamicString macSimplifiedChinese;
    cTkDynamicString macTraditionalChinese;
    cTkDynamicString macTencentChinese;
    cTkDynamicString macKorean;
    cTkDynamicString macJapanese;
    cTkDynamicString macUSEnglish;
}
