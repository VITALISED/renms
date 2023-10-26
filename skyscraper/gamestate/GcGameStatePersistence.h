#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkString.h>
#include <metadata/source/gamestate/gcgamemode.meta.h>
#include <metadata/source/user/gcdifficultypresettype.meta.h>

SKYSCRAPER_BEGIN

namespace GcGameStatePersistence
{
    enum eSaveVersion
    {
        ESaveVersion_Unknown = 0x0,
        ESaveVersion_RC1 = 0x1001,
        ESaveVersion_Patch1 = 0x1002,
        ESaveVersion_Update1 = 0x1003,
        ESaveVersion_Update1_1 = 0x1004,
        ESaveVersion_Update1_2 = 0x1005,
        ESaveVersion_Update1_3 = 0x1006,
        ESaveVersion_Update1_33 = 0x1007,
        ESaveVersion_Update1_35 = 0x1008,
        ESaveVersion_Update1_39 = 0x1009,
        ESaveVersion_Update1_4Internal = 0x1010,
        ESaveVersion_Update1_4 = 0x1011,
        ESaveVersion_Update1_5 = 0x1012,
        ESaveVersion_Update1_51 = 0x1013,
        ESaveVersion_Update1_62 = 0x1014,
        ESaveVersion_Update1_8 = 0x1015,
        ESaveVersion_Update1_81 = 0x1016,
        ESaveVersion_Update1_82 = 0x1017,
        ESaveVersion_Update1_83 = 0x1018,
        ESaveVersion_Update1_84 = 0x1019,
        ESaveVersion_Update1_85 = 0x101A,
        ESaveVersion_Update1_86 = 0x101B,
        ESaveVersion_Update1_87 = 0x101C,
        ESaveVersion_Update1_88 = 0x101D,
        ESaveVersion_Update1_89 = 0x101E,
        ESaveVersion_Update1_90 = 0x101F,
        ESaveVersion_Update1_91 = 0x1020,
        ESaveVersion_Update3_30 = 0x1021,
        ESaveVersion_Update3_32 = 0x1022,
        ESaveVersion_Update3_34 = 0x1023,
        ESaveVersion_Update3_35 = 0x1024,
        ESaveVersion_Update3_36 = 0x1025,
        ESaveVersion_Update3_52 = 0x1026,
        ESaveVersion_Update3_53 = 0x1027,
        ESaveVersion_Update3_80 = 0x1028,
        ESaveVersion_Update3_81 = 0x1029,
        ESaveVersion_Update3_85 = 0x102A,
        ESaveVersion_Update3_94 = 0x102B,
        ESaveVersion_Update4_00 = 0x102C,
        ESaveVersion_Update4_04 = 0x102D,
        ESaveVersion_Update4_05 = 0x102E,
        ESaveVersion_Update4_09 = 0x102F,
        ESaveVersion_GameModeMask = 0xE00,
        ESaveVersion_GameModeShift = 0x9,
        ESaveVersion_SeasonNumberMask = 0xFFFF0000,
        ESaveVersion_SeasonNumberShift = 0x10,
    };

    struct StorageSlotInformation
    {
        bool mbInUse;
        int miTimestamp;
        int miPlayTime;
        ePresetGameMode meGameMode;
        eDifficultyPresetType meDifficultyPreset;
        GcGameStatePersistence::eSaveVersion meVersion;
        unsigned int muDataSize;
        unsigned int muSlotIndex;
        unsigned __int16 mu16SeasonNumber;
        cTkFixedString<128,char> macSaveName;
        cTkFixedString<128,char> macSaveSummary;
    }; 
}; 

SKYSCRAPER_END