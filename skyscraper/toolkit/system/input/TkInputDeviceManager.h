/**
 * @file TkInputDeviceManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <toolkit/data/TkMetaDataClasses.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/system/input/TkInputUtils.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>

#include <toolkit/utilities/data/tkinputframearray.meta.h>

SKYSCRAPER_BEGIN

class cTkInputDeviceManager;

namespace TkInputDevicesGLFW
{

class cTkKeyboard : public ITkInputDevice
{
  public:
    cTkInputDeviceManager *mpInputManager;
};

class cTkMouse : public ITkInputDevice
{
  public:
    cTkInputDeviceManager *mpInputManager;
};

class cTkDS4Input : public ITkInputDevice
{
  public:
    cTkInputDeviceManager *mpInputManager;
    /*ScePadData*/ char mPadData[0x78];
    bool mbAvailable;
};

class cTkPadXInput : public ITkInputDevice
{
  public:
    cTkInputDeviceManager *mpInputManager;
    bool mbAvailable;
};

class cTkOculusTouch : public ITkInputDevice
{
  public:
    cTkInputDeviceManager *mpInputManager;
    bool mbAvailable;
};

} // namespace TkInputDevicesGLFW

class cTkInputDeviceManagerBase
{
  public:
    eInputPort mePrimaryPort;
    eInputPort maeSecondaryPorts[6];
    int miFrameSinceMouseLockCounter;
    int miFrameSinceMouseUnlockCounter;
    bool mbMouseLocked;
    bool mbMouseLookEnabled;
    bool mbWasActiveFocus;
    bool mbConsoleActive;
    bool mbTextInputActive;
    bool mbIconsLoaded;
    float mfSpringSmoothDeltaMin;
    float mfSpringSmoothDeltaMax;
    float mfSpringSmoothStrength;
    bool mbUseLeftHandForGyro;
    float mfJoystickOrientationTrimAltAngleDegreesOutward;
    cTkDynamicArray<sTkInputDeviceIconMap *> mDeviceIconMapByType;
    cTkUnorderedMap<TkID<128>, sTkInputDeviceIconMap *, TkIDUnorderedMap::Hash128> mDeviceIconMapByID;
    ITkDeviceInformationOverride *mpDeviceInformationOverride;

    virtual ~cTkInputDeviceManagerBase();
    virtual ITkInputDevice *FindDevice(eInputButtonType, ePadType, int);
    virtual void LockMouse();
    virtual void UnlockMouse();
    virtual void HideMouse();
    virtual void ShowMouse();
    virtual bool IsMouseHidden();
    virtual void SetMousePosition(float, float);
    virtual eInputButton LocaliseButton(eInputButton);
    virtual void ProvideDeviceMatrices(ITkDeviceMatrixSource *);
    virtual bool IsControllerPositionTracking();
    virtual bool IsGyroControlSupported();
    virtual bool GryoCanBeAttachedToScreen();
    virtual bool GyroIsAttachedToScreen();
    virtual bool IsUsingSplitController();
    virtual const char *GetDeviceSpecMetadataFile(eInputButtonType, ePadType);
};

class cTkInputDeviceManager : public cTkInputDeviceManagerBase
{
  public:
    struct PadConfiguration
    {
        std::array<int, 6> maiMapping;
        std::array<ePadType, 4> maeTypes;
        std::array<int, 4> maiHandle;
        std::array<bool, 4> mabStateJustChanged;
    };

    std::atomic<bool> mbDetectionRunning;
    std::atomic<bool> mbNewDetectionData;
    cTkInputDeviceManager::PadConfiguration mPads;
    cTkInputDeviceManager::PadConfiguration mPadDataDetection;
    cTkStackVector<unsigned int, 16> mCharacterInputQueue;
    unsigned int muBackSpaceCount;
    unsigned int muNextBackSpaceCount;
    std::string mLastUtf8StreamInput;
    long double mfMouseX;
    long double mfMousePrevX;
    long double mfMouseY;
    long double mfMousePrevY;
    float mafMouseDeltaX[7];
    float mafMouseDeltaY[7];
    int miCurrentDeltaFrame;
    cTkSmoothCD<cTkVector2> mSpringSmoother;
    float mfMouseDeltaX;
    float mfMouseDeltaY;
    bool mbShowMouse;
    bool mbSetMouse;
    int miControllerCheckCountdown;
    eRecordMode meRecordMode;
    cTkInputFrameArray *mpFrameArray;
    int miFrame;
    eInputButtonType meCurrentInputMethod;
    bool mbScePadLibOK;
    std::array<int, 4> miSceDS4Handles;
    std::array<cTkVector2, 4> mSceDS4TouchRes;
    TkInputDevicesGLFW::cTkKeyboard *mpDeviceKeyboard;
    TkInputDevicesGLFW::cTkMouse *mpDeviceMouse;
    TkInputDevicesGLFW::cTkDS4Input *mpDeviceDS4Input;
    TkInputDevicesGLFW::cTkPadXInput *mpDeviceXInputPad;
    TkInputDevicesGLFW::cTkOculusTouch *mpDeviceOculusTouch;
};

SKYSCRAPER_END