#pragma once
#include <metadata/metadata_common.h>
enum eWonderWeirdBasePartCategory
{
    EWonderWeirdBasePartCategory_EngineOrb = 0,
    EWonderWeirdBasePartCategory_BeamStone = 1,
    EWonderWeirdBasePartCategory_BubbleCluster = 2,
    EWonderWeirdBasePartCategory_MedGeometric = 3,
    EWonderWeirdBasePartCategory_Shard = 4,
    EWonderWeirdBasePartCategory_StarJoint = 5,
    EWonderWeirdBasePartCategory_BoneGarden = 6,
    EWonderWeirdBasePartCategory_ContourPod = 7,
    EWonderWeirdBasePartCategory_HydroPod = 8,
    EWonderWeirdBasePartCategory_ShellWhite = 9,
    EWonderWeirdBasePartCategory_WeirdCube = 10,
}

class cGcWonderWeirdBasePartCategory
{
    static unsigned long long muNameHash = 0xBF7B60D4CA07A9C0;
    static unsigned long long muTemplateHash = 0xC4FD35234E48565C;

    eWonderWeirdBasePartCategory WonderWeirdBasePartCategory;
}
