#pragma once
#include <metadata/metadata_common.h>
enum eSynchroniseScale
{
    ESynchroniseScale_Never = 0,
    ESynchroniseScale_Once = 1,
    ESynchroniseScale_Always = 2,
}

class cGcNetworkInterpolationComponentData
{
    static unsigned long long muNameHash = 0x1A8AEEF0DF2E3D8A;
    static unsigned long long muTemplateHash = 0x932FB3213B02066D;

    eSynchroniseScale SynchroniseScale;
    bool mbSupportTeleportation;
}
