/**
 * @file TkStorageCommon.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <skyscraper.h>

#include <toolkit/system/filesystem/TkFileSystem.h>

SKYSCRAPER_BEGIN

namespace TkStorage
{
struct Blob
{
    void *mpacData;
    unsigned int muDataLength;
    bool mbDeleteDataPtrOnCtor;
};
} // namespace TkStorage

struct CommonStorageUserCred
{
    unsigned __int64 mu64UserID;
    bool mbValidUserID;
};

class cTkSaveDataStreamBase
{
    int miFileOffsetBytes;
    char *mpaChunkBuffer;
    char *mpaCompressedChunkBuffer;
    unsigned int muCompressedChunkBufferSize;
    char *mpStreamPointer;
    char *mpEndStreamPointer;
    int miTotalBytesStreamed;
    int miTotalBytesCompressed;
    eFileOpenMode meStreamMode;
    bool mbCompressed;

    virtual __int64 PlatformReadFile(unsigned __int64, void *, __int64);
    virtual __int64 PlatformWriteFile(unsigned __int64, void *, __int64);
};

SKYSCRAPER_END