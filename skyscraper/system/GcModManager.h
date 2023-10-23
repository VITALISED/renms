#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkString.h>
#include <metadata/gamestate/gcmodsettingsinfo.meta.h>

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
