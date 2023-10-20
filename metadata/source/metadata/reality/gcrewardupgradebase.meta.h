#pragma once
#include <metadata/metadata_common.h>
enum eUpgradeBaseType
{
    EUpgradeBaseType_AllMatching = 0,
    EUpgradeBaseType_NearestMatching = 1,
}
#include <?>

class cGcRewardUpgradeBase
{
    static unsigned long long muNameHash = 0xE60E16C73CCFBAC0;
    static unsigned long long muTemplateHash = 0xFFE472115B564B2D;

    eUpgradeBaseType UpgradeBaseType;
    cTkDynamicArray<cGcPersistentBaseTypes> maMatchingBaseTypes;
}
