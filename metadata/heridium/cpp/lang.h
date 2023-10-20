#include "lex.h"
#include "notation.h"
#include "../heridium.h"

class HeridiumCXXFile
{
    std::ofstream mTargetFile;
    const char* mpacFileLocation;
    const cTkMetaDataClass* mpMetaDataClass;
    
public:
    void WriteHeaderFile();
    void WriteSourceFile();

    HeridiumCXXFile(const char* lpacFileLocation, const cTkMetaDataClass* lpMetaDataClass);
};