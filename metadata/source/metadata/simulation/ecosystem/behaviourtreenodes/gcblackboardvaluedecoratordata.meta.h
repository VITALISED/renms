#pragma once
#include <metadata/metadata_common.h>

class cGcBlackboardValueDecoratorData
{
    static unsigned long long muNameHash = 0x27C076F10CE0DEC2;
    static unsigned long long muTemplateHash = 0x95D7E51CBBB0370B;

    TkID<128> mKey;
    bool mbClearOnSuccess;
    cTkClassPointer mChild;
}
