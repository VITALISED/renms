#pragma once
#include <metadata/metadata_common.h>
enum eKeyPress
{
    EKeyPress_1 = 0,
    EKeyPress_2 = 1,
    EKeyPress_3 = 2,
    EKeyPress_4 = 3,
    EKeyPress_5 = 4,
    EKeyPress_6 = 5,
    EKeyPress_7 = 6,
    EKeyPress_8 = 7,
    EKeyPress_9 = 8,
    EKeyPress_PadUp = 9,
    EKeyPress_PadDown = 10,
    EKeyPress_PadLeft = 11,
    EKeyPress_PadRight = 12,
}
#include <?>

class cGcExperienceDebugTriggerInput
{
    static unsigned long long muNameHash = 0xBCDA670B36E2534;
    static unsigned long long muTemplateHash = 0xC72994D29824460B;

    eKeyPress KeyPress;
    cTkDynamicArray<cGcExperienceDebugTriggerAction> maActions;
}
