/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkString.h>
#include <metadata/source/gamestate/gcmodsettingsinfo.meta.h>

SKYSCRAPER_BEGIN

// this class is pretty cool actually
class cGcModManager
{
public:
    enum eModState
    {
        EModState_Installed,
        EModState_NotCached,
        EModState_Downloading,
        EModState_NeedsUpdate,
        EModState_MissingDependencies,
        EModState_Unavailable,
    };

    struct ModInfo
    {
        cGcModSettingsInfo mSavedData;
        cTkFixedString<1024,char> mThumbailPath;
        cTkFixedString<256,char> mMountPath;
        int miOverlayID;
        cGcModManager::eModState meState;
        bool mbActive;
        bool mbHasGlobals;
        bool mbHasBaseParts;
        bool mbHasLoc;
        bool mbNeedsMounting;
        bool mbWorkshopMod;
        bool mbSubscribedInWorkshop;
        bool mbUsesCustomSaveDir;
    };
};

SKYSCRAPER_END
