#pragma once
#include <metadata/metadata_common.h>
enum eInputAxis
{
    EInputAxis_None = 0,
    EInputAxis_Invalid = 0,
    EInputAxis_LeftStick = 1,
    EInputAxis_LeftStickX = 2,
    EInputAxis_LeftStickY = 3,
    EInputAxis_RightStick = 4,
    EInputAxis_RightStickX = 5,
    EInputAxis_RightStickY = 6,
    EInputAxis_LeftTrigger = 7,
    EInputAxis_RightTrigger = 8,
    EInputAxis_Mouse = 9,
    EInputAxis_MouseX = 10,
    EInputAxis_MouseY = 11,
    EInputAxis_MousePositiveX = 12,
    EInputAxis_MouseNegativeX = 13,
    EInputAxis_MousePositiveY = 14,
    EInputAxis_MouseNegativeY = 15,
    EInputAxis_MouseWheel = 16,
    EInputAxis_MouseWheelPositive = 17,
    EInputAxis_MouseWheelNegative = 18,
    EInputAxis_Touchpad = 19,
    EInputAxis_TouchpadX = 20,
    EInputAxis_TouchpadY = 21,
    EInputAxis_TouchpadPositiveX = 22,
    EInputAxis_TouchpadNegativeX = 23,
    EInputAxis_TouchpadPositiveY = 24,
    EInputAxis_TouchpadNegativeY = 25,
    EInputAxis_LeftTouchpad = 26,
    EInputAxis_LeftTouchpadX = 27,
    EInputAxis_LeftTouchpadY = 28,
    EInputAxis_LeftTouchpadPositiveX = 29,
    EInputAxis_LeftTouchpadNegativeX = 30,
    EInputAxis_LeftTouchpadPositiveY = 31,
    EInputAxis_LeftTouchpadNegativeY = 32,
    EInputAxis_LeftGrip = 33,
    EInputAxis_RightGrip = 34,
    EInputAxis_LeftStickPositiveX = 35,
    EInputAxis_LeftStickNegativeX = 36,
    EInputAxis_LeftStickPositiveY = 37,
    EInputAxis_LeftStickNegativeY = 38,
    EInputAxis_RightStickPositiveX = 39,
    EInputAxis_RightStickNegativeX = 40,
    EInputAxis_RightStickPositiveY = 41,
    EInputAxis_RightStickNegativeY = 42,
    EInputAxis_DirectionalPadX = 43,
    EInputAxis_DirectionalPadY = 44,
    EInputAxis_DirectionalButtonsX = 45,
    EInputAxis_DirectionalButtonsY = 46,
    EInputAxis_ChordAD = 47,
    EInputAxis_FakeLeftStick = 48,
    EInputAxis_FakeRightStick = 49,
}

class cTkInputAxisEnum
{
    static unsigned long long muNameHash = 0x6DC70ADC2461C621;
    static unsigned long long muTemplateHash = 0xE2086B32C63C0768;

    eInputAxis InputAxis;
}
