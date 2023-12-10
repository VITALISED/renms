/**
 * @file GcSeasonalData.h
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

#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcplayerstatedata.meta.h>

SKYSCRAPER_BEGIN

class cGcSeasonalData
{
  public:
    cGcSeasonalGameModeData mData;
    cGcSeasonalGameModeData mLatestSeasonServerData;
    int miCachedServerSeasonId;
    uint64_t mu64CachedServerSeasonStartTime;
    uint64_t mu64CachedServerSeasonEndTime;
    uint64_t mu64CachedServerSeasonDataHash;
    int miCachedServerNextSeasonId;
    uint64_t mu64CachedServerNextSeasonStartTime;
    cTkVector<std::pair<void(__cdecl *)(void *), void *>> mDataDownloadedCallbacks;
    bool mbWaitingForDataToDownload;
    bool mbDataDownloadFailed;
    bool mbDataAvailable;
    bool mbDataLocked;
    bool mbServerDataAvailable;
};

SKYSCRAPER_END