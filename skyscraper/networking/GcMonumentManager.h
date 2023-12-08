/**
 * @file GcMonumentManager.h
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

#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <atlas/gcatlasmonument.meta.h>

SKYSCRAPER_BEGIN

class cGcAsyncOpsTempMonument
{
  public:
    std::atomic<unsigned char> meDisplayNameState;
    cGcAtlasMonument mMonument;
};

class cGcMonumentManager
{
  public:
    cTkVector<uint64_t> mRequestsInFlight;
    cTkSmartResHandle mMonumentResource;
    TkHandle mNodeHandle;
    cGcAtlasMonument mMonumentData;
    /*cGcInteractionComponent*/ uintptr_t *mpInteraction;
    cGcMarkerPoint mMarkerPoint;
    cTkVector<std::shared_ptr<cGcAsyncOpsTempMonument>> mAsyncOpsTempMonuments;
};

SKYSCRAPER_END