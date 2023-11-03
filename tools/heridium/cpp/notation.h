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

#pragma once

#include "../heridium.h"
#include <cassert>
#include <toolkit/data/TkMetaDataClasses.h>

using namespace nms;

HERIDIUM_BEGIN

constexpr const char *CXX_MemberTypeToNamed(cTkMetaDataMember::eType leType)
{
    switch (leType)
    {
    case cTkMetaDataMember::EType_Unspecified:
        return "auto"; // this should error on most compilers but just in case anyway.
    case cTkMetaDataMember::EType_Bool: return "bool";
    case cTkMetaDataMember::EType_Byte: return "unsigned char";
    case cTkMetaDataMember::EType_Class: return ""; // we resolve classnames elsewhere
    case cTkMetaDataMember::EType_ClassPointer: return "cTkClassPointer";
    case cTkMetaDataMember::EType_Colour: return "cTkColour";
    case cTkMetaDataMember::EType_DynamicArray: return "cTkDynamicArray<";
    case cTkMetaDataMember::EType_DynamicString: return "cTkDynamicString";
    case cTkMetaDataMember::EType_DynamicWideString: return "cTkDynamicWideString";
    case cTkMetaDataMember::EType_Enum: return "";
    case cTkMetaDataMember::EType_Filename: return "cTkFixedString<128,char>";
    case cTkMetaDataMember::EType_Flags: return "";
    case cTkMetaDataMember::EType_Float: return "float";
    case cTkMetaDataMember::EType_HalfVector4: return "cTkHalfVector4"; // might be wrong, just a guess
    case cTkMetaDataMember::EType_Id: return "TkID<128>";
    case cTkMetaDataMember::EType_Id256: return "TkID<256>";
    case cTkMetaDataMember::EType_Int: return "int";
    case cTkMetaDataMember::EType_Int16: return "short";
    case cTkMetaDataMember::EType_Int64: return "long long";
    case cTkMetaDataMember::EType_Int8: return "char";
    case cTkMetaDataMember::EType_LocId: return "TkID<256>";
    case cTkMetaDataMember::EType_NodeHandle: return "TkHandle";
    case cTkMetaDataMember::EType_PhysRelVec: return "cTkPhysRelVec3";
    case cTkMetaDataMember::EType_Resource: return "cTkSmartResHandle";
    case cTkMetaDataMember::EType_Seed: return "cTkSeed";
    case cTkMetaDataMember::EType_StaticArray: return "cTkFixedArray<";
    case cTkMetaDataMember::EType_String1024: return "cTkFixedString<1024,char>";
    case cTkMetaDataMember::EType_String128: return "cTkFixedString<128,char>";
    case cTkMetaDataMember::EType_String2048: return "cTkFixedString<2048,char>";
    case cTkMetaDataMember::EType_String256: return "cTkFixedString<256,char>";
    case cTkMetaDataMember::EType_String32: return "cTkFixedString<32,char>";
    case cTkMetaDataMember::EType_String512: return "cTkFixedString<512,char>";
    case cTkMetaDataMember::EType_String64: return "cTkFixedString<64,char>";
    case cTkMetaDataMember::EType_UInt: return "unsigned int";
    case cTkMetaDataMember::EType_UInt16: return "unsigned short";
    case cTkMetaDataMember::EType_UInt64: return "unsigned long long";
    case cTkMetaDataMember::EType_UInt8: return "unsigned char";
    case cTkMetaDataMember::EType_UniqueId: return "cTkNetworkID";
    case cTkMetaDataMember::EType_Vector: return "cTkVector3";
    case cTkMetaDataMember::EType_Vector2: return "cTkVector2";
    case cTkMetaDataMember::EType_Vector4: return "cTkVector4";
    case cTkMetaDataMember::EType_WideChar: return "wchar_t*";
    default:
        assert("Heridium_CXX_MemberTypeToNamed: hit default, this is considerably bad in all honesty");
        return "foil";
    }
}

constexpr const char *CXX_GetNotationForMember(cTkMetaDataMember::eType leType)
{
    // we prepend the notation mostly for parity with class dumps from ida.
    switch (leType)
    {
    case cTkMetaDataMember::EType_Unspecified:
        return "m"; // highly likely this can get called in a future update adding some sort of new type, better this
                    // than nothing
    case cTkMetaDataMember::EType_Bool: return "mb";
    case cTkMetaDataMember::EType_Byte: return "m";
    case cTkMetaDataMember::EType_Class: return "m";
    case cTkMetaDataMember::EType_ClassPointer: return "m";
    case cTkMetaDataMember::EType_Colour: return "m";
    case cTkMetaDataMember::EType_DynamicArray: return "ma";
    case cTkMetaDataMember::EType_DynamicString: return "mac";
    case cTkMetaDataMember::EType_DynamicWideString: return "mac";
    case cTkMetaDataMember::EType_Enum: return "me";
    case cTkMetaDataMember::EType_Filename: return "mac";
    case cTkMetaDataMember::EType_Flags: return "mex";
    case cTkMetaDataMember::EType_Float: return "mf";
    case cTkMetaDataMember::EType_HalfVector4: return "m";
    case cTkMetaDataMember::EType_Id: return "m";
    case cTkMetaDataMember::EType_Id256: return "m";
    case cTkMetaDataMember::EType_Int: return "mi";
    case cTkMetaDataMember::EType_Int16: return "mi";
    case cTkMetaDataMember::EType_Int64: return "mi64";
    case cTkMetaDataMember::EType_Int8: return "mi";
    case cTkMetaDataMember::EType_LocId: return "m";
    case cTkMetaDataMember::EType_NodeHandle: return "m";
    case cTkMetaDataMember::EType_PhysRelVec: return "m";
    case cTkMetaDataMember::EType_Resource: return "m";
    case cTkMetaDataMember::EType_Seed: return "m";
    case cTkMetaDataMember::EType_StaticArray: return "ma";
    case cTkMetaDataMember::EType_String1024: return "mac";
    case cTkMetaDataMember::EType_String128: return "mac";
    case cTkMetaDataMember::EType_String2048: return "mac";
    case cTkMetaDataMember::EType_String256: return "mac";
    case cTkMetaDataMember::EType_String32: return "mac";
    case cTkMetaDataMember::EType_String512: return "mac";
    case cTkMetaDataMember::EType_String64: return "mac";
    case cTkMetaDataMember::EType_UInt: return "mui";
    case cTkMetaDataMember::EType_UInt16: return "mui";
    case cTkMetaDataMember::EType_UInt64: return "mui64";
    case cTkMetaDataMember::EType_UInt8: return "mui";
    case cTkMetaDataMember::EType_UniqueId: return "m"; // not sure about this one
    case cTkMetaDataMember::EType_Vector: return "m";
    case cTkMetaDataMember::EType_Vector2: return "m";
    case cTkMetaDataMember::EType_Vector4: return "m";
    case cTkMetaDataMember::EType_WideChar: return "mac";
    default:
        assert("Heridium_CXX_GetNotationForMember: hit default, this is considerably bad in all honesty");
        return "foil";
    }
}

HERIDIUM_END