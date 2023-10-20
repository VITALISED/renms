#pragma once
#include <metadata/metadata_common.h>
enum eMonth
{
    EMonth_January = 0,
    EMonth_February = 1,
    EMonth_March = 2,
    EMonth_April = 3,
    EMonth_May = 4,
    EMonth_June = 5,
    EMonth_July = 6,
    EMonth_August = 7,
    EMonth_September = 8,
    EMonth_October = 9,
    EMonth_November = 10,
    EMonth_December = 11,
}

class cGcMonth
{
    static unsigned long long muNameHash = 0x498BE03D1C172203;
    static unsigned long long muTemplateHash = 0x7212715AB678D0C3;

    eMonth Month;
}
