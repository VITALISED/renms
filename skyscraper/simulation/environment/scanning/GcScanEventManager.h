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

#include <skyscraper.h>
#include <networking/GcRpcCallBase.h>
#include <simulation/environment/scanning/GcScanEvent.h>

SKYSCRAPER_BEGIN

class cGcScanEventManager
{
    cGcRpcCallBase *RRSE;
    float mfNextEventTime;
    bool mbHasBeenToSpace;
    bool mbHasBeenSentToStation;
    bool mbWasInSpace;
    cTkPersonalRNG mRNG;
    cGcScanEventTable *mapTables[8];
    int maiScanEventIndex[8];
    std::vector<cGcScanEventData *,TkSTLAllocatorShim<cGcScanEventData *,8,-1> > mapMissionEvents;
    cGcVehicleScanTable *mpVehicleScanTable;
    std::vector<cGcScanEventData *,TkSTLAllocatorShim<cGcScanEventData *,8,-1> > mCurrentMissionPool;
    int miNumShipScanEvents;
    int miNumFoundShipScanEvents;
    float mfLastKnownScanTime;
    float mfLastEventScanTime;
    float mfLastScanStartTime;
    bool mbCanDoScanEvents;
    bool mbFirstSystemScan;
    int miVehicleScanIndex;
    std::vector<cGcScanEvent,TkSTLAllocatorShim<cGcScanEvent,16,-1> > mEventStack;
    std::vector<cGcScanEventSave,TkSTLAllocatorShim<cGcScanEventSave,16,-1> > maFullEventStack;
    std::vector<cGcScanEventSave,TkSTLAllocatorShim<cGcScanEventSave,16,-1> > maEventsPendingSync;
    std::vector<cGcScanEventSave,TkSTLAllocatorShim<cGcScanEventSave,16,-1> > maSynchedEvents;
    bool mbNeedsEventStackRefresh;
    bool mbNeedsEventStackReroll;
    bool mbPrepared;
};

SKYSCRAPER_END