#pragma once
#include <metadata/metadata_common.h>

class cGcAntagonistEnemy
{
    static unsigned long long muNameHash = 0xFF1B80B6AD49D2A3;
    static unsigned long long muTemplateHash = 0x5A770BA39A994ADD;

    float mfHatredFactor;
    float mfGrudgeFactor;
    cTkDynamicArray<TkID<128>> maPerceptions;
}
