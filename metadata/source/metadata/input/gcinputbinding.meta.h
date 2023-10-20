#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/actions/gcinputactions.meta.h>
#include <metadata/utilities/data/tkinputenum.meta.h>
#include <metadata/utilities/data/tkinputaxisenum.meta.h>

class cGcInputBinding
{
    static unsigned long long muNameHash = 0x4A8D0B35C3429A12;
    static unsigned long long muTemplateHash = 0x3A6A47E184830B13;

    cGcInputActions Action;
    cTkInputEnum Button;
    cTkInputAxisEnum Axis;
}
