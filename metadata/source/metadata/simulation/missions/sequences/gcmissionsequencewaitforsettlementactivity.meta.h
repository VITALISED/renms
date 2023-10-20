#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForSettlementActivity
{
    static unsigned long long muNameHash = 0x13DC6DC343F05;
    static unsigned long long muTemplateHash = 0xED92D28584E03751;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macMessageWhileBuilding;
    cTkFixedString<128,char> macMessageForVisitor;
    cTkFixedString<128,char> macMessageForConflict;
    cTkFixedString<128,char> macMessageForProposal;
    cTkFixedString<128,char> macDebugText;
}
