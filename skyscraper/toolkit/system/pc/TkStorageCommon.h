#pragma once

#include <skyscraper.h>
#include <toolkit/system/filesystem/TkFileSystem.h>

SKYSCRAPER_BEGIN

namespace TkStorage
{
    struct Blob
    {
        void *mpacData;
        unsigned int muDataLength;
        bool mbDeleteDataPtrOnCtor;
    };
}

struct CommonStorageUserCred
{
    unsigned __int64 mu64UserID;
    bool mbValidUserID;
};

class cTkSaveDataStreamBase
{
    int miFileOffsetBytes;
    char *mpaChunkBuffer;
    char *mpaCompressedChunkBuffer;
    unsigned int muCompressedChunkBufferSize;
    char *mpStreamPointer;
    char *mpEndStreamPointer;
    int miTotalBytesStreamed;
    int miTotalBytesCompressed;
    eFileOpenMode meStreamMode;
    bool mbCompressed;

    virtual __int64 PlatformReadFile(unsigned __int64, void *, __int64);
    virtual __int64 PlatformWriteFile(unsigned __int64, void *, __int64);
};

SKYSCRAPER_END