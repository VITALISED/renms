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

#include "lex.h"
#include "notation.h"
#include "../heridium.h"

class HeridiumCXXFile
{
    std::ofstream mTargetFile;
    const char* mpacFileLocation;
    const cTkMetaDataClass* mpMetaDataClass;
    std::vector<const char*> mDefinedTypes;
    
public:
    std::string FindIncludePathForClass(const char* lpacClassName);
    std::string DoEnumLookup(cTkMetaDataMember* lpCurrentMember);
    std::string DoFlagLookup(cTkMetaDataMember* lpCurrentMember);
    std::string DoHeaderFirstPass();
    std::string GetInnerType(cTkMetaDataMember* lpCurrentMember);
    void WriteHeaderFile();
    void WriteSourceFile();

    HeridiumCXXFile(const char* lpacFileLocation, const cTkMetaDataClass* lpMetaDataClass);
};