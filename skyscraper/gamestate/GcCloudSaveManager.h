/**
 * @file GcCloudSaveManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

class cGcGameState;

struct TkCloudDataInfo
{
    uint64_t mUploadTimestamp;
    cTkFixedString<512, char> mMetaDataJson;
};

class cGcCloudSaveManager
{
  public:
    cGcGameState *mpGameState;
    std::function<void(bool)> mpOnCompletionCallback;
    uint64_t mTempJsonFile;
    uint64_t mTempLZ4File;
    nms_rapidjson::GenericDocument<
        nms_rapidjson::UTF8<char>, nms_rapidjson::MemoryPoolAllocator<nms_rapidjson::CrtAllocator>,
        nms_rapidjson::CrtAllocator>
        mJsonDocument;
    char *mpStreamBuffer;
    TkCloudDataInfo mCloudDataInfo;
    bool mbCancelTransferRequested;
};

SKYSCRAPER_END