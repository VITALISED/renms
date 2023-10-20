#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tkparticleburstdata.meta.h>
#include <metadata/utilities/data/tkemitterfloatproperty.meta.h>
#include <metadata/utilities/data/tkemitfromparticleinfo.meta.h>
#include <metadata/animation/tkcurvetype.meta.h>
enum eDragType
{
    EDragType_IgnoreGravity = 0,
    EDragType_PhysicallyBased = 1,
    EDragType_ApplyWind = 2,
}
enum eSpawnOffsetType
{
    ESpawnOffsetType_Sphere = 0,
    ESpawnOffsetType_Box = 1,
    ESpawnOffsetType_Disc = 2,
    ESpawnOffsetType_Cone = 3,
    ESpawnOffsetType_Donut = 4,
    ESpawnOffsetType_Point = 5,
}
enum eBillboardAlignment
{
    EBillboardAlignment_Screen = 0,
    EBillboardAlignment_XLocal = 1,
    EBillboardAlignment_YLocal = 2,
    EBillboardAlignment_ZLocal = 3,
    EBillboardAlignment_NegativeXLocal = 4,
    EBillboardAlignment_NegativeYLocal = 5,
    EBillboardAlignment_NegativeZLocal = 6,
    EBillboardAlignment_ScreenWorld = 7,
}
#include <metadata/utilities/data/tkcoordinateorientation.meta.h>
enum eFlipbookPlaybackRate
{
    EFlipbookPlaybackRate_Absolute = 0,
    EFlipbookPlaybackRate_RelativeToMax = 1,
    EFlipbookPlaybackRate_OnceToCompletion = 2,
    EFlipbookPlaybackRate_Random = 3,
}
enum eOnRefractionsDisabled
{
    EOnRefractionsDisabled_Hide = 0,
    EOnRefractionsDisabled_AlphaBlend = 1,
}
#include <metadata/tkfloatrange.meta.h>

class cTkParticleData
{
    static unsigned long long muNameHash = 0xE9525144C4F949EB;
    static unsigned long long muTemplateHash = 0x353F8C32388B38B0;

    unsigned int muiAudioEvent;
    bool mbStartEnabled;
    bool mbOneshot;
    int miMaxCount;
    cTkParticleBurstData BurstData;
    cTkEmitterFloatProperty EmissionRate;
    float mfDelay;
    cTkEmitFromParticleInfo EmitFromParticleInfo;
    cTkEmitterFloatProperty ParticleLife;
    cTkEmitterFloatProperty EmitterLife;
    float mfEmitterMidLifeRatio;
    cTkCurveType EmitterLifeCurve1;
    cTkCurveType EmitterLifeCurve2;
    float mfEmitterSpreadAngle;
    float mfEmitterSpreadAngleMin;
    cTkVector3 mEmitterDirection;
    cTkEmitterFloatProperty ParticleSpeedMultiplier;
    cTkEmitterFloatProperty ParticleGravity;
    cTkEmitterFloatProperty ParticleDamping;
    cTkEmitterFloatProperty ParticleDrag;
    eDragType DragType;
    float mfVariation;
    float mfStartOffset;
    eSpawnOffsetType SpawnOffsetType;
    cTkVector3 mSpawnOffsetParams;
    cTkEmitterFloatProperty ParticleSize;
    cTkEmitterFloatProperty ParticleSizeY;
    float mfStartRotationVariation;
    cTkEmitterFloatProperty Rotation;
    eAlignment Alignment;
    eBillboardAlignment BillboardAlignment;
    cTkVector3 mRotationPivot;
    cTkCoordinateOrientation UCoordinate;
    cTkCoordinateOrientation VCoordinate;
    float mfVelocityInheritance;
    float mfTrackEmitterPosition;
    float mfRotateAroundEmitter;
    cTkVector3 mRotateAroundEmitterAxis;
    eFlipbookPlaybackRate FlipbookPlaybackRate;
    float mfHueVariance;
    float mfSaturationVariance;
    float mfLightnessVariance;
    float mfAlphaVariance;
    cTkColour mColourStart;
    cTkColour mColourMiddle;
    cTkColour mColourEnd;
    cTkEmitterFloatProperty AlphaThreshold;
    eOnRefractionsDisabled OnRefractionsDisabled;
    bool mbFadeRefractionsAtScreenEdge;
    TkID<128> mUserColour;
    float mfMaxRenderDistance;
    float mfMaxSpawnDistance;
    float mfSoftFadeStrength;
    cTkFloatRange CameraDistanceFade;
}
