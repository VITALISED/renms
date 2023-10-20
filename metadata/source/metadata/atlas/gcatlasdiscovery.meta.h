#pragma once
#include <metadata/metadata_common.h>
#include <metadata/atlas/gcatlasdownloadtype.meta.h>
#include <metadata/reality/gcdiscoveryowner.meta.h>
#include <metadata/atlas/gcatlasdiscoverydata.meta.h>
#include <metadata/atlas/gcatlasdiscoverymetadata.meta.h>
#include <metadata/atlas/gcatlasmessage.meta.h>

class cGcAtlasDiscovery
{
    static unsigned long long muNameHash = 0x886C03C3F3987F4;
    static unsigned long long muTemplateHash = 0x3A1F612CFFA8437F;

    cGcAtlasDownloadType PackageType;
    cGcDiscoveryOwner Owner;
    cGcAtlasDiscoveryData Data;
    cGcAtlasDiscoveryMetadata Metadata;
    cGcAtlasMessage MessageData;
    cTkFixedString<64,char> macRID;
    cTkFixedString<32,char> macPTK;
}
