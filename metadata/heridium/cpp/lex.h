#pragma once

#include "notation.h"

#define HM_BEGIN_BUFFER std::string buffer = "";
#define HM_PRELUDE buffer += "pragma once\n #include <metadata/metadata_common.h>\n\n"
#define HM_CLASS_BEGIN(lpacName)  buffer.append("class ").append(lpacName).append("\n{\n")
#define HM_CLASS_END buffer.append("}\n");
#define HM_INDENT buffer += "    "
#define HM_SEMI buffer += ";\n"

#define HM_DEFINED_MEMBER(lpacType, lpacMember)
#define HM_MEMBER(lpacType, lpacMember) HM_INDENT; buffer.append(heridium::CXX_MemberTypeToNamed(lpacType)) \
                                        .append(" ").append(heridium::CXX_GetNotationForMember(lpacType)) \
                                        .append(lpacMember); HM_SEMI

#define HM_TEMPLATED_MEMBER(lpacType, lpacInnerType, lpacName)
#define HM_MEMBER_VAL(lpacType, lpacMember, lpacValue)  HM_INDENT; buffer.append(lpacType).append(" ").append(lpacMember); \
                                                        buffer.append(" = ").append(lpacValue); HM_SEMI 


#define HM_PUSHSTRING(chars) buffer += string;