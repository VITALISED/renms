#pragma once
#include <metadata/metadata_common.h>
enum eHand
{
    EHand_Right = 0,
    EHand_Left = 1,
}

class cGcHand
{
    static unsigned long long muNameHash = 0xDF2E636EA66DCE65;
    static unsigned long long muTemplateHash = 0x6932E051A4A23022;

    eHand Hand;
}
