#pragma once
#include <metadata/metadata_common.h>
enum eResourceOrigin
{
    EResourceOrigin_Terrain = 0,
    EResourceOrigin_Crystal = 1,
    EResourceOrigin_Asteroid = 2,
    EResourceOrigin_Robot = 3,
    EResourceOrigin_Depot = 4,
}

class cGcResourceOrigin
{
    static unsigned long long muNameHash = 0xA7C99AD4BD0E24FB;
    static unsigned long long muTemplateHash = 0xA9B211D37A8AEB9A;

    eResourceOrigin ResourceOrigin;
}
