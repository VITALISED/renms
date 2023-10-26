#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkHandle.h>

SKYSCRAPER_BEGIN

enum eFadeState
{
	EFade_In,
	EFade_Out,
	EFade_Visible,
	EFade_Hidden,
};

enum eFadeType
{
	FadeInThenFadeOut,
	CrossFade,
};

class cGcFadeNodeBase
{
	float mfTimer;
	float mfTotalTime;
	int miNodeParam;
	int miNodeSetIndex;
	eFadeState meFadeState;
	eFadeType meFadeType;

	virtual void SetNodeActivation(bool);
	virtual void CheckNodeActivation(bool);
	virtual void SetNodeParamF(float);
	virtual bool Update();
};

class cGcFadeNode : public cGcFadeNodeBase
{
	TkHandle mNode;
};

SKYSCRAPER_END