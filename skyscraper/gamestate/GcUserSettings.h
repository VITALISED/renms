#pragma once

#include <skyscraper.h>
#include <gamestate/GcBlockList.h>
#include <metadata/user/gcusersettingsdata.meta.h>

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
