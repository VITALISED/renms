#pragma once
#include <metadata/metadata_common.h>
enum eLocatorType
{
    ELocatorType_Generic1 = 0,
    ELocatorType_Generic2 = 1,
    ELocatorType_Generic3 = 2,
    ELocatorType_Generic4 = 3,
}

class cGcSolarSystemLocatorTypes
{
    static unsigned long long muNameHash = 0xB1D42EFA923F8574;
    static unsigned long long muTemplateHash = 0xEA28003C2F8842CB;

    eLocatorType LocatorType;
}
