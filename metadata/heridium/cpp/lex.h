#pragma once

#include "notation.h"

#define HM_BEGIN_BUFFER std::string buffer = "";
#define HM_PRELUDE buffer += "pragma once\n #include <metadata/metadata_common.h>\n\n"
#define HM_CLASS_BEGIN(class_name)  buffer.append("class ").append(class_name).append("\n{\n")
#define HM_CLASS_END buffer.append("}\n");
#define HM_INDENT buffer += "    "

#define HM_DEFINED_MEMBER(lpacType, lpacMember)
#define HM_MEMBER(lpacType, lpacMember) HM_IDENT; lpacType;
#define HM_TEMPLATED_MEMBER(lpacType, lpacInnerType, lpacName)

#define HM_PUSHSTRING(chars) buffer += string;