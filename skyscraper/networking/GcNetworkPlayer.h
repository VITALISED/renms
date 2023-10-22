#pragma once

#include <skyscraper.h>
#include <atlas/WinHttpTask.h>
#include <atlas/GcAtlasBrokerAuth.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <gamestate/EnvironmentLocation.h>
#include <networking/GcNetworkConstants.h>
#include <networking/GcNetworkMessage.h>
#include <networking/GcNetworkAddress.h>
#include <networking/GcNetworkPlayerReplicatedState.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayer : public cGcPlayerCommon
{
    typedef WinHttpTask::State::Enum ePlayerStatus;

    class IVoiceConnection
    {
        virtual unsigned int GetOutgoingVoiceData(unsigned __int8 *, unsigned int, bool *);
        virtual void SetIncomingVoiceData(unsigned __int8 *, unsigned int, const bool);
    };

    cTkFixedString<64,char> mName;
    cGcNetworkConstants::PlayerMovementState mePlayerMovementState;
    EnvironmentLocation::Enum meEnvironmentLocation;
    bool mbIsInPlayerFreighter;
    unsigned __int64 mCurrentUA;
    cGcNetworkConstants::LobbyType mePlayerType;
    cGcNetworkPlayerReplicatedState mReplicatedState;
    cGcNetworkPlayer::IVoiceConnection *mpVoiceConnection;
    std::shared_ptr<cGcNetworkAddress> mNetworkAddress;
    cTkFixedString<3,char> mPlatform;
    cGcNetworkPlayer::ePlayerStatus meStatus;
    cGcNetworkPlayer::ePlayerStatus mePendingStatus;
    float mfTimeSinceLastUpdateSent;
    cTkUserIdBase<cTkFixedString<64,char> > mPlayerId;
    cTkUserIdBase<cTkFixedString<64,char> > mAccountId;
    bool mbVoiceChatSuppressed;
    bool mbFriendOfLocal;
    cTkFixedString<64,char> mPlatformId;
    std::list<std::shared_ptr<cGcNetworkMessage>> mPendingMessages;
};

SKYSCRAPER_END