/**
 * @file GcStoriesPageData.h
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

#include <toolkit/data/TkMetaDataClasses.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcStoriesPageData
{
  public:
    struct sGcUnlockedStoryInfo
    {
        cTkDynamicArray<int> maiUnlockedBranch;
        int miUnlockedIdx;
        bool mbIdxIsBitmask;
        bool mbSeenLastEntry;
    };

    int miCurrentCategory;
    int miCurrentTopicPage;
    int miCurrentStoryPage;
    int miCurrentStoryPageSection;
    cTkVector<cTkFixedString<8192, char>> maCurentPageSecionsText;
    float mfTimeSinceLastTransition;
    cTkFixedArray<cTkDynamicArray<cGcStoriesPageData::sGcUnlockedStoryInfo>, 8> maiUnlockedStoryIndex;
    cTkFixedArray<int, 8> maiCategoryUnseenCount;
    TextScrollBarState mTextScrollBarState;
};

SKYSCRAPER_END