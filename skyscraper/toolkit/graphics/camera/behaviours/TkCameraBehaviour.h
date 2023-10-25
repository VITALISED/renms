#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/camera/TkCameraManager.h>
#include <toolkit/graphics/camera/TkCamera.h>

SKYSCRAPER_BEGIN

class cTkCameraBehaviour
{
	cTkCameraManager* mpCameraManager;

	virtual ~cTkCameraBehaviour();
	virtual void Construct();
	virtual void Setup();
	virtual bool Prepare(cTkCamera*, cTkCameraManager*);
	virtual void Update(float, cTkCamera*);
	virtual bool Release();
	virtual void Destruct();
	virtual void Transform(const cTkMatrix34*);
};

SKYSCRAPER_END