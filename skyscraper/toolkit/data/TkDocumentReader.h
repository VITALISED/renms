/**
 * @file TkDocumentReader.h
 * @author VITALISED & Contributors
 * @since 2024-01-22
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <toolkit/data/TkMetaDataClasses.h>

SKYSCRAPER_BEGIN

class ITkDocumentReader
{
  public:
    enum ReadResult;

    virtual ~ITkDocumentReader();
    virtual TkID<128> &GetReaderFormat();
    virtual void PushContext(const char *);
    virtual void PopContext();
    virtual ITkDocumentReader::ReadResult MoveCursor(const char *);
    virtual ITkDocumentReader::ReadResult MoveCursor(const unsigned int);
    virtual ITkDocumentReader::ReadResult PopCursor();
    virtual bool IsCursorNull();
    virtual ITkDocumentReader::ReadResult ReadArraySize(unsigned int *);
    virtual ITkDocumentReader::ReadResult ReadStringSize(unsigned int *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkDynamicWideString *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkDynamicString *);
    virtual ITkDocumentReader::ReadResult ReadValue(TkHandle *);
    virtual ITkDocumentReader::ReadResult ReadValue(unsigned int *);
    virtual ITkDocumentReader::ReadResult ReadValue(uint16_t *);
    virtual ITkDocumentReader::ReadResult ReadValue(int *);
    virtual ITkDocumentReader::ReadResult ReadValue(int16_t *);
    virtual ITkDocumentReader::ReadResult ReadValue(char *);
    virtual ITkDocumentReader::ReadResult ReadValue(uint8_t *);
    virtual ITkDocumentReader::ReadResult ReadValue(char **);
    virtual ITkDocumentReader::ReadResult ReadValue(float *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkSeed *);
    virtual ITkDocumentReader::ReadResult ReadValue(TkID<256> *);
    virtual ITkDocumentReader::ReadResult ReadValue(TkID<128> *);
    virtual ITkDocumentReader::ReadResult ReadValue(uint64_t *);
    virtual ITkDocumentReader::ReadResult ReadValue(int64_t *);
    virtual ITkDocumentReader::ReadResult ReadValue(bool *);
    virtual ITkDocumentReader::ReadResult ReadValue(const wchar_t **);
    virtual ITkDocumentReader::ReadResult ReadValue(const char **);
    virtual ITkDocumentReader::ReadResult ReadValue(long double *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkHalfVector4 *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkVector2 *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkVector3 *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkVector4 *);
    virtual ITkDocumentReader::ReadResult ReadValue(cTkPhysRelVec3 *);

    enum ReadResult
    {
        InvalidCursor,
        CursorOverflow,
        CursorUnderflow,
        InvalidArrayIndex,
        KeyNotFound,
        TypeMismatch,
        InnerTypeMismatch,
        UnexpectedArraySize,
        IncompleteTypeData,
        Success,
    };
};

SKYSCRAPER_END