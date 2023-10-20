#pragma once
#include <metadata/metadata_common.h>
enum eNodeActiveState
{
    ENodeActiveState_Activate = 0,
    ENodeActiveState_Deactivate = 1,
    ENodeActiveState_Toggle = 2,
    ENodeActiveState_Add = 3,
    ENodeActiveState_Remove = 4,
    ENodeActiveState_RemoveChildren = 5,
}

class cGcNodeActivationAction
{
    static unsigned long long muNameHash = 0xB2C5F1A083F1473A;
    static unsigned long long muTemplateHash = 0x901A4F810577784F;

    eNodeActiveState NodeActiveState;
    cTkFixedString<128,char> macName;
    cTkFixedString<128,char> macSceneToAdd;
    bool mbIncludePhysics;
    bool mbIncludeChildPhysics;
    bool mbNotifyNPC;
    bool mbUseMasterModel;
    bool mbUseLocalNode;
    bool mbRestartEmitters;
    bool mbAffectModels;
}
