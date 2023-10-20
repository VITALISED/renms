#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/scheduling/gcday.meta.h>

class cGcWeeklyRecurrence
{
    static unsigned long long muNameHash = 0xB686CC9F04962DFA;
    static unsigned long long muTemplateHash = 0xA57E8D6B89E55536;

    int miRecurrenceMinute;
    int miRecurrenceHour;
    cGcDay RecurrenceDay;
    cTkFixedString<128,char> macDebugText;
}
