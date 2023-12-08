/**
 * @file GcNetworkTerrainEditMessage.h
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

#include <networking/messages/GcNetworkMessage.h>

#include <gamestate/gcuniverseaddressdata.meta.h>

SKYSCRAPER_BEGIN

class cGcNetworkTerrainEditMessage : public cGcNetworkMessage
{
  public:
    enum eDataType
    {
        EDataType_NormalEdits,
        EDataType_UndoneEdits,
        EDataType_EditsUndo,
        EDataType_NumTypes,
    };
    cGcUniverseAddressData mUniverseAddress;
    cTkVector3 mAnchorPosition;
    cGcNetworkTerrainEditMessage::eDataType meDataType;
    int miEditsCount;
    cTkFixedArray<int, 220> maiEditPositions;
    cTkFixedArray<char, 220> maEditData;
};

SKYSCRAPER_END