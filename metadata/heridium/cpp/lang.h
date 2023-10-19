#include "lex.h"
#include "notation.h"

#include <fstream>

class HeridiumCXXFile
{
    std::ofstream target_file;
    const char* file_location;
    const cTkMetaDataClass* metadata_class;
    
public:
    void DoHeaderFirstPass();
    void WriteHeaderFile();
    void WriteSourceFile();

    HeridiumCXXFile(const char* file_location, const cTkMetaDataClass* metadata_class);
};