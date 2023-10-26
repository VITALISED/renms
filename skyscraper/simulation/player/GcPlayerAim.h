#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkAttachment.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

class cGcPlayerAimTarget
{
	cTkPhysRelVec3 mPoint;
	cTkVector3 mNormal;
	int miMaterial;
	cTkRigidBodyPtr mpBody;
	cTkAttachmentPtr mpAttachment;
};

class cGcPlayerAim
{
	cGcPlayer* mpPlayer;
	cGcPlayerAimTarget mLookTarget;
	cGcPlayerAimTarget mShootTarget;
	cTkAttachmentPtr mpAutoAimTarget;
	cTkPhysRelVec3 mAutoAimIntercept;
	cTkVector3 mAutoAimPos;
	float mfAutoAimWeight;
};

SKYSCRAPER_END