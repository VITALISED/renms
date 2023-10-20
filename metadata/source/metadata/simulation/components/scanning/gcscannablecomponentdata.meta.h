#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eScannableType
{
    EScannableType_Binoculars = 0,
    EScannableType_BinocularsHotspots = 1,
    EScannableType_Scanner = 2,
    EScannableType_Marker = 3,
    EScannableType_None = 4,
}

class cGcScannableComponentData
{
    static unsigned long long muNameHash = 0x74BA808E86F0EC01;
    static unsigned long long muTemplateHash = 0x99F74C03F8948E2C;

    float mfScanRange;
    cTkFixedString<32,char> macScanName;
    float mfScanTime;
    float mfCompassRangeMultiplier;
    float mfAlwaysShowRange;
    bool mbCanTagIcon;
    bool mbClearTagOnArrival;
    bool mbDisableIfBuildingPart;
    bool mbDisableIfInBase;
    bool mbUseModelNode;
    cGcScannerIconTypes Icon;
    eScannableType ScannableType;
    bool mbIsPlacedMarker;
    bool mbShowInFreighterBranchRoom;
    bool mbTellPlayerIfFreighterObjectUsed;
    TkID<256> mFreighterObjectAlreadyUsedLocID;
    bool mbAllowedToMerge;
    bool mbMarkerActiveWithNodeInactive;
    TkID<128> mMissionSurveyId;
    float mfMinDisplayDistanceOverride;
}
