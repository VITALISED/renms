/**
 * @file GcGameAnalytics.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <atlas/transport/GcAtlasTransport.h>
#include <networking/GcNetworkPlayerEventsHandler.h>
#include <toolkit/data/TkDocumentWriterJSON.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/string/TkStringAssembler.h>

SKYSCRAPER_BEGIN

class cGcStatsManager;

class cGcGameAnalytics : public INetworkPlayerEventsHandler
{
  public:
    void AddCrossplayEvent(std::string lKey, int liValue, bool lbUseValue);
    void AddCustomEvent(const char *lpKey, int liValue, bool lbEncodeValueInEventId);
    void AddProgressionEvent(const char *lpMission, int liStage, bool lbIsComplete);
    void AddRequiredKeyValues(cTkDocumentWriterJSON *lpDocWriter, bool lbCrossplay);
    cTkFixedString<128, char> &BuildHeirachicalEventId(const char *lpString);
    void CheckJsonBuffer();
    void Construct();
    void EndSession(bool lbCrossplay);
    void HttpHandleInitRequestResult(const Http::RequestResult &lResult);
    void HttpHandleSessionStartRequestResult(const Http::RequestResult &lResult);
    void OnMultiplayerSessionFinished(cGcNetworkConstants::LobbyType leLobbyType);
    void OnMultiplayerSessionStarting(cGcNetworkConstants::LobbyType leLobbyType);
    void OnNetworkPlayerStateEvent(cGcNetworkPlayer *lpPlayer, eGcNetworkPlayerStateEvent leEvent);
    bool StartEvents();
    void StartSession(bool lbCrossplay);
    void Update(float lfTimeStep);
    void UpdateFireteamSession();
    void UploadEventsJSON();

    enum ConnectionState
    {
        E_OK,
        E_Init_Failed,
        E_Invalid_User,
        E_Session_Failed,
    };

    struct Pending
    {
        cTkFixedString<128, char> mKey;
        int mValue;
        bool mIsProgression;
        bool mStageIsComplete;
        bool mIsLevelledStat;
    };

    struct ValidPlayer
    {
        cGcNetworkPlayer *mpPlayer;
        uint8_t meState[4];
        std::string mDevice;
    };

    cGcStatsManager *mpStatsManager;
    cGcAtlasTransport *mpTransport;
    cTkStringAssembler *mpStringAssembler;
    cTkDocumentWriterJSON *mpDocWriter;
    cTkUserIdBase<uint64_t> mLocalUserId;
    cTkFixedString<128, char> mSessionId;
    int mSessionNum;
    int mTimestampOffset;
    bool mbRequestUploadAll;
    bool mbPendingUploadAll;
    cTkFixedString<32, char> mBuildId;
    cTkFixedString<32, char> mTelemetryVersion;
    int mSessionStartTime;
    cTkFixedString<128, char> mFireteamSessionId;
    int mFireteamSessionStartTime;
    int mFireteamSessionNum;
    std::vector<cGcGameAnalytics::Pending> maPending;
    bool mbActualDataToUpload;
    bool mbEnableGameAnalyticsUpload;
    cGcGameAnalytics::ConnectionState meConnectionState;
    cTkStringAssembler *mpCrossplayStringAssembler;
    cTkDocumentWriterJSON *mpCrossplayDocWriter;
    bool mbInFireteamSession;
    int64_t miMatchmakingVersion;
    cTkVector<cGcGameAnalytics::ValidPlayer> mValidPlayers;
    std::map<std::string, int> mCrossplayDeviceSessionTimes;
};

SKYSCRAPER_END