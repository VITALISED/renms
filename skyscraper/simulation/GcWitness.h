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

#include <simulation/GcTrackArrowTypes.h>
#include <toolkit/attachments/TkAttachment.h>

#include <simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>

SKYSCRAPER_BEGIN

class cGcWitness
{
    cTkAttachmentPtr mpWitness;
    float mfHearingRange;
    float mfSightRange;
    float mfSightAngle;
    bool mbCanSee;
    bool mbInvestigating;
    float mfLastSightTime;
    ePrimaryAxis meAxis;
    eGcTrackArrowTypes meArrowType;
    float mfArrowTypeChangeTime;
    bool mbPermenant;
    bool (*mPerceptionCallback)(cTkAttachment *, const cTkVector3 *, bool *);
};

SKYSCRAPER_END