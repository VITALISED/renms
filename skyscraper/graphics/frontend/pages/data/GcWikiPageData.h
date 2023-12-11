/**
 * @file GcWikiPageData.h
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

#include <gamestate/GcWonderCommon.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>

SKYSCRAPER_BEGIN

enum eWikiPageType
{
    EWikiPageType_Wiki,
    EWikiPageType_Catalogue,
    EWikiPageType_MaterialsAndItemsCatalogue,
    EWikiPageType_CraftingAndTechnologyCatalogue,
    EWikiPageType_BuildablesCatalogue,
    EWikiPageType_Stories,
    EWikiPageType_RecipesCatalogue,
    EWikiPageType_Wonders,
    EWikiPageType_NumTypes,
};

class cGcCustomWonderTextEntryHandler
{
  public:
    enum eState
    {
        Inactive,
        NamingNewWonder,
        Renaming,
        RenamingWithOverwrite,
    };

    cGcCustomWonderTextEntryHandler::eState meState;
    cGcWonderHandle mWonder;
};

class cGcWikiPageData
{
  public:
    int miCurrentCategoryIdx;
    int miCurrentTopic;
    int miCurrentTopicPage;
    int miCurrentPage;
    float mfTimeSinceLastTransition;
    TextScrollBarState mTextScrollBarState;
    cGcCustomWonderTextEntryHandler mCustomWonderTextEntryHandler;
};

SKYSCRAPER_END