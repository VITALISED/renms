#pragma once
#include <metadata/metadata_common.h>
enum eLanguage
{
    ELanguage_Default = 0,
    ELanguage_English = 1,
    ELanguage_USEnglish = 2,
    ELanguage_French = 3,
    ELanguage_Italian = 4,
    ELanguage_German = 5,
    ELanguage_Spanish = 6,
    ELanguage_Russian = 7,
    ELanguage_Polish = 8,
    ELanguage_Dutch = 9,
    ELanguage_Portuguese = 10,
    ELanguage_LatinAmericanSpanish = 11,
    ELanguage_BrazilianPortuguese = 12,
    ELanguage_Japanese = 13,
    ELanguage_TraditionalChinese = 14,
    ELanguage_SimplifiedChinese = 15,
    ELanguage_TencentChinese = 16,
    ELanguage_Korean = 17,
}

class cTkLanguages
{
    static unsigned long long muNameHash = 0xEA37791FF01A5AF4;
    static unsigned long long muTemplateHash = 0x370D5A3B36E0E0F1;

    eLanguage Language;
}
