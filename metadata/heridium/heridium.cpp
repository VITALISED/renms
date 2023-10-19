#include "heridium.h"

HERIDIUM_BEGIN

void CreateOutputDirectories()
{
#if HERIDIUM_LANGUAGE_TARGET == EHeridiumLanguageType_CXX
    char* lpacLocalPath = (char*)"/HERIDIUM/cpp/";
#else 
    static_assert("No language target defined for heridium");
#endif

    for(std::pair<const char*, const char*> lPair : classPaths)
    {
        strcat(lpacLocalPath, lPair.second);
        char* lpacFullPath = (char*)std::filesystem::current_path().string().c_str(); // peak c++
        strcat(lpacFullPath, lpacLocalPath);
        std::filesystem::create_directories(lpacFullPath);
    }
};

HERIDIUM_END