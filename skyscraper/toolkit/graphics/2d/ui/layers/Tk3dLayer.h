#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/2d/ui/layers/Tk2dLayer.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

class cTk3dLayer : public cTk2dLayer
{
	enum eDepthTest
	{
		EDepthTest_None,
		EDepthTest_Normal,
		EDepthTest_Inverse,
	};

	cTkVector3 mWorldPosition;
	cTkVector4 mScreenPosition;
	cTkVector4 mScreenPositionLeft;
	cTkVector4 mScreenPositionRight;
	float mfScreenDepth;
	float mfDefaultDistToCamera;
	float mfMinScale;
	float mfMaxScale;
	cTk3dLayer::eDepthTest meTestZ;
	bool mbEnable3d;
	bool mbScale3d;
};

SKYSCRAPER_END