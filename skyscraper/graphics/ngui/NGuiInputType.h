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