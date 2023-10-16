#pragma once

#define HM_BEGIN_BUFFER std::string buffer = "";
#define HM_PRAGMA buffer += "pragma once\n"
#define HM_CLASS(class_name)  buffer += "class " + #class_name + "\n{\n"
#define HM_IDENT buffer += "    "

#define HM_PUSHSTRING(chars) buffer += string;