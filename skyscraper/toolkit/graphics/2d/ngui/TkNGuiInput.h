/**
 * @file TkNGuiInput.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <toolkit/graphics/2d/ngui/TkNGuiDraggable.h>
#include <toolkit/graphics/2d/ngui/TkNGuiElementID.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

enum eNGuiInputButtonState
{
    eButton_None,
    eButton_Released,
    eButton_Pressed,
    eButton_Held,
};

enum eNGuiInputType
{
    eInput_RightDragged    = -8,
    eInput_RightPressed    = -7,
    eInput_RightHeld       = -6,
    eInput_Hover           = -5,
    eInput_Dragged         = -4,
    eInput_TouchPressReady = -3,
    eInput_Pressed         = -2,
    eInput_Held            = -1,
    eInput_None            = 0,
    eInput_Released        = 1,
    eInput_Click           = 2,
    eInput_RightReleased   = 3,
    eInput_RightClick      = 4,
};

struct ScrollBarState
{
    int32_t miNumEntries;
    int32_t miCurrentStartIndex;
    int32_t miEntriesPerPage;
    cTkVector2 mfLastSeenPos;
    cTkVector2 mfLastSeenSize;
};

class cTkNGuiInput
{
  public:
    bool mbControlHeld;
    bool mbShiftHeld;
    bool mbAltHeld;
    float mfRightStickX;
    float mfRightStickY;
    float mfCursorX;
    float mfCursorY;
    float mfCursorDeltaX;
    float mfCursorDeltaY;
    float mfCursorSpeedModifierX;
    float mfCursorSpeedModifierY;
    float mfMousePosX;
    float mfMousePosY;
    float mfMouseScroll;
    eNGuiInputButtonState meMouseButtonState;
    eNGuiInputButtonState meMouse2ButtonState;
    eNGuiInputButtonState meRightThumbState;
    eNGuiInputButtonState meTransferButtonState;
    eNGuiInputButtonState meUploadButtonState;
    eNGuiInputButtonState meDiscoveryUploadButtonState;
    bool mbCursorIsMouse;
    bool mbPadOnly;
    cTkVector<std::pair<cTkNGuiElementID, eNGuiInputType>> maElementsPressed;
    cTkVector<std::pair<cTkNGuiElementID, eNGuiInputType>> maElementsPressed2;
    int32_t KeyMap[19];
    bool KeyCtrl;
    bool KeyShift;
    bool KeyAlt;
    bool maKeysDown[512];
    int8_t maInputCharacters[17];
    bool mbPadActive;
    ITkNGuiDraggable *mpDragObject;
};

SKYSCRAPER_END