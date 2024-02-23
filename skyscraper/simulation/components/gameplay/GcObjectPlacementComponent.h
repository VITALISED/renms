/**
 * @file GcObjectPlacementComponent.h
 * @author VITALISED & Contributors
 * @since 2024-01-22
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

#include <toolkit/simulation/components/TkComponent.h>

#include <gameplay/gcobjectplacementcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcObjectPlacementComponent : public cTkComponent
{
  public:
    enum ePlaceObjectState
    {
        EPlaceObjectState_None,
        EPlaceObjectState_Requested,
        EPlaceObjectState_Pending,
        EPlaceObjectState_Place,
        EPlaceObjectState_Complete,
    };

    cGcObjectPlacementComponent::ePlaceObjectState meObjectPlacementState;
    TkHandle mGroupNode;
    TkHandle mNode;
    int miNumObjectsAdded;
    int miNumGroupsAdded;
    cTkVector3 mPrevPosition;
    cTkVector<cTkMatrix34> maStartMatrices;
    cTkVector<float> mafOffsets;
    uint64_t mSeed;
    cGcObjectPlacementComponentData *mpData;
};

SKYSCRAPER_END