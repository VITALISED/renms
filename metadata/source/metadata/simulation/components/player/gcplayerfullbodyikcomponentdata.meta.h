#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum ePlayerHeadUpAxis
{
    EPlayerHeadUpAxis_X = 0,
    EPlayerHeadUpAxis_XNeg = 1,
    EPlayerHeadUpAxis_Y = 2,
    EPlayerHeadUpAxis_YNeg = 3,
    EPlayerHeadUpAxis_Z = 4,
    EPlayerHeadUpAxis_ZNeg = 5,
}
#include <?>
#include <?>

class cGcPlayerFullBodyIKComponentData
{
    static unsigned long long muNameHash = 0x80648B8FC1E7CB4D;
    static unsigned long long muTemplateHash = 0x1050DC441F582ECB;

    bool mbEnabled;
    bool mbEnableFootRaycasts;
    cTkDynamicArray<cGcIKConstraint> maHeadConstraints;
    cTkDynamicArray<cGcIKConstraint> maLegConstraints;
    cGcIKConstraint COGConstraint;
    cTkDynamicArray<cGcIKConstraint> maRestrictConstraints;
    cTkDynamicArray<cTkFixedString<32,char>> maHandBones;
    cTkDynamicArray<cTkFixedString<32,char>> maCameraNeckBones;
    cGcIKConstraint SitConstraint;
    ePlayerHeadUpAxis PlayerHeadUpAxis;
    cTkDynamicArray<cGcCreatureIkData> maJointDataDeprecated;
    bool mbUseFootGlue;
    cGcCharacterLookAtData LookAtSettings;
}
