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

SKYSCRAPER_BEGIN

enum eNGuiInputType
{
    eInput_RightDragged = -8,
    eInput_RightPressed = -7,
    eInput_RightHeld = -6,
    eInput_Hover = -5,
    eInput_Dragged = -4,
    eInput_TouchPressReady = -3,
    eInput_Pressed = -2,
    eInput_Held = -1,
    eInput_None = 0,
    eInput_Released = 1,
    eInput_Click = 2,
    eInput_RightReleased = 3,
    eInput_RightClick = 4,
};

SKYSCRAPER_END