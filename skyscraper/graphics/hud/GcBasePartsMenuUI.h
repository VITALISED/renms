/**
 * @file GcBasePartsMenuUI.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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
#include <toolkit/core/types/TkTypes.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcBasePartsMenuUI
{
  public:
    struct sPartsTab
    {
        cTkVector<TkID<128>> maExpandedPartIDs;
        cTkVector<TkID<128>> maExpandedSubPartIDs;
        TkID<128> mGroupID;
        TkID<256> mTabName;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mIconRes;
        float mfScrollPosition;
        TkID<128> maPartIds[240];
        int maPartSubGroup[240];
        int maPartExpanded[240];
        int miNumParts;
        bool mbContainsUnseenItems;
    };

    struct sLocationRestoration
    {
        cTkVector2 mCursorPos;
        TkID<128> mPartId;
        float mfCursorPosSetTime;
    };

    struct sBreadcrumb
    {
        TkID<128> mGroupId;
        TkID<128> mItemId;
    };

    cGcBasePartsMenuUI::sPartsTab maPartsTabs[20];
    int miCurrentTab;
    int miDesiredTab;
    TkID<128> mCurrentSubgroupId;
    TkID<128> mDesiredSubgroupId;
    cGcBasePartsMenuUI::sLocationRestoration mLocationRestoration;
    cGcBasePartsMenuUI::sBreadcrumb mBreadcrumb;
    float mfHoverStartTime;
    TkID<128> mHoveredPartId;
    TkID<128> mStartPlacingPartId;
    TkID<128> mRequestExpansionToggleId;
    bool mbHaveSeenNewParts;
    bool mbWantToSetCursorPos;
    bool mbShowingPopup;
};

SKYSCRAPER_END