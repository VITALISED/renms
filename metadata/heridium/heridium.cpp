#include "heridium.h"

HERIDIUM_BEGIN

#if HERIDIUM_LANGUAGE_TARGET == EHeridiumLanguageType_CXX
    //Might be a thing in the future, will never run the below for now
#else 
    static_assert("No language target defined for heridium");
#endif

//This also creates the header with all the includes
void CreateOutputDirectories()
{
    std::ofstream lHeaderStream("./GIVEMEALLTHECLASSES.h");
    lHeaderStream << "#pragma once\n\n";
    for(std::pair<const char*, const char*> lPair : classPaths)
    {
        if (std::string(lPair.second) != "source/globals/gcdebugoptions.meta.h")
            lHeaderStream << "#include \"" << lPair.second << "\"\n";

        std::string lpacLocalPath = "/";
        lpacLocalPath.append(lPair.second);
        std::string lpacFullPath = std::filesystem::current_path().string(); 
        lpacFullPath.append(lpacLocalPath);
        size_t lastindex = lpacFullPath.find_last_of("/"); 
        std::string lpacDirPath = lpacFullPath.substr(0, lastindex); 
        std::filesystem::create_directories(lpacDirPath);
    }

    lHeaderStream.close();
};

HERIDIUM_END