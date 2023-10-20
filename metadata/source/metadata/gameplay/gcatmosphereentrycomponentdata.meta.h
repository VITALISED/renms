#pragma once
#include <metadata/metadata_common.h>

class cGcAtmosphereEntryComponentData
{
    static unsigned long long muNameHash = 0x90485A00D3954CE2;
    static unsigned long long muTemplateHash = 0xAD817E4B7355FC77;

    bool mbAutoEntry;
    float mfEntryTime;
    float mfEntryOffset;
    float mfEditTerrainRadius;
    TkID<128> mImpactEffect;
    TkID<128> mFlareEffect;
}
