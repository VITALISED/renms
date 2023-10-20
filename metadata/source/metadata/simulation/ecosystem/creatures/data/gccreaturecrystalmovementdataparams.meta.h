#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcbiomesubtype.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/animation/tkcurvetype.meta.h>
enum eDeathType
{
    EDeathType_Explode = 0,
    EDeathType_Drop = 1,
}

class cGcCreatureCrystalMovementDataParams
{
    static unsigned long long muNameHash = 0x1232AC16AD2DF95C;
    static unsigned long long muTemplateHash = 0x918FDBF743EC6311;

    cTkDynamicArray<cGcBiomeSubType> maValidBiomes;
    cTkDynamicArray<TkID<256>> maValidDescriptors;
    int miNumShards;
    bool mbUseTerrainAngle;
    bool mbScaleOnAppear;
    cGcAudioWwiseEvents CreationAudio;
    float mfSpawnDist;
    float mfDespawnDist;
    float mfMaxOffset;
    float mfMaxOffsetZ;
    float mfMaxTilt;
    float mfOffsetTilt;
    float mfMinScale;
    float mfMaxScale;
    float mfMinAppearTime;
    float mfMaxAppearTime;
    float mfAppearOvershoot;
    float mfMinDisappearTime;
    float mfMaxDisappearTime;
    float mfShowOffset;
    float mfHideOffset;
    float mfMinShowTime;
    bool mbCustomHideCurve;
    cTkCurveType HideCurve;
    float mfIdleSpeedModifier;
    float mfWalkSpeedModifier;
    float mfRunSpeedModifier;
    float mfParticleScale;
    TkID<128> mDustEffect;
    cGcAudioWwiseEvents Audio;
    cGcAudioWwiseEvents RetractAudio;
    cGcAudioWwiseEvents MoveStartAudio;
    cGcAudioWwiseEvents MoveStopAudio;
    float mfDeathFadeStart;
    float mfDeathFadeTime;
    eDeathType DeathType;
    eSubType SubType;
    cTkFixedString<32,char> macTentacleStartJoint;
    cTkFixedString<32,char> macTentacleEndJoint;
    float mfTentacleSpeed;
    float mfTentacleChurnSpeed;
    float mfTentacleIdleLookChance;
    float mfTentacleStretchMin;
    float mfTentacleStretchMax;
    float mfTentacleMoveSwingAngle;
    float mfTentacleWalkSwingSpeed;
    float mfTentacleRunSwingSpeed;
    float mfTentacleRotationApplyBase;
    float mfTentacleRotationApplyTip;
    float mfTentacleMoveTimeMin;
    float mfTentacleMoveTimeMax;
    float mfTentaclePitchRange;
    float mfTentacleYawRange;
    float mfTentacleRollRange;
}
