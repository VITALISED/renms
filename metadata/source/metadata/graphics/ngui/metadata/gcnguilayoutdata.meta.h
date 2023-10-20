#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/ngui/metadata/gcvroverride_layout.meta.h>
#include <metadata/graphics/ngui/metadata/gcaccessibleoverride_layout.meta.h>
#include <metadata/ngui/tknguialignment.meta.h>

class cGcNGuiLayoutData
{
    static unsigned long long muNameHash = 0xCEE71E03D7326B71;
    static unsigned long long muTemplateHash = 0x6BF5030552548903;

    cTkDynamicArray<cGcVROverride_Layout> maVROverrides;
    cTkDynamicArray<cGcAccessibleOverride_Layout> maAccessibleOverrides;
    float mfPositionX;
    float mfPositionY;
    float mfWidth;
    float mfHeight;
    float mfConstrainAspect;
    float mfMaxWidth;
    cTkNGuiAlignment Align;
    bool mbWidthPercentage;
    bool mbHeightPercentage;
    bool mbConstrainProportions;
    bool mbForceAspect;
    bool mbAnchor;
    bool mbAnchorPercent;
    bool mbSameLine;
    bool mbSlowCursorOnHover;
}
