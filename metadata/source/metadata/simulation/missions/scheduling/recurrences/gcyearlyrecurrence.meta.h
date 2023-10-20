#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcYearlyRecurrence
{
    static unsigned long long muNameHash = 0x252EDF07EC993BBF;
    static unsigned long long muTemplateHash = 0x4B73D314D2AE425;

    int miRecurrenceMinute;
    int miRecurrenceHour;
    int miRecurrenceDay;
    cGcMonth RecurrenceMonth;
    cTkFixedString<128,char> macDebugText;
}
