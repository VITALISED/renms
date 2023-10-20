#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/wiki/gcwikipage.meta.h>
#include <metadata/input/gcactionsettype.meta.h>

class cGcWikiTopic
{
    static unsigned long long muNameHash = 0x55D566D2C6EFD1C1;
    static unsigned long long muTemplateHash = 0x457A094003702400;

    TkID<256> mTopicID;
    TkID<256> mShortDescriptionID;
    cTkTextureResource Icon;
    cTkTextureResource NotifyIcon;
    cTkDynamicArray<cGcWikiPage> maPages;
    TkID<128> mMission;
    TkID<256> mMissionButtonText;
    bool mbSeen;
    bool mbUnlocked;
    cGcActionSetType ActionSet;
}
