#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dObject.h>
#include <toolkit/utilities/TkArray.h>

SKYSCRAPER_BEGIN

enum eTkBlendMode
{
	EBlendMode_None,
	EBlendMode_Normal,
	EBlendMode_Additive,
	EBlendMode_Subtractive,
	EBlendMode_SourceRGBIsAlpha,
	EBlendMode_EngineBlend,
	EBlendMode_EngineAdd,
	EBlendMode_EngineMult,
	EBlendMode_EngineBlend_OutputOneMinusAlpha,
	EBlendMode_EngineBlend_OutputAlpha,
	EBlendMode_EngineAdd_OutputOneMinusAlpha,
	EBlendMode_InvSourceAlpha,
	EBlendMode_SourceAlpha,
	EBlendMode_RgbOnly,
	EBlendMode_AlphaOnly,
	EBlendMode_Num = 15,
};

class cTk2dLayer : public cTk2dObject
{
	cTkBitArray<unsigned __int64, 512> mBitArray;
	eTkBlendMode meBlendMode;
	cTk2dObject* mpFirstChild;
	bool mbIsVisible;
	bool mbDynamicSize;
	cTkVector2 mScale;
	float mfAngle;
};

SKYSCRAPER_END