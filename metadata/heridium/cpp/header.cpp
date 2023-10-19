#include "lang.h"

void HeridiumCXXFile::WriteHeaderFile()
{
    HM_BEGIN_BUFFER; 

    HM_PRELUDE;
    HM_CLASS_BEGIN(this->metadata_class->mpacName);

    for(int i = 0; i < this->metadata_class->miNumMembers; i++)
    {
        cTkMetaDataMember currentMember = this->metadata_class->maMembers[i];

        switch(currentMember.mType)
        {
            case cTkMetaDataMember::EType_Unspecified:
                exit(1); //fuck your program
            case cTkMetaDataMember::EType_Bool:


        }
    }
}