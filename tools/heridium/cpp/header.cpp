/**
 * @file header.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-12
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <spdlog/spdlog.h>

#include "../paths.h"
#include "lang.h"

HeridiumCXXFile::HeridiumCXXFile(std::string lpacFileLocation, const cTkMetaDataClass *lpMetaDataClass)
    : mpMetaDataClass(lpMetaDataClass), mTargetFile(lpacFileLocation)
{
    this->mpacFileLocation = lpacFileLocation;
    this->mDefinedTypes    = std::vector<const char *>();
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
        case cTkMetaDataMember::EType_StaticArray: HM_CONSTVAL(currentMember.mpacName, currentMember.miCount); break;
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
        case cTkMetaDataMember::EType_StaticArray: HM_CONSTVAL(currentMember.mpacName, currentMember.miCount); break;
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

std::string HeridiumCXXFile::AddMethodDefinitions()
{
    HM_BEGIN_BUFFER;

    const std::string lsClassName = this->mpMetaDataClass->mpacName;

    HM_PUSHSTRING("    /**\n     * Constructors\n     */\n\n");
    HM_METHOD_DEF("inline", lsClassName, "()", true);

    HM_PUSHSTRING("\n");

    HM_PUSHSTRING("    /**\n     * Methods\n     */\n\n");
    HM_METHOD_DEF("void", "FixDown", "(uint64_t liDynamicOffset)", false);
    HM_METHOD_DEF("void", "FixUp", "(uint64_t liDynamicOffset)", false);
    HM_METHOD_DEF("uint64_t", "GenerateHash", "(uint64_t luHash, bool lbDeep)", false);
    HM_METHOD_DEF("void", "NGuiRender", "()", false);
    HM_METHOD_DEF("void", "ReadFromXMLNode", "(XMLNode &lDataNode, bool lbMergeWithExisting)", false);
    HM_METHOD_DEF("bool", "Save", "(const char *lpacFilename, bool lbClearAllExistingData)", false);
    HM_METHOD_DEF("void", "ValidateData", "()", false);
    HM_METHOD_DEF("void", "SetDefaults", "()", false);
    HM_METHOD_DEF("void", "WriteToClassPtr", "(cTkClassPointer &lClassPtr)", false);
    HM_METHOD_DEF("void", "WriteToXMLNode", "(XMLNode &lDataNode, bool lbForceShortForm, bool lbGlobal)", false);
    HM_PUSHSTRING("\n");

    HM_PUSHSTRING("    /**\n     * Class Pointer Calls\n     */\n\n");
    HM_METHOD_DEF(
        std::string("static ").append(this->mpMetaDataClass->mpacName).append("&"), "Cast",
        "(cTkClassPointer &lClassPtr)", false);
    HM_METHOD_DEF(
        std::string("static const ").append(this->mpMetaDataClass->mpacName).append("&"), "Cast",
        "(const cTkClassPointer &lClassPtr)", false);
    HM_METHOD_DEF(
        "static bool", "ClassPointerCompare", "(const cTkClassPointer &lPtr, const cTkClassPointer &lOtherPtr)", false);
    HM_METHOD_DEF("static void", "ClassPointerCopy", "(cTkClassPointer &lDest, const cTkClassPointer &lSource)", false);
    HM_METHOD_DEF("static cTkClassPointer&", "ClassPointerCreate", "()", false);
    HM_METHOD_DEF(
        "static void", "ClassPointerCreateDefault", "(cTkClassPointer& lPtr, cTkLinearMemoryPool* lpAllocator)", false);
    HM_METHOD_DEF("static void", "ClassPointerDestroy", "(cTkClassPointer &lPtr)", false);
    HM_METHOD_DEF(
        "static void", "ClassPointerFix", "(cTkClassPointer &lPtr, bool lbFixUp, uint64_t liDynamicOffset)", false);
    HM_METHOD_DEF(
        "static uint64_t", "ClassPointerGenerateHash", "(const cTkClassPointer &lPtr, uint64_t luHash, bool lbDeep)",
        false);
    HM_METHOD_DEF(
        "static void", "ClassPointerRead",
        "(cTkClassPointer &lPtr, XMLNode &lDataNode, cTkLinearMemoryPool *lpAllocator)", false);
    HM_METHOD_DEF("static bool", "ClassPointerSave", "(const cTkClassPointer &lPtr, const char *lpacFilename)", false);
    HM_METHOD_DEF("static void", "ClassPointerValidateData", "(cTkClassPointer &lPtr)", false);
    HM_METHOD_DEF(
        "static void", "ClassPointerWrite", "(const cTkClassPointer &lPtr, XMLNode &lDataNode, bool lbForceShortForm)",
        false);

    return HM_BUFFER;
}

void HeridiumCXXFile::WriteHeaderFile()
{
    HM_BEGIN_BUFFER;

    auto now       = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");
    std::string lsFile    = std::filesystem::path(this->mpacFileLocation).filename().string();
    std::string lsDateStr = ss.str();

    HM_PRELUDE(lsFile, lsDateStr, D_NMS_VER);

    HM_PUSHSTRING(this->DoHeaderFirstPass());

    HM_NAMESPACE_BEGIN;

    HM_PUSHSTRING(this->msEnumBuffer);

    HM_CLASS_BEGIN(this->mpMetaDataClass->mpacName);

    TYPEDEF_ENUM_VAL("ClassNameHash", fmt::format("0x{:X}", this->mpMetaDataClass->muNameHash));

    HM_PUSHSTRING("\n");

    HM_PUSHSTRING(this->AddMethodDefinitions());

    HM_PUSHSTRING("\n");

    // HM_UNION_BEGIN;

    // HM_PUSHSTRING(this->msConstBuffers);
    // if (!this->msConstBuffers.empty()) { HM_PUSHSTRING("\n"); }

    // HM_STRUCT_BEGIN;

    HM_PUSHSTRING("    /**\n     * Members\n     */\n\n");

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

    HM_PUSHSTRING("\n");

    // HM_STRUCT_END;

    HM_PUSHSTRING("    /**\n     * Metadata\n     */\n\n");

    for (int i = 0; i < this->mpMetaDataClass->miNumMembers; i++)
    {
        cTkMetaDataMember currentMember = this->mpMetaDataClass->maMembers[i];
        HM_META_MEMBER(currentMember);
    }

    HM_METADATA_CLASS;

    // HM_UNION_END;

    HM_CLASS_END;

    HM_NAMESPACE_END;

    const char *lFinal = HM_BUFFER_CSTR;

    this->mTargetFile << lFinal;

    this->mTargetFile.close();
}