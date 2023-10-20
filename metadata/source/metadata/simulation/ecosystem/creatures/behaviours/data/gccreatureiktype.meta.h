#pragma once
#include <metadata/metadata_common.h>
enum eCreatureIkType
{
    ECreatureIkType_Foot = 0,
    ECreatureIkType_Hinge_X = 1,
    ECreatureIkType_Hinge_Y = 2,
    ECreatureIkType_Hinge_Z = 3,
    ECreatureIkType_Locked = 4,
    ECreatureIkType_Head = 5,
    ECreatureIkType_Toe = 6,
    ECreatureIkType_SpaceshipFoot = 7,
    ECreatureIkType_SpaceshipToe = 8,
}

class cGcCreatureIkType
{
    static unsigned long long muNameHash = 0x1A5C8AEE15BC00C7;
    static unsigned long long muTemplateHash = 0x42748B3F25F8C43A;

    eCreatureIkType CreatureIkType;
}
