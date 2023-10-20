#include "lang.h"

HeridiumCXXFile::HeridiumCXXFile(const char* lpacFileLocation, const cTkMetaDataClass* lpMetaDataClass) :
    mTargetFile(lpacFileLocation),
    mpMetaDataClass(lpMetaDataClass)
{
    this->DoHeaderFirstPass();
    this->WriteHeaderFile();
    this->WriteSourceFile();
}

void HeridiumCXXFile::DoHeaderFirstPass() {
    //Todo: this.
}

void HeridiumCXXFile::WriteHeaderFile()
{
    HM_BEGIN_BUFFER; 

    HM_PRELUDE;
    HM_CLASS_BEGIN(this->mpMetaDataClass->mpacName);

    // hashes
    HM_MEMBER_VAL("static unsigned long long", "muNameHash", fmt::format("{:X}", this->mpMetaDataClass->muNameHash));
    HM_MEMBER_VAL("static unsigned long long", "muTemplateHash", fmt::format("{:X}", this->mpMetaDataClass->muTemplateHash));

    for(int i = 0; i < this->mpMetaDataClass->miNumMembers; i++)
    {
        cTkMetaDataMember currentMember = this->mpMetaDataClass->maMembers[i];

        switch(currentMember.mType)
        {
            case cTkMetaDataMember::EType_Unspecified:
                exit(1); //fuck your program
            case cTkMetaDataMember::EType_Bool:
                HM_MEMBER(cTkMetaDataMember::EType_Bool, currentMember.mpacName);

        }
    }
}

void HeridiumCXXFile::WriteSourceFile() {
    //Todo: this.
}