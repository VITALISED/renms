#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/actions/gcinputactions.meta.h>
#include <metadata/utilities/input/tktriggerfeedbackdata.meta.h>

class cGcTriggerFeedbackState
{
    static unsigned long long muNameHash = 0x6310315CF52D5A45;
    static unsigned long long muTemplateHash = 0x776D4FC8EF2794A4;

    TkID<128> mId;
    cGcInputActions Action;
    cTkTriggerFeedbackData Data;
}
