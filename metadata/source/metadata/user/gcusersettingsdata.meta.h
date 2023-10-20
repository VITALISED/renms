#pragma once
#include <metadata/metadata_common.h>
#include <metadata/user/gcblocklistpersistence.meta.h>
enum ePS4FixedFPS
{
    EPS4FixedFPS_Invalid = 0,
    EPS4FixedFPS_False = 1,
    EPS4FixedFPS_True = 2,
}
enum eBaseSharingMode
{
    EBaseSharingMode_Undecided = 0,
    EBaseSharingMode_On = 1,
    EBaseSharingMode_Off = 2,
}
enum eTemperatureUnit
{
    ETemperatureUnit_Invalid = 0,
    ETemperatureUnit_C = 1,
    ETemperatureUnit_F = 2,
    ETemperatureUnit_K = 3,
}
#include <metadata/simulation/player/gcmovementdirection.meta.h>
enum eSpaceCombatFollowMode
{
    ESpaceCombatFollowMode_Disabled = 0,
    ESpaceCombatFollowMode_Hold = 1,
    ESpaceCombatFollowMode_Toggle = 2,
}
enum exEyeTrackingFlags
{
    FEyeTrackingFlags_ = 0,
    FEyeTrackingFlags_BaseBuilding = 1,
    FEyeTrackingFlags_WristMenus = 2,
    FEyeTrackingFlags_LookVector = 4,
    FEyeTrackingFlags_BinocScanner = 8,
}
#include <metadata/user/gcgyrosettingsdata.meta.h>
#include <metadata/tklanguages.meta.h>
#include <metadata/simulation/player/gchand.meta.h>
#include <metadata/ui/hud/gcinworlduiscreendata.meta.h>

class cGcUserSettingsData
{
    static unsigned long long muNameHash = 0x3A50D683FD1CF4BF;
    static unsigned long long muTemplateHash = 0xB1245EFE662ED9AE;

    bool mbInvertLookControls;
    bool mbInvertFlightControls;
    bool mbInvertVRInWorldFlightControls;
    bool mbVRVehiclesUseWorldControls;
    bool mbHUDHidden;
    bool mbVibration;
    int miScreenBrightness;
    int miMusicVolume;
    int miSfxVolume;
    int miLookSensitivityMode1;
    int miLookSensitivityMode2;
    int miFlightSensitivityMode1;
    int miFlightSensitivityMode2;
    int miCursorSensitivityMode1;
    int miCursorSensitivityMode2;
    int miMouseSpringSmoothing;
    cGcBlockListPersistence BlockList;
    int miMotionBlurAmount;
    int miFilter;
    bool mbDamageNumbers;
    ePS4FixedFPS PS4FixedFPS;
    float mfPS4FOVFoot;
    float mfPS4FOVShip;
    bool mbXboxOneXHighResolutionMode;
    bool mbPS4VignetteAndScanlines;
    eBaseSharingMode BaseSharingMode;
    cTkDynamicArray<TkID<128>> maSeenSubstances;
    cTkDynamicArray<TkID<128>> maSeenTechnologies;
    cTkDynamicArray<TkID<128>> maSeenProducts;
    cTkDynamicArray<TkID<256>> maSeenWikiTopics;
    cTkDynamicArray<TkID<256>> maUnlockedWikiTopics;
    cTkDynamicArray<TkID<128>> maUnlockedTitles;
    cTkDynamicArray<TkID<128>> maUnlockedSpecials;
    cTkDynamicArray<TkID<128>> maUnlockedSeasonRewards;
    cTkDynamicArray<TkID<128>> maUnlockedTwitchRewards;
    cTkDynamicArray<TkID<128>> maUnlockedPlatformRewards;
    bool mbVoiceChat;
    bool mbMultiplayer;
    bool mbInstantUIInputs;
    bool mbInstantUIDelete;
    bool mbSpeechToText;
    bool mbTranslate;
    bool mbCrossPlatform;
    eTemperatureUnit TemperatureUnit;
    bool mbUseOldMouseFlight;
    int miLastSeenCommunityMission;
    int miLastSeenCommunityMissionTier;
    eMovementMode MovementMode;
    cGcMovementDirection MovementDirectionPad;
    cGcMovementDirection MovementDirectionHands;
    bool mbEnableControllerCursorInVR;
    eTurnMode TurnMode;
    float mfVRVignetteStrength;
    bool mbUseShipAutoControlVignette;
    float mfHUDZoom;
    float mfFrontendZoom;
    bool mbUseAutoTorch;
    eUIColourScheme UIColourScheme;
    bool mbEnableModdingConsole;
    bool mbHeadBob;
    bool mbVRHeadBob;
    bool mbVRShowBody;
    bool mbUseCharacterHeightForCamera;
    bool mbBaseComplexityLimitsEnabled;
    bool mbEnableLargeLobbies;
    int miFireteamSessionCount;
    int miHeadsetVibrationStrength;
    int miVibrationStrength;
    int miCamerShakeStrength;
    int miTriggerFeedbackStrength;
    eSpaceCombatFollowMode SpaceCombatFollowMode;
    cTkDynamicArray<cTkFixedString<128,char>> maUpgradedUsers;
    bool mbAllowWhiteScreenTransitions;
    bool mbAccessibleText;
    bool mbAutoScanDiscoveries;
    bool mbSprintScanSwap;
    bool mbPlaceJumpSwap;
    exEyeTrackingFlags EyeTrackingFlags;
    cGcGyroSettingsData GyroSettings;
    cTkLanguages Language;
    bool mbAutoRotateThirdPersonPlayerCamera;
    cGcHand DominantHand;
    float mfHazardEffectsStrength;
    bool mbQuickMenuBuildMenuSwap;
    eHighResVRUI HighResVRUI;
    float mfPlayerHUDVROffset;
    float mfShipHUDVROffset;
    cGcInWorldUIScreenData QuickMenuLauncherScreenData;
    cGcInWorldUIScreenData VehicleWristMenuScreenData;
    cGcInWorldUIScreenData WeaponMenuScreenData;
    cGcInWorldUIScreenData LargeWeaponMenuScreenData;
}
