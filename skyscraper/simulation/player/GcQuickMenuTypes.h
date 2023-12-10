/**
 * @file GcQuickMenuTypes.h
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
#include <toolkit/graphics/TkColour.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/string/TkString.h>

#include <gamestate/gcinventoryelement.meta.h>
#include <simulation/weapons/gcplayerweapons.meta.h>
#include <ui/hud/quickmenu/gcquickmenuactions.meta.h>

SKYSCRAPER_BEGIN

enum eQuickMenuState
{
    EQuickMenuState_Closed,
    EQuickMenuState_QuickActions,
    EQuickMenuState_Build,
    EQuickMenuState_TerrainEditor,
    EQuickMenuState_GalaxyPath,
};

enum eQuickMenuSlot
{
    EQuickMenuSlot_None = -1,
    EQuickMenuSlot_Left4,
    EQuickMenuSlot_Left3,
    EQuickMenuSlot_Left2,
    EQuickMenuSlot_Left1,
    EQuickMenuSlot_Main,
    EQuickMenuSlot_Right1,
    EQuickMenuSlot_Right2,
    EQuickMenuSlot_Right3,
    EQuickMenuSlot_Right4,
    EQuickMenuSlot_TopLeft3,
    EQuickMenuSlot_TopLeft2,
    EQuickMenuSlot_TopLeft1,
    EQuickMenuSlot_TopMain,
    EQuickMenuSlot_TopRight1,
    EQuickMenuSlot_TopRight2,
    EQuickMenuSlot_TopRight3,
    EQuickMenuSlot_TotalNumSlots  = 16,
    EQuickMenuSlot_MainSlotsStart = 0,
    EQuickMenuSlot_MainSlotsEnd   = 8,
    EQuickMenuSlot_TopSlotsStart  = 9,
    EQuickMenuSlot_TopSlotsEnd    = 15,
};

struct MenuAction
{
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mActionIcon;
    eQuickMenuActions meAction;
    bool mbUseInventryElement;
    cGcInventoryElement mInventoryElement;
    uint8_t mActionInventory[4];
    cGcInventoryIndex mActionInventoryIndex;
    bool mbDisabled;
    bool mbShowBackground;
    eWeaponMode meWeaponMode;
    bool mbGlow;
    bool mbAllowPrimaryWhenDisabled;
    bool mbDisableWhenNotSelected;
    cTkColour mPrimaryColour;
    cTkColour mSecondaryColour;
    bool mbAnimateIn;
    int miSavedActionIndex;
    TkID<128> mActionID;
    cTkFixedString<64, char> mName;
    int miBoundHotAction;
};

struct AnimateItems
{
    bool mbRequested;
    float mfFrom;
    float mfTo;
    float mfAnimTime;
    float mfTimer;
    float mfWait;
};

struct QuickMenuRenderState
{
    cTkFixedString<256, char> msControlsString;
    cTkFixedString<256, char> msExtraControlsString;
    bool mbShowMenu;
    bool mbShowCategories;
    TkID<256> maCategories[3];
    float mfCursorX;
    float mfCursorY;
    cTkFixedString<512, char> mLabelID;
    cTkColour mLabelTextColour;
    cTkColour mLabelBGColour;
    cTkFixedString<128, char> mItemName;
    bool mbShowChargeArrows;
    bool mbForceShowUpArrow;
    bool mbShowBackButton;
    cTkVector<MenuAction> mNextActions;
    MenuAction mPreviousAction;
    std::vector<MenuAction> mCurrentActions;
    bool mbItemChanged;
    AnimateItems mAnimateItems;
    AnimateItems mAnimateNextItems;
    AnimateItems mEnterMenuAnimation;
    AnimateItems mUpArrowAnimation;
    AnimateItems mLeftArrowAnimation;
    AnimateItems mRightArrowAnimation;
    int miCurrentAction;
    int miNextAction;
    bool mbWrapCurrentActions;
    int miCurrentActionDepth;
    cTkBitArray<unsigned int, 1, 32> mxValidSlots;
    bool mbCurrentActionIsSubMenu;
    std::atomic<bool> mbLocked;
};

class cGcAnalogueMenuNavigator
{
  public:
    bool mbWasActive;
    uint8_t meOutput[4];
    uint8_t mePrevOutput[4];
    cTkPhysRelMat34 mMoveOrigin;
    cTkVector3 mLocalIntersect;
    cTkVector3 mLocalDir;
    cTkVector2 mCursorPos;
    bool mbScrolling;
    bool mbValid;
};

class cGcQuickMenuState
{
  public:
    const int kiMaxTips;
    cGcAnalogueMenuNavigator mAnalogueMenuNav;
    cTkFixedString<512, char> mErrorID;
    cTkColour mErrorColour;
    cTkColour mErrorHighlightColour;
    float mfErrorTimer;

    void Update(const float, QuickMenuRenderState *);
    void UpdateRender();
    void Render();
    void Activate();
    bool Close(bool);
    bool ShouldRenderCursor();
    bool ShouldTriggerAction();
    bool TriggerCurrentAction();
    bool TriggerClose();
    void UpdateControlsString(cTkFixedString<256, char> *, cTkFixedString<256, char> *);
    bool ShouldClose();
    bool CanPlayerMove();
    bool HasParentMenu();
    bool AllowedToOpenFrontendPages();
    bool IsSlotHighlighted(eQuickMenuSlot);
    bool IsSlotSelected(eQuickMenuSlot);
};

SKYSCRAPER_END