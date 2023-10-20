#pragma once
#include <metadata/metadata_common.h>
enum eScannerRechargeDifficulty
{
    EScannerRechargeDifficulty_VeryFast = 0,
    EScannerRechargeDifficulty_Fast = 1,
    EScannerRechargeDifficulty_Normal = 2,
    EScannerRechargeDifficulty_Slow = 3,
}

class cGcScannerRechargeDifficultyOption
{
    static unsigned long long muNameHash = 0x5980B3D90F168F60;
    static unsigned long long muTemplateHash = 0x2C77C6A1D7CCA517;

    eScannerRechargeDifficulty ScannerRechargeDifficulty;
}
