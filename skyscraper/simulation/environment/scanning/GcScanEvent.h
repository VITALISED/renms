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
#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/system/TkAddNodesHandle.h>

SKYSCRAPER_BEGIN

class cGcScanEvent
{
    typedef enum TkAddNodesHandle::eState eState;

    eScanTable meTable;
    __declspec(align(16)) cGcMarkerPoint mMarker;
    cGcScanEventData *mpEvent;
    cGcBuilding *mpBuilding;
    bool mbMissionSurveyPositionRecalculated;
    cGcScanEvent::eState meEventState;
    float mfEventTimer;
    float mfTooltipTimer;
    float mfEmergencyEndTimer;
    float mfTimedEventLength;
    float mfTimedEventLengthCurrent;
    bool mbIconShown;
    bool mbMessageShown;
    bool mbTooltipShown;
    bool mbCompletionMessageShown;
    bool mbSurveyArrivalMessageShown;
    bool mbTriggered;
    cTkAttachmentPtr mpEncounterOverride;
    int miEncounterOverrideFrameCount;
    cTkAttachmentPtr mpForcedInteraction;
    int miForceInteractionFrameCount;
    cTkClassPoolHandle mResourceOverride;
};

SKYSCRAPER_END