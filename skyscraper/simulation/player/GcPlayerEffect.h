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