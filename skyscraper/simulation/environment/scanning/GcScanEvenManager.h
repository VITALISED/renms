/**
 * @file GcScanEvenManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <networking/GcNetworkRpcCall.h>
#include <simulation/environment/scanning/GcScanEvent.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <simulation/gcscaneventsave.meta.h>
#include <simulation/gcscaneventtable.meta.h>
#include <simulation/vehicle/gcvehiclescantable.meta.h>

SKYSCRAPER_BEGIN

class cGcScanEventManager
{
  public:
    cGcRpcCallBase *RRSE;
    float mfNextEventTime;
    bool mbHasBeenToSpace;
    bool mbHasBeenSentToStation;
    bool mbWasInSpace;
    cTkPersonalRNG mRNG;
    cGcScanEventTable *mapTables[8];
    int maiScanEventIndex[8];
    cTkVector<cGcScanEventData *> mapMissionEvents;
    cGcVehicleScanTable *mpVehicleScanTable;
    cTkVector<cGcScanEventData *> mCurrentMissionPool;
    int miNumShipScanEvents;
    int miNumFoundShipScanEvents;
    float mfLastKnownScanTime;
    float mfLastEventScanTime;
    float mfLastScanStartTime;
    bool mbCanDoScanEvents;
    bool mbFirstSystemScan;
    int miVehicleScanIndex;
    cTkVector<cGcScanEvent> mEventStack;
    cTkVector<cGcScanEventSave> maFullEventStack;
    cTkVector<cGcScanEventSave> maEventsPendingSync;
    cTkVector<cGcScanEventSave> maSynchedEvents;
    bool mbNeedsEventStackRefresh;
    bool mbNeedsEventStackReroll;
    bool mbPrepared;
};

SKYSCRAPER_END