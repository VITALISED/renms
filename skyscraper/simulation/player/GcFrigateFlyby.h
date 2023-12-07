/**
 * @file GcFrigateFlyby.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <reality/gcfrigateclass.meta.h>
#include <simulation/gcfrigateflybytable.meta.h>
#include <simulation/gcfrigateflybytype.meta.h>
#include <simulation/player/gcplayercommunicatormessage.meta.h>
#include <toolkit/tktextureresource.meta.h>

SKYSCRAPER_BEGIN

class cGcFrigateFlyby
{
  public:
    cTkMatrix34 mSpawnMatrix;
    cGcPlayerCommunicatorMessage mCommunicatorMessage;
    TkID<256> mCommunitcatorOSDLocId;
    cTkTextureResource mMarkerIcon;
    cGcMarkerPoint mMarkerPoint;
    cTkVector<eFrigateClass> maFrigateClasses;
    eFrigateFlybyType meFlybyType;
    cTkClassPoolHandle mSquadHandle;
    cTkVector3 mPointOfInterest;
    cGcFrigateFlybyTable *mpFlybyTable;
    bool mbCommunicationAllowed;
    bool mbAnythingSpawned;
    bool mbAlignWithSun;
};

SKYSCRAPER_END