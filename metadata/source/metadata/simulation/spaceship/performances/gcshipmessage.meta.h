#pragma once
#include <metadata/metadata_common.h>
enum eMessageType
{
    EMessageType_Leave = 0,
    EMessageType_Fight = 1,
}

class cGcShipMessage
{
    static unsigned long long muNameHash = 0x7D370752342BB815;
    static unsigned long long muTemplateHash = 0xDCFA575FE29DF1DD;

    eMessageType MessageType;
}
