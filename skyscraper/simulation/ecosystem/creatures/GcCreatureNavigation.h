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
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/animation/utils/TkIKSolver.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>

SKYSCRAPER_BEGIN

class cGcCreatureCogConstraint : public cTkIKCenterOfGravityConstraint
{
	cGcCreatureNavTrail* mpNavTrail;
	cTkPhysRelMat34 mModelMat;
	ePrimaryAxis meAxis;
};

class cGcCreaturePelvisConstraint : public cTkIKRotYModifyConstraint
{
	cGcCreatureNavTrail* mpNavTrail;
	cTkPhysRelMat34 mModelMat;
	ePrimaryAxis meAxis;
};

class cGcCreatureNavTrail
{
	cTkVector3 mTrailElts[64];
	cTkVector3 mvOffset;
	cTkVector3 mvFrontFootPos;
	int miNumElts;
	int miIntervalCounter;
	float mfScale;
	float mfFade;
	float mfFadeTarget;
};

SKYSCRAPER_END
