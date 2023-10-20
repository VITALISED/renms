#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/character/gccharactercontrolinputvalidity.meta.h>
#include <metadata/utilities/input/actions/gcinputactions.meta.h>
enum eInputRemapMode
{
    EInputRemapMode_ReplaceOriginalBinding = 0,
    EInputRemapMode_AdditionalBinding = 1,
}

class cGcPlayerControlInputRemap
{
    static unsigned long long muNameHash = 0x907551D5CDAAAA41;
    static unsigned long long muTemplateHash = 0xCC3BF88C243770D9;

    cGcCharacterControlInputValidity Validity;
    cGcInputActions Action;
    cGcInputActions CanBeTriggeredBy;
    eInputRemapMode InputRemapMode;
}
