#pragma once
#include <metadata/metadata_common.h>
enum eActiveModeOnFoot
{
    EActiveModeOnFoot_None = 0,
    EActiveModeOnFoot_ScopeOnly = 1,
    EActiveModeOnFoot_ScopeOrFiring = 2,
    EActiveModeOnFoot_Always = 3,
}
enum eActiveModeWhenBuilding
{
    EActiveModeWhenBuilding_None = 0,
    EActiveModeWhenBuilding_BuildPlacementOnly = 1,
    EActiveModeWhenBuilding_SelectionModeOnly = 2,
    EActiveModeWhenBuilding_Always = 3,
}
enum eEnableGyroInBuildingFreeCam
{
    EEnableGyroInBuildingFreeCam_Never = 0,
    EEnableGyroInBuildingFreeCam_MatchActiveModeWhenBuilding = 1,
    EEnableGyroInBuildingFreeCam_Always = 2,
}
enum eActiveModeInExocraft
{
    EActiveModeInExocraft_None = 0,
    EActiveModeInExocraft_Firing = 1,
    EActiveModeInExocraft_Always = 2,
}
enum eLookStickEnabled
{
    ELookStickEnabled_None = 0,
    ELookStickEnabled_Disabled = 1,
    ELookStickEnabled_Enabled = 2,
}
enum eHandedness
{
    EHandedness_Left = 0,
    EHandedness_Right = 1,
}
enum eYawAxisDirection
{
    EYawAxisDirection_Disabled = 0,
    EYawAxisDirection_Standard = 1,
    EYawAxisDirection_Inverted = 2,
}
enum eRollAxisDirection
{
    ERollAxisDirection_Disabled = 0,
    ERollAxisDirection_Standard = 1,
    ERollAxisDirection_Inverted = 2,
}

class cGcGyroSettingsData
{
    static unsigned long long muNameHash = 0x4EA99277E076565E;
    static unsigned long long muTemplateHash = 0xDC3376240A715E64;

    bool mbGyroEnabled;
    bool mbGyroEnabledHandheld;
    eActiveModeOnFoot ActiveModeOnFoot;
    bool mbAllowWhenRidingCreatures;
    eActiveModeWhenBuilding ActiveModeWhenBuilding;
    eEnableGyroInBuildingFreeCam EnableGyroInBuildingFreeCam;
    eActiveModeInExocraft ActiveModeInExocraft;
    eLookStickEnabled LookStickEnabled;
    bool mbGyroCursorEnabled;
    float mfCursorSensitivityX;
    float mfCursorSensitivityY;
    float mfCursorTighteningThreshold;
    eCursorLookStickEnabled CursorLookStickEnabled;
    eHandedness Handedness;
    float mfSensitivityX;
    float mfSensitivityY;
    float mfSteadying;
    float mfAcceleration;
    bool mbEnableAdvancedOptions;
    float mfScopeMultiplier;
    float mfAimingMultiplier;
    float mfExocraftMultiplier;
    float mfBuildingMultiplier;
    bool mbZoomScalesSensitivity;
    eGyroRotationSpace GyroRotationSpace;
    eGyroRotationSpaceHandheld GyroRotationSpaceHandheld;
    eYawAxisDirection YawAxisDirection;
    eRollAxisDirection RollAxisDirection;
    ePitchAxisDirection PitchAxisDirection;
    float mfSmoothingThreshold;
    float mfSmoothingWindow;
    float mfTighteningThreshold;
    float mfDeadzone;
    bool mbFilterControllerVibrations;
}
