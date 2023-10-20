#pragma once
#include <metadata/metadata_common.h>
enum eScaleInTransformApplicationOnCloth
{
    EScaleInTransformApplicationOnCloth_Multiply = 0,
    EScaleInTransformApplicationOnCloth_Divide = 1,
    EScaleInTransformApplicationOnCloth_Ignore = 2,
}
enum eScaleInTransformApplicationOnCollision
{
    EScaleInTransformApplicationOnCollision_Multiply = 0,
    EScaleInTransformApplicationOnCollision_Divide = 1,
    EScaleInTransformApplicationOnCollision_Ignore = 2,
}
enum eScaleInTransformApplicationOnAttachment
{
    EScaleInTransformApplicationOnAttachment_Multiply = 0,
    EScaleInTransformApplicationOnAttachment_Divide = 1,
    EScaleInTransformApplicationOnAttachment_Ignore = 2,
}
enum eInitialShapeSource
{
    EInitialShapeSource_Rectangular = 0,
    EInitialShapeSource_TakenFromRenderMesh = 1,
    EInitialShapeSource_Saved = 2,
}
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcClothPiece
{
    static unsigned long long muNameHash = 0x7596FBA2C232AC37;
    static unsigned long long muTemplateHash = 0xABA3C17DBE6EBD46;

    bool mbEnabled;
    cTkFixedString<64,char> macDebugName;
    cTkFixedString<64,char> macRenderMeshNodeName;
    int miNumPointsInRenderMeshI;
    int miNumPointsInRenderMeshJ;
    int miVertexRemappingPermutation;
    int miNumSimPointsI;
    int miNumSimPointsJ;
    float mfClothHeight;
    float mfParticleRadius;
    float mfStaticFriction;
    float mfDampingWrtFixed;
    float mfAbsoluteDamping;
    float mfApplyGameWind;
    float mfAirSpeedFromMovementSpeedScale;
    float mfAirSpeedOverallEffect;
    float mfStandardGravityScale;
    cTkFixedString<64,char> macInitialShapeReferenceBone;
    eScaleInTransformApplicationOnCloth ScaleInTransformApplicationOnCloth;
    eScaleInTransformApplicationOnCollision ScaleInTransformApplicationOnCollision;
    eScaleInTransformApplicationOnAttachment ScaleInTransformApplicationOnAttachment;
    eInitialShapeSource InitialShapeSource;
    cGcRectangularInitialShape RectangularInitialShape;
    cTkDynamicArray<cTkVector3> maInitialShapePoints;
    cTkDynamicArray<cGcClothCollisionBone> maCollisionBones;
    cTkDynamicArray<cGcClothAttachmentCirlce> maAttachmentCircles;
    cTkDynamicArray<cGcClothAttachmentLine> maAttachmentLines;
    cTkDynamicArray<cGcAttachmentPointSet> maAttachmentPointSets;
    cGcConstraintsToCreateSpec ConstraintsToCreate;
    cTkDynamicArray<cTkFixedString<64,char>> maNodesThatMustBePresent;
    cTkDynamicArray<cTkFixedString<64,char>> maNodesToHide;
    cGcAdvancedTweaks Advanced;
    bool mbVertexBasedClothRenderingEnabled;
    bool mbAttachedNodesEnabled;
    cTkDynamicArray<cGcAttachedNode> maAttachedNodes;
    float mfAttachedNodesOverallBlendStrength;
    cTkDynamicArray<int> maDeletedSimPoints;
    cTkDynamicArray<int> maDeletedConstraintsI;
    cTkDynamicArray<int> maDeletedConstraintsJ;
    bool mbLeaveRenderedTrianglesUnaffected;
}
