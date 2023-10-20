#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayeremotepropdata.meta.h>
#include <metadata/tktextureresource.meta.h>

class cGcPlayerEmote
{
    static unsigned long long muNameHash = 0xBD1382185246DF07;
    static unsigned long long muTemplateHash = 0xC0C272905A6A0283;

    TkID<256> mTitle;
    TkID<256> mChatText;
    bool mbChatUsesPrefix;
    TkID<128> mEmoteID;
    TkID<128> mAnimationName;
    cGcPlayerEmotePropData PropData;
    cTkTextureResource Icon;
    TkID<128> mLinkedSpecialID;
    bool mbNeverShowInMenu;
    TkID<128> mLoopAnimUntilMove;
    bool mbCloseMenuOnSelect;
    bool mbMoveToCancel;
    TkID<128> mGekAnimationName;
    TkID<128> mGekLoopAnimUntilMove;
    bool mbAvailableUnderwater;
    TkID<128> mRidingAnimationName;
    bool mbIsPetCommand;
    TkID<256> mPetCommandTitle;
    cTkTextureResource PetCommandIcon;
}
