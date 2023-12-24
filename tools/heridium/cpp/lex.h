/**
 * @file lex.h
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

#pragma once

#include <chrono>

#include "notation.h"

#define PRELUDE_DOCSTR                                                                                                 \
    "/**\n"                                                                                                            \
    " * @file {}\n"                                                                                                    \
    " * @author VITALISED & Contributors\n"                                                                            \
    " * @since {}\n"                                                                                                   \
    " * @version v{}\n"                                                                                                \
    " * @brief This file is autogenerated metadata created by Heridium for ReNMS. You shouldn't need to modify this, " \
    "see https://github.com/VITALISED/renms.\n"                                                                        \
    " *\n"                                                                                                             \
    " * Copyright (C) 2023  VITALISED & Contributors\n"                                                                \
    " *\n"                                                                                                             \
    " * This program is free software: you can redistribute it and/or modify\n"                                        \
    " * it under the terms of the GNU General Public License as published by\n"                                        \
    " * the Free Software Foundation, either version 3 of the License, or \n"                                          \
    " * (at your option) any later version. \n"                                                                        \
    " *\n"                                                                                                             \
    " * This program is distributed in the hope that it will be useful,\n"                                             \
    " * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"                                              \
    " * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"                                               \
    " * GNU General Public License for more details.\n"                                                                \
    " *\n"                                                                                                             \
    " * You should have received a copy of the GNU General Public License\n"                                           \
    " * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n"                                      \
    " */"

#define HM_BEGIN_BUFFER std::string buffer = ""
#define HM_PRELUDE(lsFile, lsDate, liNMSBuild)                                             \
    std::string __PRELUDE_FMTED = fmt::format(PRELUDE_DOCSTR, lsFile, lsDate, liNMSBuild); \
    buffer.append(__PRELUDE_FMTED);                                                        \
    buffer.append("\n\n#pragma once\n\n#include <toolkit/data/TkMetaDataClasses.h>\n");
#define HM_NAMESPACE_BEGIN buffer += "SKYSCRAPER_BEGIN\n\n";
#define HM_NAMESPACE_END   buffer += "SKYSCRAPER_END\n";
#define HM_CLASS_BEGIN(lpacName)                                         \
    buffer.append("/**\n * @class ").append(lpacName).append("\n */\n"); \
    buffer.append("class ").append(lpacName).append("\n{\n").append("  public:\n")
#define HM_CLASS_END   buffer.append("};\n\n")
#define HM_INDENT      buffer += "    "
#define HM_SEMI        buffer += ";\n"
#define HM_BUFFER_CSTR buffer.c_str()
#define HM_BUFFER      buffer;
#define HM_CONSTVAL(name, value)                                                                            \
    this->msConstBuffers.append("        NO_UNIQUE_ADDRESS const int ki").append(name).append("ArraySize"); \
    this->msConstBuffers.append(";\n")

#define HM_UNION_BEGIN \
    HM_INDENT;         \
    buffer.append("union\n    {\n")
#define HM_UNION_END    \
    HM_INDENT;          \
    buffer.append("}"); \
    HM_SEMI
#define HM_STRUCT_BEGIN \
    HM_INDENT;          \
    HM_INDENT;          \
    buffer.append("struct\n        {\n")
#define HM_STRUCT_END   \
    HM_INDENT;          \
    HM_INDENT;          \
    buffer.append("}"); \
    HM_SEMI

#define HM_BEGIN_ENUM_BUFFER this->msEnumBuffer = "";

#define HM_METHOD_DEF(return_type, name, arguments, empty_body)    \
    HM_INDENT;                                                     \
    buffer.append(return_type);                                    \
    if (!std::string(return_type).empty()) { buffer.append(" "); } \
    buffer.append(name).append(arguments);                         \
    if (empty_body) { buffer.append(" {}\n"); }                    \
    else { buffer.append(";\n"); }

#define HM_ISDEPENDENCYDEFINED(lpacName) \
    (std::find(this->mDefinedTypes.begin(), this->mDefinedTypes.end(), lpacName) != this->mDefinedTypes.end())
// This do-while suppresses a warning about multiple statements on a single line. It turns this into it's own block, but
// it should still work.
#define HM_ADDINCLUDE(lpacPath, lpacName)                           \
    do {                                                            \
        this->mbAddedInclude = true;                                \
        buffer.append("#include <").append(lpacPath).append(">\n"); \
        this->mDefinedTypes.push_back(lpacName);                    \
    } while (0)
#define HM_ENUMNAME(lpacName)     std::string("e").append(lpacName).c_str()
#define HM_FLAGNAME(lpacName)     std::string("ex").append(lpacName).c_str()
#define HM_ENUMNOTATION(lpacName) std::string("E").append(lpacName).c_str()
#define HM_FLAGNOTATION(lpacName) std::string("F").append(lpacName).c_str()

#define HM_ENUM_BEGIN(lpacName, lsType)                                                                            \
    this->msEnumBuffer.append("/**\n * @enum ").append(HM_ENUMNAME(lpacName)).append("\n */\n");                   \
    this->msEnumBuffer.append("enum ").append(HM_ENUMNAME(lpacName)).append(" : ").append(lsType).append("\n{\n"); \
    const char *__enum_id = lpacName
#define HM_ENUM_VAL(lpacName, liValue)                    \
    this->msEnumBuffer.append("    ");                    \
    this->msEnumBuffer.append(HM_ENUMNOTATION(__enum_id)) \
        .append("_")                                      \
        .append(lpacName)                                 \
        .append(" = ")                                    \
        .append(std::to_string(liValue))                  \
        .append(",\n")
#define HM_ENUM_END this->msEnumBuffer.append("};\n\n")

#define HM_FLAG_BEGIN(lpacName, lsType)                                                                            \
    this->msEnumBuffer.append("/**\n * @enum ").append(HM_ENUMNAME(lpacName)).append("\n */\n");                   \
    this->msEnumBuffer.append("enum ").append(HM_FLAGNAME(lpacName)).append(" : ").append(lsType).append("\n{\n"); \
    const char *__flag_id = lpacName
#define HM_FLAG_VAL(lpacName, liValue)                    \
    HM_INDENT;                                            \
    this->msEnumBuffer.append(HM_FLAGNOTATION(__flag_id)) \
        .append("_")                                      \
        .append(lpacName)                                 \
        .append(" = ")                                    \
        .append(std::to_string(liValue))                  \
        .append(",\n")
#define HM_FLAG_END this->msEnumBuffer.append("};\n\n")

#define HM_METADATA_CLASS                                                     \
    HM_INDENT;                                                                \
    HM_INDENT;                                                                \
    buffer.append("NO_UNIQUE_ADDRESS const cTkMetaDataClass mClassMetadata"); \
    HM_SEMI;

#define HM_DEFINED_MEMBER(lpacType, lpacMember)             \
    HM_INDENT;                                              \
    HM_INDENT;                                              \
    HM_INDENT;                                              \
    buffer.append(lpacType).append(" ").append(lpacMember); \
    HM_SEMI
#define HM_MEMBER(lpacType, lpacMember)                       \
    HM_INDENT;                                                \
    HM_INDENT;                                                \
    HM_INDENT;                                                \
    buffer.append(heridium::CXX_MemberTypeToNamed(lpacType))  \
        .append(" ")                                          \
        .append(heridium::CXX_GetNotationForMember(lpacType)) \
        .append(lpacMember);                                  \
    HM_SEMI
#define HM_TEMPLATED_MEMBER(lpacMember)                                                                       \
    HM_INDENT;                                                                                                \
    HM_INDENT;                                                                                                \
    HM_INDENT;                                                                                                \
    buffer.append(heridium::CXX_MemberTypeToNamed(lpacMember.mType)).append(this->GetInnerType(&lpacMember)); \
    buffer.append(">").append(" ").append(heridium::CXX_GetNotationForMember(lpacMember.mType));              \
    buffer.append(lpacMember.mpacName);                                                                       \
    HM_SEMI
#define HM_TEMPLATED_MEMBER_FIXED(lpacMember)                                                                 \
    HM_INDENT;                                                                                                \
    HM_INDENT;                                                                                                \
    HM_INDENT;                                                                                                \
    buffer.append(heridium::CXX_MemberTypeToNamed(lpacMember.mType)).append(this->GetInnerType(&lpacMember)); \
    buffer.append(", ").append(std::to_string(lpacMember.miCount));                                           \
    buffer.append(">").append(" ").append(heridium::CXX_GetNotationForMember(lpacMember.mType));              \
    buffer.append(lpacMember.mpacName);                                                                       \
    HM_SEMI
#define HM_META_MEMBER(lpacMember)                                       \
    HM_INDENT;                                                           \
    HM_INDENT;                                                           \
    buffer.append("NO_UNIQUE_ADDRESS cTkMetaDataMember mMember_");       \
    buffer.append(heridium::CXX_GetNotationForMember(lpacMember.mType)); \
    buffer.append(lpacMember.mpacName);                                  \
    HM_SEMI
#define HM_MEMBER_VAL(lpacType, lpacMember, lpacValue)      \
    HM_INDENT;                                              \
    HM_INDENT;                                              \
    HM_INDENT;                                              \
    buffer.append(lpacType).append(" ").append(lpacMember); \
    buffer.append(" = ").append(lpacValue);                 \
    HM_SEMI

#define TYPEDEF_ENUM_VAL(lpacMember, lpacValue)                \
    HM_INDENT;                                                 \
    buffer.append("enum\n");                                   \
    HM_INDENT;                                                 \
    buffer.append("{\n");                                      \
    HM_INDENT;                                                 \
    HM_INDENT;                                                 \
    buffer.append(lpacMember).append(" = ").append(lpacValue); \
    buffer.append(",\n");                                      \
    HM_INDENT;                                                 \
    buffer.append("};\n")

#define HM_PUSHSTRING(lpacString) buffer += lpacString