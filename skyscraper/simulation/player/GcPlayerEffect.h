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

SKYSCRAPER_BEGIN

enum ePlayerEffects
{
	EPlayerEffects_None,
	EPlayerEffects_Enter_Vehicle,
	EPlayerEffects_Exit_Vehicle,
	EPlayerEffects_Size,
	EPlayerEffects_EnableCamo,
	EPlayerEffects_DisableCamo,
	EPlayerEffects_MiniPortalEnter,
	EPlayerEffects_MiniPortalExit,
};

class cGcPlayerEffectsComponent;

class cGcPlayerEffect
{
	cGcPlayerEffectsComponent* mpEffectComponent;
	float mfSpeed;
	bool mbStarted;
	bool mbFinished;

	virtual void Construct();
	virtual void Prepare();
	virtual void Start();
	virtual void Update(const float);
	virtual void End();
	virtual void Release();
	virtual bool FreezePlayerMovement();
};

SKYSCRAPER_END