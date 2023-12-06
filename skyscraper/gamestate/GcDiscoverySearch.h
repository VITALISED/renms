/**
 * @file GcDiscoverySearch.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <toolkit/core/types/TkID.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

#include <reality/gcdiscoverytype.meta.h>

SKYSCRAPER_BEGIN

namespace DiscoveryResolver
{

typedef int NameAndOwnerResult;

struct DiscoveryInfo
{
    struct DiscoveryInfoValue
    {
        TkID<256> mTitle;
        cTkFixedString<128, char> msValue;
        bool mbHighlight;
    };

    cTkFixedString<128, char> msTitle;
    DiscoveryResolver::NameAndOwnerResult mNameAndOwner;
    cTkVector<DiscoveryResolver::DiscoveryInfo::DiscoveryInfoValue> mValues;
    eDiscoveryType meDiscoveryType;
    int miWorth;
    cTkModelResourceRenderer *mpThumbnail;
    float mfDisplayTime;
    float mfDisplayTimer;
    float mfAnimateInTime;
    bool mbNewDiscovery;
    bool mbWeird;
};

} // namespace DiscoveryResolver

SKYSCRAPER_END