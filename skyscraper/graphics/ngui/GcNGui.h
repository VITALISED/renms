#pragma once

#include <skyscraper.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <toolkit/graphics/ngui/TkNGuiInput.h>
#include <toolkit/graphics/2d/ui/layers/Tk3dLayer.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dImage.h>

SKYSCRAPER_BEGIN

class cGcNGui
{
	cGcNGuiLayer mRoot;
	cTkNGuiInput mInput;
	bool mbUseInput;
	float mfPixelRatio;
	bool mbFullscreen;
	cTkVector2 mCustomSize;
	bool mbHasCustomSize;
	bool mbIsInWorld;
	cTk3dLayer mTk3dLayer;
	cTk2dImage mTk2dImage;
};

SKYSCRAPER_END