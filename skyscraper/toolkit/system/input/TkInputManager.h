/**
 * @file TkInputManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <toolkit/system/input/TkInputDeviceManager.h>

#include <toolkit/utilities/input/tkinputvalidation.meta.h>

SKYSCRAPER_BEGIN

class cTkInputManager
{
  public:
    cTkInputDeviceManager mDeviceManager;
    bool mbInitialised;
    cTkVector<sTkInputAction> mActions;
    cTkVector<sTkInputActionSet> mActionSets;
    cTkVector<sTkInputBindings *> mBindings;
    sTkInputActionSet *mpSetBeingAdded;
    sTkInputBindings *mpBindingsBeingAdded;
    sTkInputBindingsActionSet *mpBindingsActionSetBeingAdded;
    sTkInputActionSet *mpBindingsActionSetFilter;
    bool mbIconSizesResolved;
    std::array<cTkInputPort, 6> maPortArray;
    std::array<cTkOutputPort, 6> maOutputPortArray;
    cTkDynamicArray<sTkInputAction *> mapActionLookup;
    cTkDynamicArray<sTkInputActionSet *> mapActionSetLookup;
    int miNumActions;
    int miNumActionSets;
    ePadType mePrimaryPadType;
    bool mbLastWasFocused;
    bool mbLastLockState;
    std::function<bool(int, float &)> mInterceptAnalogInputCallback;
    std::function<bool(int, eInputValidation, bool &)> mInterceptButtonInputCallback;
    bool mbSkipUpdateClickToPlay;

    virtual ~cTkInputManager();
    virtual void Construct();
    virtual bool Prepare();
    virtual void Update(float);
    virtual bool GetButtonInput(int, eInputValidation, eInputPort);
    virtual float GetAnalogInput(int, eInputPort);
    virtual bool GetLastButtonInputWasTouch(eInputPort);
    virtual void SetTouchInputWaitingForReset(bool, eInputPort);
    virtual bool HasDigitalActionBound(int, int, eInputPort);
    virtual bool HasAnalogActionBound(int, int, eInputPort);
    virtual const TkID<128> *GetDeviceVRViewResetLayerName();
    virtual eInputButton GetActionButton(int);
    virtual eInputAxis GetActionAxis(int);
    virtual const sTkInputDeviceIcon *GetMappedIcon(int, eInputIconType);
    virtual const cTkVector<sTkInputDeviceChordIcons> *GetChordIcons();
    virtual void SetActiveActionSet(int);
    virtual bool ShowRemapScreen();
};
SKYSCRAPER_END