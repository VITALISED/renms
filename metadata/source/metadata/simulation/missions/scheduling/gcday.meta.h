#pragma once
#include <metadata/metadata_common.h>
enum eDay
{
    EDay_Sunday = 0,
    EDay_Monday = 1,
    EDay_Tuesday = 2,
    EDay_Wednesday = 3,
    EDay_Thursday = 4,
    EDay_Friday = 5,
    EDay_Saturday = 6,
}

class cGcDay
{
    static unsigned long long muNameHash = 0xE8931C5D607657DE;
    static unsigned long long muTemplateHash = 0x64F01908C5305F87;

    eDay Day;
}
