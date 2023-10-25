#pragma once

#include <skyscraper.h>
#include <toolkit/system/TkMemoryManager.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/simulation/physics/havok/TkRigidBodyGameplayFlags.h>
#include <toolkit/system/thread/TkRegionThreadManager.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

SKYSCRAPER_BEGIN

class cTkContactPoint
{
	cTkRigidBodyPtr mpHitBody;
	cTkPhysRelVec3 mvContactPoint;
	cTkVector3 mvContactNormal;
	int miMaterial;
	int miSubIndex;
	float mfDistance;
	float mfFraction;
	bool mbIsFresh;
	bool mbIsBodyA;
	unsigned __int8 muRayHitFlags;
};

class cTkRaycastJob
{
	struct Contact
	{
		cTkPhysRelVec3 mvPosition;
		cTkVector3 mvNormal;
		unsigned int miHitBody;
		float mfHitFraction;
		unsigned __int16 miHitMaterial;
		unsigned __int8 muRayHitFlags;
	};

	struct Ray
	{
		cTkPhysRelVec3 mvFrom;
		cTkPhysRelVec3 mvTo;
		unsigned int mIgnoreBodyIdInt;
		unsigned int miFilter;
		cTkRaycastJob::Contact mFirstContact;
		cTkRaycastJob::Contact* mExtraContacts;
		unsigned __int16 miNumContacts;
		unsigned __int16 miMaxContacts;
		float mfRadius;
		eTkRigidBodyGameplayFlags mxIgnoreGameplayFlags;
		bool mbAllowBackfaces;
		bool mbAllowInsideHits;
		bool mbIgnoreCameraInvisible;
		unsigned int mFirstShapeKey;
	};

	struct Status
	{
		bool mbKicked;
		bool mbWaited;
		bool mbPausable;
		eTkMemType meMemoryPool;
		TkJobHandle mJobHandle;
		cTkRaycastJob::Ray* maRays;
		int miNumRays;
		const char* mpFile;
		const char* mpFunc;
		int miLine;
	};

	cTkRaycastJob::Status* maStatus;
	unsigned int miNumJobs;
	cTkRaycastJob::Ray* maRays;
	int miNumRays;
	bool mbConstructed;
	unsigned __int64 miFrameNum;
	eTkMemType meMemoryPool;
};

SKYSCRAPER_END