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
#include <gamestate/GcBlockList.h>
#include <metadata/source/user/gcusersettingsdata.meta.h>

SKYSCRAPER_BEGIN

class cGcUserSettings
{
public:
	enum eLoadState
	{
		Unloaded,
		EaryBootLoadComplete,
		FullLoadComplete,
	};

	enum Sensitivity
	{
		Flight,
		View,
		Cursor,
	};

	cGcUserSettingsData mSettingsData;
	cGcGyroSettingsData mGyroSettingsDataHandheldProxy;
	cGcBlockList mBlockList;
	cGcUserSettings::eLoadState meLoadState;
	bool mbPendingWrite;
	bool mbWriteThreadCreated;
	unsigned int mWriteThreadId;
	unsigned __int64 mu64LastContentHash1;
	unsigned __int64 mu64LastContentHash2;
	bool mbContentHashesValid;
	robin_hood::detail::Table<false, 80, cTkFixedString<128, char>, void, robin_hood::hash<cTkFixedString<128, char>, void>, std::equal_to<cTkFixedString<128, char> > > mUpgradedUsers;
};

SKYSCRAPER_END
