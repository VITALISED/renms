#pragma once

#define HM_BEGIN_BUFFER std::string buffer = "";
#define HM_PRELUDE buffer += "pragma once\n #include <metadata/metadata_common.h>\n\n"
#define HM_CLASS_BEGIN(class_name)  buffer.append("class ").append(class_name).append("\n{\n")
#define HM_CLASS_END buffer.append("}\n");
#define HM_INDENT buffer += "    "

#define HM_PUSHSTRING(chars) buffer += string;