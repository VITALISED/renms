#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcpersistentbaseentry.meta.h>
#include <metadata/reality/gcdiscoveryowner.meta.h>
#include <metadata/gamestate/basebuilding/gcpersistentbasetypes.meta.h>
#include <metadata/gamestate/gcgamemode.meta.h>
#include <metadata/user/gcpersistentbasedifficultydata.meta.h>
#include <metadata/gamestate/basebuilding/gcbaseautopowersetting.meta.h>

class cGcPersistentBase
{
    static unsigned long long muNameHash = 0x732552199A3AE45E;
    static unsigned long long muTemplateHash = 0x856B1B2F38F87437;

    int miBaseVersion;
    int miOriginalBaseVersion;
    unsigned long long mui64GalacticAddress;
    cTkVector3 mPosition;
    cTkVector3 mForward;
    unsigned long long mui64UserData;
    unsigned long long mui64LastUpdateTimestamp;
    cTkDynamicArray<cGcPersistentBaseEntry> maObjects;
    cTkFixedString<64,char> macRID;
    cGcDiscoveryOwner Owner;
    cTkFixedString<64,char> macName;
    cGcPersistentBaseTypes BaseType;
    cTkFixedString<64,char> macLastEditedById;
    cTkFixedString<64,char> macLastEditedByUsername;
    cTkVector3 mScreenshotAt;
    cTkVector3 mScreenshotPos;
    cGcGameMode GameMode;
    cGcPersistentBaseDifficultyData Difficulty;
    cTkFixedString<32,char> macPlatformToken;
    bool mbIsReported;
    bool mbIsFeatured;
    cGcBaseAutoPowerSetting AutoPowerSetting;
}
