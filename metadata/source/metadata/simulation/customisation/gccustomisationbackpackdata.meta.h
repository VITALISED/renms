#pragma once
#include <metadata/metadata_common.h>

class cGcCustomisationBackpackData
{
    static unsigned long long muNameHash = 0xF9391B96F83DAF40;
    static unsigned long long muTemplateHash = 0xB44E6EA2FA256B5F;

    cTkFixedString<32,char> macNodeName;
    cTkVector3 mActiveJetOffset;
}
