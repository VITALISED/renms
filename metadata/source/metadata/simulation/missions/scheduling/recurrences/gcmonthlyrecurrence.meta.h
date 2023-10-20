#pragma once
#include <metadata/metadata_common.h>

class cGcMonthlyRecurrence
{
    static unsigned long long muNameHash = 0x5CB869EED69B0A9;
    static unsigned long long muTemplateHash = 0x59C5D6F7DA3AEBA7;

    int miRecurrenceMinute;
    int miRecurrenceHour;
    int miRecurrenceDay;
    cTkFixedString<128,char> macDebugText;
}
