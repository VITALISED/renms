#pragma once

#include <skyscraper.h>
#include <toolkit/system/pc/TkStorageCommon.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/system/filesystem/TkFileSystem.h>
#include <toolkit/system/TkPollResult.h>

SKYSCRAPER_BEGIN

struct ManifestData
{
    unsigned int muMagic;
    unsigned int muVersion;
    unsigned __int64 mu64HashSpooky1;
    unsigned __int64 mu64HashSpooky2;
    std::array<unsigned char,32> maHashSHA;
    int miOriginalDataSize;
    int miCompressedDataSize;
    unsigned int muUsedUserIDInObfuscation;
    char mGameMetaData[280];
    std::array<unsigned int,3> maReserved;
};

class cTkStoragePersistent
{
    typedef TkPollResult State;

    struct LowSpaceWarningData
    {
        unsigned __int64 mu64RequestedMB;
        unsigned __int64 mu64RemainingMB;
        cTkFixedString<32,char> mDrive;
    };

    enum Slot
    {
        UserSettings,
        AccountData,
        PlayerState1,
        PlayerState2,
        PlayerState3,
        PlayerState4,
        PlayerState5,
        PlayerState6,
        PlayerState7,
        PlayerState8,
        PlayerState9,
        PlayerState10,
        PlayerState11,
        PlayerState12,
        PlayerState13,
        PlayerState14,
        PlayerState15,
        PlayerState16,
        PlayerState17,
        PlayerState18,
        PlayerState19,
        PlayerState20,
        PlayerState21,
        PlayerState22,
        PlayerState23,
        PlayerState24,
        PlayerState25,
        PlayerState26,
        PlayerState27,
        PlayerState28,
        PlayerState29,
        PlayerState30,
        ___SlotCount,
    };
    
    struct Data : CommonStorageUserCred
    {
        struct  cTkSaveDataStreamPC : cTkSaveDataStreamBase
        { };

        wchar_t lcaAppDataPathRoot[260];
        wchar_t lcaFilenames[64][260];
        bool mbUsingLegacyFilenames;
        cTkStoragePersistent::LowSpaceWarningData mLowSpaceData;
        bool mbLowSpaceWarning;
        bool mbAccessDeniedWarning;
        cTkFixedString<1024,char> mDisplayableRootPath;
        wchar_t lcaSafePathRootInput[260];
        wchar_t lcaSafePathRootOutput[260];
        ManifestData maManifests[32];
        cTkStoragePersistent::Data::cTkSaveDataStreamPC mSaveDataStream;
        eFileOpenMode meStreamMode;
        cTkStoragePersistent::Slot meSlot;
        TkStorage::Blob mGameMetaData;
        void *mStreamSideloadHandle;
    };
    
    cTkStoragePersistent::Data *mpData;
    cTkStoragePersistent::State meState;
};