/**
 * @file TkAudioManagerWwise.h
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

SKYSCRAPER_BEGIN

struct TkAudioID
{
    const char *mpacName;
    unsigned int muID;
    bool mbValid;
};

struct TkAudioObject
{
    unsigned __int64 mID;
};

class cTkAudioStreamFormat
{
    unsigned int miSampleRate;
    bool mbStereo;
    unsigned int miBitsPerSample;
    unsigned int miBytesPerFrame;
    bool mbFloatData;
};

class ITkAudioStream
{
    virtual ~ITkAudioStream();
    virtual void GetAudioStreamFormat(cTkAudioStreamFormat *);
    virtual void GetAudioStreamData(const unsigned int, unsigned int *);
};

SKYSCRAPER_END