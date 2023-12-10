/**
 * @file TkInputUtils.h
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

#include <toolkit/utilities/UnorderedMapHashes.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/utilities/data/tkinputenum.meta.h>
#include <toolkit/utilities/input/tkcontrollerspecification.meta.h>
#include <toolkit/utilities/input/tktriggerfeedbackdata.meta.h>

SKYSCRAPER_BEGIN

class cTkInputManager;
class cTkInputPort;
class ITkInputDevice;

enum eInputButtonType
{
    EButton_None,
    EButtonKeyboard,
    EButtonMouse,
    EButtonPad,
    EButtonHands,
    EButtonGesture,
    EButtonType_Num,
    EButtonType_Any,
};

enum ePadType
{
    EPad_None,
    EPad_XInput,
    EPad_GLFW,
    EPad_XBoxOne,
    EPad_XBox360,
    EPad_DS4,
    EPad_DS5,
    EPad_Move,
    EPad_SteamInput,
    EPad_Touch,
    EPad_OpenVR,
    EPad_SwitchPro,
    EPad_SwitchHandheld,
    EPad_GameInput,
    EPad_SwitchDebugPad,
    EPad_SwitchJoyConDual,
    EPad_Num,
};

enum eInputPort
{
    EPort_None = -1,
    EPort_0,
    EPort_1,
    EPort_2,
    EPort_3,
    EPort_Debug,
    EPort_Console,
    ENumInputPorts,
    EPort_Invalid,
};

enum eInputPointerMode
{
    EInputPointer_Relative,
    EInputPointer_Absolute,
};

enum eInputDeviceTransform
{
    EDeviceTransform_None = -1,
    EDeviceTransform_Pad,
    EDeviceTransform_PrimaryHand,
    EDeviceTransform_SecondaryHand,
    EDeviceTransforms,
    EDeviceTransform_Invalid = 3,
};

enum eInputIconType
{
    EInputIcon_Solid,
    EInputIcon_Overlay,
    EInputIcon_Special,
    EInputIconType_Num,
    EInputIcon_Default = 0,
};

enum eRecordMode
{
    ERecordMode_None,
    ERecordMode_Record,
    ERecordMode_Playback,
};

enum eInputDimension
{
    EInputDimension_None = -1,
    EInputDimension_X    = 0,
    EInputDimension_Y    = 1,
    EInputDimension_Z    = 2,
    EInputDimension_0    = 0,
    EInputDimension_1    = 1,
    EInputDimension_2    = 2,
};

struct sTkInputDeviceIcon
{
    cTkSmartResHandle mhTexture;
    cTkVector2 mvSize;
};

struct sTkInputBinding
{
    int miActionId;
    eInputButton meDigitalBinding;
    eInputAxis meAnalogueBinding;
};

struct sTkInputBindingsActionSet
{
    int muActionSetId;
    cTkVector<sTkInputBinding> mBindings;
};

struct sTkInputBindings
{
    cTkVector<sTkInputBindingsActionSet *> mActionSetBindings;
};

struct sTkInputDeviceIcons
{
    sTkInputDeviceIcon mIcons[3];
};

struct sTkInputDeviceChordIcons
{
    eInputButton mButtons[8];
    sTkInputDeviceIcons mIcons;
    TkID<128> mTextTag;
};

struct sTkInputDeviceIconMap
{
    const cTkControllerSpecification *mpSpec;
    robin_hood::detail::Table<
        true, 80, eInputButton, sTkInputDeviceIcons, robin_hood::hash<eInputButton, void>, std::equal_to<eInputButton>>
        mButtonIcons;
    robin_hood::detail::Table<
        true, 80, eInputAxis, sTkInputDeviceIcons, robin_hood::hash<eInputAxis, void>, std::equal_to<eInputAxis>>
        mAxisIcons;
    robin_hood::detail::Table<
        true, 80, cTkFixedString<32, char>, std::pair<eInputButton, eInputAxis>,
        UnorderedMapHashes::Hash<cTkFixedString<32, char>>, std::equal_to<cTkFixedString<32, char>>>
        mOriginIcons;
    cTkVector<sTkInputDeviceChordIcons> mChordIcons;
    bool mbIconSizesResolved;
};

class ITkDeviceInformationOverride
{
  public:
    const char *GetDeviceSpecMetadataFile(eInputButtonType, ePadType);
};

struct sTkActionState
{
    int miDigitalFirstSet;
    int miDigitalLastSet;
    int miAnalogueLastSet;
    float mfAnalogueValue;
    bool mbAnalogueSource;
    int miActionSetContinuity;
};

struct cTkInputButtonOrAxis
{
    eInputButton meButton;
    eInputAxis meAxis;
};

class cTkAttachedDevice
{
  public:
    eInputButtonType meDeviceType;
    ePadType mePadType;
    int miDeviceId;
    int mhUserBindings;
    int mhBaseBindings;
    int mhBindings;
    sTkInputDeviceIconMap *mpIcons;
    sTkInputDeviceIconMap *mpDefaultIcons;
    cTkInputPort *mpPort;
    ITkInputDevice *mpDevice;
    cTkAttachedDevice *mpPiggyBack;
    bool mbIsPiggyBacked;
    bool mbEnabled;
    bool mbActive;
    bool mbDeviceActivity;
    cTkDynamicArray<std::array<int, 16>> maiActionsDigital;
    cTkDynamicArray<std::array<int, 16>> maiActionsAnalogue;
    cTkDynamicArray<cTkInputButtonOrAxis> maFirstActionBindings;
    cTkDynamicArray<cTkInputButtonOrAxis> maGhostActionBindings;
};

class cTkInputPort
{
    cTkInputManager *mpInputManager;
    eInputPort mePort;
    cTkDynamicArray<sTkActionState> mActionStates;
    int miNow;
    int miLastActionSetChange;
    int miLastGhostActionSetChange;
    int miActionSetContinuity;
    bool mbDeviceActivity;
    cTkVector<cTkAttachedDevice *> mDevices;
    cTkAttachedDevice *mpActiveDevice;
    bool mbActiveDeviceChanged;
    bool mbActiveDeviceRemoved;
    cTkAttachedDevice *mpUpdatingDevice;
    int miDefaultActionSetId;
    int miActiveActionSetId;
    int miPrevActiveActionSetId;
    int miGhostActionSetId;
    int miPrevGhostActionSetId;
    bool mbActionSetChanged;
    bool mbBindingsInvalid;
    bool mbLastInputWasTouch;
    bool mbResetTouchInput;
    int mhFallbackBinding;
    bool mbGyroActivity;
    cTkVector3 mGyroAngularVelocity;
    cTkVector3 mSteadiedGyroAngularVelocity;
    cTkVector3 mGyroAcceleration;
    cTkVector3 mGyroGravityVector;
    cTkVector3 mGyroSmoothAcceleration;
    float mfGyroShakiness;
    cTkBitArray<uint64_t, true, 512> mButtons;
    cTkBitArray<uint64_t, true, 512> mButtonsPrev;
    float mafAxis[51];
    float mafAxisPrev[51];
    int miMouseX;
    int miMouseY;
    int miMousePrevX;
    int miMousePrevY;
    eInputPointerMode meMouseMode;
    bool mbDeviceTransformsAvailable[3];
    cTkMatrix34 mDeviceTransforms[3];
};

class cTkOutputPort
{
  public:
    cTkInputManager *mpInputManager;
    eInputPort mePort;
    float mRumblePrimary;
    float mRumbleSecondary;
    cTkTriggerFeedbackData mTriggerFeedback[2];
};

class ITkInputDevice
{
  public:
    virtual ~ITkInputDevice();
    virtual bool IsAvailable();
    virtual bool ActivityCheck();
    virtual bool PullInput(cTkInputPort *);
    virtual void PushOutput(const cTkOutputPort *);
};

struct sTkInputAction
{
    int miActionId;
    bool mbAnalogue;
    int miPairedActionId;
    TkID<128> midTextTags[8];
    TkID<256> midName;
    sTkInputDeviceIcons mIcons;
    cTkFixedString<32, char> msExternalId;
    cTkFixedString<32, char> msExternalLoc;
    cTkFixedString<32, char> msExternalDigitalAliasId;
    unsigned int muFlags;
    cTkFixedString<64, char> msName;
    bool mbCompositeAction;
    eInputDimension meOrientation;
};

struct sTkInputActionSetAction
{
    int miActionId;
    bool mbActionSetVisible;
    bool mbActionSetDebug;
};

struct sTkInputActionSet
{
    int miActionSetId;
    cTkFixedString<32, char> msName;
    TkID<256> midName;
    cTkFixedString<32, char> msExternalId;
    cTkFixedString<32, char> msExternalLoc;
    bool mbActionSetVisible;
    bool mbActionSetDebug;
    cTkVector<sTkInputActionSetAction> mActions;
};

class ITkDeviceMatrixSource
{
  public:
    virtual bool GetDeviceMatrix(eInputDeviceTransform, int, cTkMatrix44 *);
};

SKYSCRAPER_END