#include "lang.h"

HeridiumCXXFile::HeridiumCXXFile(const char* lpacFileLocation, const cTkMetaDataClass* lpMetaDataClass) :
    mTargetFile(lpacFileLocation),
    mpMetaDataClass(lpMetaDataClass)
{
    this->WriteHeaderFile();
    this->WriteSourceFile();
}

void HeridiumCXXFile::WriteHeaderFile()
{
    HM_BEGIN_BUFFER; 

    HM_PRELUDE;
    HM_CLASS_BEGIN(this->mpMetaDataClass->mpacName);

    // hashes
    HM_MEMBER_VAL("static unsigned long long", "muNameHash", fmt::format("{:X}", this->mpMetaDataClass->muNameHash));
    HM_MEMBER_VAL("static unsigned long long", "muTemplateHash", fmt::format("{:X}", this->mpMetaDataClass->muTemplateHash));

    HM_PUSHSTRING("\n");

    for(int i = 0; i < this->mpMetaDataClass->miNumMembers; i++)
    {
        cTkMetaDataMember currentMember = this->mpMetaDataClass->maMembers[i];

        switch(currentMember.mType)
        {
            case cTkMetaDataMember::EType_Unspecified:
                break;
            case cTkMetaDataMember::EType_Bool:
                HM_MEMBER(cTkMetaDataMember::EType_Bool, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Byte:
                HM_MEMBER(cTkMetaDataMember::EType_Byte, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Class:
                //use class preprocessor
                break;
            case cTkMetaDataMember::EType_ClassPointer:
                HM_MEMBER(cTkMetaDataMember::EType_ClassPointer, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Colour:
                HM_MEMBER(cTkMetaDataMember::EType_Colour, currentMember.mpacName);
                break;
		    case cTkMetaDataMember::EType_DynamicArray:
                //use inner type preprocessor
                break;
            case cTkMetaDataMember::EType_DynamicString:
                HM_MEMBER(cTkMetaDataMember::EType_DynamicString, currentMember.mpacName);
                break;
		    case cTkMetaDataMember::EType_DynamicWideString:
                HM_MEMBER(cTkMetaDataMember::EType_DynamicWideString, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Enum:
                //user class preprocessor (maybe)
                break;
            case cTkMetaDataMember::EType_Filename:
                HM_MEMBER(cTkMetaDataMember::EType_Filename, currentMember.mpacName);
                break;
		    case cTkMetaDataMember::EType_Flags:
                //basically the same as an enum
                break;
            case cTkMetaDataMember::EType_Float:
                HM_MEMBER(cTkMetaDataMember::EType_Float, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_HalfVector4:
                HM_MEMBER(cTkMetaDataMember::EType_HalfVector4, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Id:
                HM_MEMBER(cTkMetaDataMember::EType_Id, currentMember.mpacName);
                break;
		    case cTkMetaDataMember::EType_Id256:
                HM_MEMBER(cTkMetaDataMember::EType_Id256, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Int:
                HM_MEMBER(cTkMetaDataMember::EType_Int, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Int16:
                HM_MEMBER(cTkMetaDataMember::EType_Int16, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Int64:
                HM_MEMBER(cTkMetaDataMember::EType_Int64, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Int8:
                HM_MEMBER(cTkMetaDataMember::EType_Int8, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_LocId:
                HM_MEMBER(cTkMetaDataMember::EType_LocId, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_NodeHandle:
                HM_MEMBER(cTkMetaDataMember::EType_NodeHandle, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_PhysRelVec:
                HM_MEMBER(cTkMetaDataMember::EType_PhysRelVec, currentMember.mpacName);
                break;
		    case cTkMetaDataMember::EType_Resource:
                HM_MEMBER(cTkMetaDataMember::EType_Resource, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Seed:
                HM_MEMBER(cTkMetaDataMember::EType_Seed, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_StaticArray:
                // use inner type preprocessor
                break;
            case cTkMetaDataMember::EType_String1024:
                HM_MEMBER(cTkMetaDataMember::EType_String1024, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_String128:
                HM_MEMBER(cTkMetaDataMember::EType_String128, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_String2048:
                HM_MEMBER(cTkMetaDataMember::EType_String2048, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_String256:
                HM_MEMBER(cTkMetaDataMember::EType_String256, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_String32:
                HM_MEMBER(cTkMetaDataMember::EType_String32, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_String512:
                HM_MEMBER(cTkMetaDataMember::EType_String512, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_String64:
                HM_MEMBER(cTkMetaDataMember::EType_String64, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_UInt:
                HM_MEMBER(cTkMetaDataMember::EType_UInt, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_UInt16:
                HM_MEMBER(cTkMetaDataMember::EType_UInt16, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_UInt64:
                HM_MEMBER(cTkMetaDataMember::EType_UInt64, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_UInt8:
                HM_MEMBER(cTkMetaDataMember::EType_UInt8, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_UniqueId:
                HM_MEMBER(cTkMetaDataMember::EType_UniqueId, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Vector:
                HM_MEMBER(cTkMetaDataMember::EType_Vector, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Vector2:
                HM_MEMBER(cTkMetaDataMember::EType_Vector2, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_Vector4:
                HM_MEMBER(cTkMetaDataMember::EType_Vector4, currentMember.mpacName);
                break;
            case cTkMetaDataMember::EType_WideChar:
                HM_MEMBER(cTkMetaDataMember::EType_WideChar, currentMember.mpacName);
                break;
            default:
                break;
        }
    }
}

void HeridiumCXXFile::WriteSourceFile() {
    //Todo: this.
}