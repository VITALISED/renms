#pragma once
#include <metadata/metadata_common.h>
enum eAssertsLevel
{
    EAssertsLevel_Disabled = 0,
    EAssertsLevel_Ignored = 1,
    EAssertsLevel_Skipped = 2,
    EAssertsLevel_Enabled = 3,
}
enum exEnabledChannels
{
    FEnabledChannels_ = 0,
    FEnabledChannels_Default = 1,
    FEnabledChannels_Note = 2,
    FEnabledChannels_Error = 4,
    FEnabledChannels_Warning = 8,
    FEnabledChannels_Info = 16,
    FEnabledChannels_Alt = 32,
    FEnabledChannels_AltWarn = 64,
    FEnabledChannels_AltError = 128,
}

class cTkGlobals
{
    static unsigned long long muNameHash = 0xB62E6456DFE47836;
    static unsigned long long muTemplateHash = 0x91DC0B006B334CE8;

    eAssertsLevel AssertsLevel;
    bool mbDefaultSelectIgnoreAsserts;
    exEnabledChannels EnabledChannels;
    cTkFixedString<256,char> macIncludeLogFilter;
    cTkFixedString<256,char> macExcludeLogFilter;
    int miLoadBalanceTimeoutMS;
    int miVRLoadBalanceTimeoutMS;
    int miPSVR2LoadBalanceTimeoutMS;
    bool mbLogInputSetup;
    bool mbLogInputChanges;
    bool mbDisableResScaling;
    int miLODOverride;
    bool mbColourLODs;
    float mfWwiseVibrationMultiplierPrimary;
    float mfWwiseVibrationMultiplierSecondary;
    bool mbUseHeavyAir;
    bool mbSimulateDisabledParticleRefractions;
    bool mbDisableMultiplayer;
}
