#include "lex.h"
#include "notation.h"

#include <fstream>

class HeridiumCXXFile
{
    const char* file_location;
    const cTkMetaDataClass* metadata_class;
    std::ofstream target_file;
    
public:
    HeridiumCXXFile(const char* file_location, const cTkMetaDataClass* metadata_class)
    {
        this->file_location = file_location;
        this->metadata_class = metadata_class;
        
        this->DoHeaderFirstPass();
        this->WriteHeaderFile();
        this->WriteSourceFile();
    }

    void WriteHeaderFile();
    void DoHeaderFirstPass();
    void WriteSourceFile();
};