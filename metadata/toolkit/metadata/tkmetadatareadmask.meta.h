#pragma once
#include <metadata/metadata_common.h>
enum eMetadataReadMask
{
    EMetadataReadMask_Default = 1,
    EMetadataReadMask_SaveWhenMultiplayerClient = 2,
    EMetadataReadMask_SavePlayerPosition = 4,
    EMetadataReadMask_SavePlayerInventory = 8,
    EMetadataReadMask_SaveDifficultySettings = 16,
}

class cTkMetadataReadMask
{
    static unsigned long long muNameHash = 0x76BB9C78D7AE1C6B;
    static unsigned long long muTemplateHash = 0xE5E072016B296CBC;

    eMetadataReadMask MetadataReadMask;
}
