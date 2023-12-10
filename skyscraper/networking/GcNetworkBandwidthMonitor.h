/**
 * @file GcNetworkBandwidthMonitor.h
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

#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

class cGcNetworkBandwidthMonitor
{
  public:
    struct sMessageData
    {
        uint64_t mu64TotalBandwidth;
        unsigned int muCount;
        unsigned int muBwInLastSecond;
        unsigned int muPeakBwPerSec;
        unsigned int muCurrentAccumulator;
        unsigned int muMsgsInLastSecond;
        unsigned int muPeakMsgsPerSec;
        unsigned int muCurrentMsgAccumulator;
        bool mbDisplayRecordedData;
        unsigned int mauRecordings[180];
    };

    struct sBandwidthData
    {
        cGcNetworkBandwidthMonitor::sMessageData mTotal;
        std::array<cGcNetworkBandwidthMonitor::sMessageData, 41> mMessageCounts;
    };

    struct sPlayerData
    {
        unsigned int muUploadBytes;
        unsigned int muDownloadBytes;
        uint64_t muLastSendTime;
    };

    cGcNetworkBandwidthMonitor::sBandwidthData mUpload;
    cGcNetworkBandwidthMonitor::sBandwidthData mDownload;
    std::map<cTkFixedString<64, char>, cGcNetworkBandwidthMonitor::sMessageData> mComponentData;
    std::map<cTkFixedString<64, char>, cGcNetworkBandwidthMonitor::sMessageData> mReplicatedVariableData;
    std::map<cTkFixedString<64, char>, cGcNetworkBandwidthMonitor::sMessageData> mEntityData;
    std::map<cTkFixedString<32, char>, cGcNetworkBandwidthMonitor::sMessageData> mRpcData;
    std::map<cTkUserIdBase<cTkFixedString<64, char>>, cGcNetworkBandwidthMonitor::sPlayerData> mPlayerMap;
    uint64_t mCurrSecond;
};

SKYSCRAPER_END