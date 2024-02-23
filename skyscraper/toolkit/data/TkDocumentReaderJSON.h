/**
 * @file TkDocumentReaderJSON.h
 * @author VITALISED & Contributors
 * @since 2024-01-23
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <toolkit/data/TkDocumentReader.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

class cTkDocumentReaderJSON : public ITkDocumentReader
{
  public:
    nms_rapidjson::GenericDocument<nms_rapidjson::UTF8<char>> mJsonDocument;
    nms_rapidjson::GenericValue<nms_rapidjson::UTF8<char>> *mCursor;
    std::array<nms_rapidjson::GenericValue<nms_rapidjson::UTF8<char>> *, 32> mCursorStack;
    cTkStackVector<const char *, 32> mContextTrail;
    int miCursorStackIndex;
    bool mbAllowSkipIdsCaret;
    uint64_t mJsonFile;
    char *mpStreamBuffer;
};

SKYSCRAPER_END