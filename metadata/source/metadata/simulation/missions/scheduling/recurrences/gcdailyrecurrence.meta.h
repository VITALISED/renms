#pragma once
#include <metadata/metadata_common.h>

class cGcDailyRecurrence
{
    static unsigned long long muNameHash = 0xA4B99A409C0C214B;
    static unsigned long long muTemplateHash = 0x97FB1C988472469D;

    int miRecurrenceMinute;
    int miRecurrenceHour;
    cTkFixedString<128,char> macDebugText;
}
