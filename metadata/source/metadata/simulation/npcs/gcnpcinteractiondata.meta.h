#pragma once
#include <metadata/metadata_common.h>
#include <metadata/attachments/tkattachmentdata.meta.h>

class cGcNPCInteractionData
{
    static unsigned long long muNameHash = 0xBB7B4EAD531E3D6;
    static unsigned long long muTemplateHash = 0x7A6AB24B3910461E;

    TkID<128> mID;
    cTkAttachmentData Data;
}
