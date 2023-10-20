#pragma once
#include <metadata/metadata_common.h>
#include <metadata/user/gcblockeduser.meta.h>
#include <metadata/user/gcblockedmessage.meta.h>

class cGcBlockListPersistence
{
    static unsigned long long muNameHash = 0xFD630C0F790F1BCB;
    static unsigned long long muTemplateHash = 0x6018730138103927;

    cTkFixedArray<cGcBlockedUser> maBlockedUserArray;
    int miNextSlot;
    int miListSize;
    cTkFixedArray<cGcBlockedMessage> maBlockedMessageArray;
    int miMessageNextSlot;
    int miMessageListSize;
}
