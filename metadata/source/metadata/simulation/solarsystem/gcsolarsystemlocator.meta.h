#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcSolarSystemLocator
{
    static unsigned long long muNameHash = 0x39BE669FF8F8CD9;
    static unsigned long long muTemplateHash = 0x8A1BA8C4F06F7526;

    cTkFixedString<32,char> macName;
    cGcSolarSystemLocatorTypes Type;
    cTkVector3 mPosition;
    cTkVector3 mDirection;
    float mfRadius;
}
