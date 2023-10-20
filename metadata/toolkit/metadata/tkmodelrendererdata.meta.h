#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkmodelrenderercameradata.meta.h>
enum eThumbnailMode
{
    EThumbnailMode_None = 0,
    EThumbnailMode_HUD = 1,
    EThumbnailMode_GUI = 2,
}

class cTkModelRendererData
{
    static unsigned long long muNameHash = 0x53EC68060BE631FB;
    static unsigned long long muTemplateHash = 0x4B24E25067FB7537;

    cTkModelRendererCameraData Camera;
    float mfFov;
    float mfAspectRatio;
    eThumbnailMode ThumbnailMode;
    eFocusType FocusType;
    TkID<256> mFocusLocator;
    cTkVector3 mFocusOffset;
    float mfFocusInterpTime;
    float mfBlendInTime;
    float mfBlendInOffset;
    TkID<128> mAnim;
    float mfHeightOffset;
    bool mbUsePlayerCameraInHmd;
    bool mbAlignUIToCameraInHmd;
    bool mbUseSensibleCameraFocusNodeIsNowOffsetNode;
    bool mbLookForFocusInMasterModel;
}
