/**
 * @file TkClock.h
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

class cTkClock
{
    unsigned __int64 mu64StartTime;
    unsigned __int64 mu64CurrentTime;
    unsigned __int64 muLastWaitTicksFinish;
    float mfTimeStep;
    float mfTotalTime;
    float mfPrevTotalTime;
    float mfSlowMotionFactor;
    unsigned __int64 muFrameCount;
    bool mbMinFrameTimeSynced;
    bool mbPaused;
    bool mbRealtime;
};

SKYSCRAPER_END