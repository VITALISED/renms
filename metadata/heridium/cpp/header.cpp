#include "lang.h"

HeridiumCXXFile::HeridiumCXXFile(const char* file_location, const cTkMetaDataClass* metadata_class) :
    target_file(file_location),
    metadata_class(metadata_class)
{
    this->DoHeaderFirstPass();
    this->WriteHeaderFile();
    this->WriteSourceFile();
}

void HeridiumCXXFile::DoHeaderFirstPass() {
    //Todo: this.
}

void HeridiumCXXFile::WriteHeaderFile()
{/* Immense compiler warnings
    HM_BEGIN_BUFFER; 

    HM_PRELUDE;
    HM_CLASS_BEGIN(this->metadata_class->mpacName);

    for(int i = 0; i < this->metadata_class->miNumMembers; i++)
    {
        cTkMetaDataMember currentMember = this->metadata_class->maMembers[i];

        //Todo: this.
        switch(currentMember.mType)
        {
            case cTkMetaDataMember::EType_Unspecified:
                exit(1); //fuck your program
            case cTkMetaDataMember::EType_Bool:


        }
    }
*/}

void HeridiumCXXFile::WriteSourceFile() {
    //Todo: this.
}