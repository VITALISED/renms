#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcbytebeatsong.meta.h>

class cGcByteBeatLibraryData
{
    static unsigned long long muNameHash = 0x1D3FECE6AC6A7E9F;
    static unsigned long long muTemplateHash = 0x77725A322F5E2BE8;

    cTkFixedArray<cGcByteBeatSong> maMySongs;
    cTkFixedArray<TkID<128>> maPlaylist;
    bool mbShuffle;
    bool mbAutoplayOnFoot;
    bool mbAutoplayInShip;
    bool mbAutoplayInVehicle;
}
