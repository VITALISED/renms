#include "lex.h"
#include "notation.h"
#include "../heridium.h"

class HeridiumCXXFile
{
    std::ofstream mTargetFile;
    const char* mpacFileLocation;
    const cTkMetaDataClass* mpMetaDataClass;
    std::vector<const char*> mDefinedTypes;
    
public:
    std::string FindIncludePathForClass(const char* lpacClassName);
    std::string DoEnumLookup(cTkMetaDataMember* lpCurrentMember);
    std::string DoFlagLookup(cTkMetaDataMember* lpCurrentMember);
    std::string DoHeaderFirstPass();
    std::string GetInnerType(cTkMetaDataMember* lpCurrentMember);
    void WriteHeaderFile();
    void WriteSourceFile();

    HeridiumCXXFile(const char* lpacFileLocation, const cTkMetaDataClass* lpMetaDataClass);
};