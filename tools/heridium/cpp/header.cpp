/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <spdlog/spdlog.h>

#include "../paths.h"
#include "lang.h"

HeridiumCXXFile::HeridiumCXXFile(const char *lpacFileLocation, const cTkMetaDataClass *lpMetaDataClass)
    : mTargetFile(lpacFileLocation), mpMetaDataClass(lpMetaDataClass)
{
    this->mDefinedTypes = std::vector<const char *>();
    this->WriteHeaderFile();
    // this->WriteSourceFile();
}

std::string HeridiumCXXFile::GetEnumSizeType(int liType)
{
    switch (liType)
    {
    case 1: return "uint8_t";
    case 4: return "uint32_t";
    default: spdlog::error("Unhandled type size {}", liType); return "?";
    }
}

std::string HeridiumCXXFile::DoEnumLookup(cTkMetaDataMember *lpCurrentMember)
{
    HM_BEGIN_BUFFER;

    HM_ENUM_BEGIN(lpCurrentMember->mpacName, this->GetEnumSizeType(lpCurrentMember->miSize));

    for (int i = 0; i < lpCurrentMember->miNumEnumMembers; i++)
    {
        cTkMetaDataEnumLookup lCurrentEnumMember = lpCurrentMember->mpEnumLookup[i];
        HM_ENUM_VAL(lCurrentEnumMember.mpacName, lCurrentEnumMember.miValue);
    }

    HM_ENUM_END;

    return HM_BUFFER;
}

std::string HeridiumCXXFile::DoFlagLookup(cTkMetaDataMember *lpCurrentMember)
{
    HM_BEGIN_BUFFER;

    HM_FLAG_BEGIN(lpCurrentMember->mpacName, this->GetEnumSizeType(lpCurrentMember->miSize));

    for (int i = 0; i < lpCurrentMember->miNumEnumMembers; i++)
    {
        cTkMetaDataEnumLookup lCurrentEnumMember = lpCurrentMember->mpEnumLookup[i];

        if (std::string(lCurrentEnumMember.mpacName).empty()) continue;

        HM_FLAG_VAL(lCurrentEnumMember.mpacName, lCurrentEnumMember.miValue);
    }

    HM_FLAG_END;

    return HM_BUFFER;
}

std::string HeridiumCXXFile::FindIncludePathForClass(const char *lpacClassName)
{
    std::string lsKey = lpacClassName;

    std::transform(lsKey.begin(), lsKey.end(), lsKey.begin(), [](unsigned char c) { return (char)std::tolower(c); });

    for (std::pair<const char *, const char *> lItem : gClassPaths)
    {
        if (lsKey == lItem.first) { return std::string(lItem.second); }
    }

    return "?";
}

std::string HeridiumCXXFile::DoHeaderFirstPass()
{
    HM_BEGIN_BUFFER;

    HM_BEGIN_ENUM_BUFFER;

    for (int i = 0; i < this->mpMetaDataClass->miNumMembers; i++)
    {
        cTkMetaDataMember currentMember = this->mpMetaDataClass->maMembers[i];

        switch (currentMember.mType)
        {
        case cTkMetaDataMember::EType_Class:
            if (!HM_ISDEPENDENCYDEFINED(currentMember.mpClassMetadata->mpacName))
                HM_ADDINCLUDE(
                    FindIncludePathForClass(currentMember.mpClassMetadata->mpacName),
                    currentMember.mpClassMetadata->mpacName);
            break;
        case cTkMetaDataMember::EType_Enum: HM_PUSHSTRING(this->DoEnumLookup(&currentMember)); break;
        case cTkMetaDataMember::EType_Flags: HM_PUSHSTRING(this->DoFlagLookup(&currentMember)); break;
        default: break;
        }

        // we also need to scan inner types as well which is kind of annoying
        switch (currentMember.mInnerType)
        {
        case cTkMetaDataMember::EType_Class:
            if (!HM_ISDEPENDENCYDEFINED(currentMember.mpClassMetadata->mpacName))
                HM_ADDINCLUDE(
                    FindIncludePathForClass(currentMember.mpClassMetadata->mpacName),
                    currentMember.mpClassMetadata->mpacName);
            break;
        case cTkMetaDataMember::EType_Enum: HM_PUSHSTRING(this->DoEnumLookup(&currentMember)); break;
        case cTkMetaDataMember::EType_Flags: HM_PUSHSTRING(this->DoFlagLookup(&currentMember)); break;
        default: break;
        }
    }

    if (this->mbAddedInclude) { HM_PUSHSTRING("\n"); }

    return HM_BUFFER;
}

std::string HeridiumCXXFile::GetInnerType(cTkMetaDataMember *lpCurrentMember)
{
    switch (lpCurrentMember->mInnerType)
    {
    case cTkMetaDataMember::EType_Class: return lpCurrentMember->mpClassMetadata->mpacName;
    case cTkMetaDataMember::EType_Enum: return HM_ENUMNAME(lpCurrentMember->mpacName);
    case cTkMetaDataMember::EType_Flags: return HM_FLAGNAME(lpCurrentMember->mpacName);
    default: return heridium::CXX_MemberTypeToNamed(lpCurrentMember->mInnerType);
    }
}

void HeridiumCXXFile::WriteHeaderFile()
{
    if (!this->mTargetFile.is_open())
    {
        spdlog::error("Failed to open file for writing: {}", this->mpacFileLocation);
        return;
    }

    HM_BEGIN_BUFFER;

    HM_PRELUDE;

    HM_PUSHSTRING(this->DoHeaderFirstPass());

    HM_NAMESPACE_BEGIN;

    HM_PUSHSTRING(this->msEnumBuffer);

    HM_CLASS_BEGIN(this->mpMetaDataClass->mpacName);

    // hashes
    HM_MEMBER_VAL(
        "static const unsigned long long", "muNameHash", fmt::format("0x{:X}", this->mpMetaDataClass->muNameHash));
    HM_MEMBER_VAL(
        "static const unsigned long long", "muTemplateHash",
        fmt::format("0x{:X}", this->mpMetaDataClass->muTemplateHash));

    HM_PUSHSTRING("\n");

    for (int i = 0; i < this->mpMetaDataClass->miNumMembers; i++)
    {
        cTkMetaDataMember currentMember = this->mpMetaDataClass->maMembers[i];
        switch (currentMember.mType)
        {
        case cTkMetaDataMember::EType_Unspecified: break;
        case cTkMetaDataMember::EType_Bool: HM_MEMBER(cTkMetaDataMember::EType_Bool, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Byte: HM_MEMBER(cTkMetaDataMember::EType_Byte, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Class:
            HM_DEFINED_MEMBER(currentMember.mpClassMetadata->mpacName, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_ClassPointer:
            HM_MEMBER(cTkMetaDataMember::EType_ClassPointer, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Colour: HM_MEMBER(cTkMetaDataMember::EType_Colour, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_DynamicArray: HM_TEMPLATED_MEMBER(currentMember); break;
        case cTkMetaDataMember::EType_DynamicString:
            HM_MEMBER(cTkMetaDataMember::EType_DynamicString, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_DynamicWideString:
            HM_MEMBER(cTkMetaDataMember::EType_DynamicWideString, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Enum:
            HM_DEFINED_MEMBER(HM_ENUMNAME(currentMember.mpacName), currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Filename:
            HM_MEMBER(cTkMetaDataMember::EType_Filename, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Flags:
            HM_DEFINED_MEMBER(HM_FLAGNAME(currentMember.mpacName), currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Float: HM_MEMBER(cTkMetaDataMember::EType_Float, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_HalfVector4:
            HM_MEMBER(cTkMetaDataMember::EType_HalfVector4, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Id: HM_MEMBER(cTkMetaDataMember::EType_Id, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Id256: HM_MEMBER(cTkMetaDataMember::EType_Id256, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Int: HM_MEMBER(cTkMetaDataMember::EType_Int, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Int16: HM_MEMBER(cTkMetaDataMember::EType_Int16, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Int64: HM_MEMBER(cTkMetaDataMember::EType_Int64, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Int8: HM_MEMBER(cTkMetaDataMember::EType_Int8, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_LocId: HM_MEMBER(cTkMetaDataMember::EType_LocId, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_NodeHandle:
            HM_MEMBER(cTkMetaDataMember::EType_NodeHandle, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_PhysRelVec:
            HM_MEMBER(cTkMetaDataMember::EType_PhysRelVec, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Resource:
            HM_MEMBER(cTkMetaDataMember::EType_Resource, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Seed: HM_MEMBER(cTkMetaDataMember::EType_Seed, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_StaticArray: HM_TEMPLATED_MEMBER_FIXED(currentMember); break;
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
        case cTkMetaDataMember::EType_UInt: HM_MEMBER(cTkMetaDataMember::EType_UInt, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_UInt16: HM_MEMBER(cTkMetaDataMember::EType_UInt16, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_UInt64: HM_MEMBER(cTkMetaDataMember::EType_UInt64, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_UInt8: HM_MEMBER(cTkMetaDataMember::EType_UInt8, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_UniqueId:
            HM_MEMBER(cTkMetaDataMember::EType_UniqueId, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Vector: HM_MEMBER(cTkMetaDataMember::EType_Vector, currentMember.mpacName); break;
        case cTkMetaDataMember::EType_Vector2:
            HM_MEMBER(cTkMetaDataMember::EType_Vector2, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_Vector4:
            HM_MEMBER(cTkMetaDataMember::EType_Vector4, currentMember.mpacName);
            break;
        case cTkMetaDataMember::EType_WideChar:
            HM_MEMBER(cTkMetaDataMember::EType_WideChar, currentMember.mpacName);
            break;
        default: break;
        }
    }

    HM_CLASS_END;

    HM_NAMESPACE_END;

    const char *lFinal = HM_BUFFER_CSTR;

    this->mTargetFile << lFinal;

    this->mTargetFile.close();
}