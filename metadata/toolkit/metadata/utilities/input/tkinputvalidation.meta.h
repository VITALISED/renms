#pragma once
#include <metadata/metadata_common.h>
enum eInputValidation
{
    EInputValidation_Held = 0,
    EInputValidation_Pressed = 1,
    EInputValidation_Released = 2,
    EInputValidation_HeldOver = 3,
}

class cTkInputValidation
{
    static unsigned long long muNameHash = 0xE57F8ACB51D80972;
    static unsigned long long muTemplateHash = 0x30AC58313BDDBA37;

    eInputValidation InputValidation;
}
