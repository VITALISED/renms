#pragma once
#include <metadata/metadata_common.h>
enum eDownloadType
{
    EDownloadType_Unknown = 0,
    EDownloadType_Discovery = 1,
    EDownloadType_Base = 2,
    EDownloadType_Message = 3,
}

class cGcAtlasDownloadType
{
    static unsigned long long muNameHash = 0x73783FC8636BAB3E;
    static unsigned long long muTemplateHash = 0xC1A12C832D4AC62A;

    eDownloadType DownloadType;
}
