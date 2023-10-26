#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/resources/TkResourceDescriptor.h>

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

class cGcFadeNodeInstance : public cGcFadeNodeBase
{
	class cImposterGenerationData
	{
  		cTkFixedString<512,char> msFullPath;
  		TkHandle mNodeToRender;
  		cTkSmartResHandle mNodeToRenderResource;
  		cTkSmartResHandle mPipelineResource;
  		cTkSmartResHandle mPipelineResourceNormals;
  		cTkSmartResHandle mPipelineResourceMasks;
  		int miPipelineSetRenderTargetPipelineStage;
  		int miPipelineNormalsSetRenderTargetPipelineStage;
  		int miPipelineMasksSetRenderTargetPipelineStage;
  		int miPipelineClearRenderTargetPipelineStage;
  		int miPipelineNormalsClearRenderTargetPipelineStage;
  		int miPipelineMasksClearRenderTargetPipelineStage;
  		int miPipelineDrawPipelineStage;
  		int miPipelineNormalsDrawPipelineStage;
  		int miPipelineMasksDrawPipelineStage;
  		cTkSmartResHandle mDxt5DiffuseTexRes;
  		cTkSmartResHandle mDxt5NormalTexRes;
  		cTkSmartResHandle mDxt5MaskTexRes;
  		cTkSmartResHandle mTempMaterialRes;
  		float mfCentreOffset;
  		float mfAspectRatio;
  		float mfDistance;
  		float mfHeight;
  		float mfOriginalHeight;
  		float mfHeightOffset;
  		float mfImposterWidthMultiplier;
  		float mfWidth;
  		float mfImposterFadeDistance;
  		cTkResourceDescriptor mResourceDescriptor;
  		cTkVector<cTkSmartResHandle> *mpImposterResources;
  		int miRefCount;
  		bool mbAbort;
  		int miImposterGenerationStateIndex;
  		unsigned char meImposterLevelToCapture[1];
	};

  	cTkStackVector<TkHandle> maMeshNodeHandles;
  	TkHandle mTransientRenderNode;
  	int miNumImposterImages;
  	bool mbPrepared;
  	int miWaitingForGeometryStreaming;
  	int miImposterGenerationStateIndex;
  	cGcFadeNodeInstance::cImposterGenerationData *mpGenerationData;
  	cTkVector<cTkSmartResHandle> mImposterResources;
};

SKYSCRAPER_END