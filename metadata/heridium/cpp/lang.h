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
    const char* FindIncludePathForClass(const char* lpacClassName);
    const char* DoEnumLookup(cTkMetaDataMember* lpCurrentMember);
    const char* DoFlagLookup(cTkMetaDataMember* lpCurrentMember);
    const char* DoHeaderFirstPass();
    const char* GetInnerType(cTkMetaDataMember* lpCurrentMember);
    void WriteHeaderFile();
    void WriteSourceFile();

    HeridiumCXXFile(const char* lpacFileLocation, const cTkMetaDataClass* lpMetaDataClass);
};