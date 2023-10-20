#pragma once
#include <metadata/metadata_common.h>
enum eWonderCustomCategory
{
    EWonderCustomCategory_Custom01 = 0,
    EWonderCustomCategory_Custom02 = 1,
    EWonderCustomCategory_Custom03 = 2,
    EWonderCustomCategory_Custom04 = 3,
    EWonderCustomCategory_Custom05 = 4,
    EWonderCustomCategory_Custom06 = 5,
    EWonderCustomCategory_Custom07 = 6,
    EWonderCustomCategory_Custom08 = 7,
    EWonderCustomCategory_Custom09 = 8,
    EWonderCustomCategory_Custom10 = 9,
    EWonderCustomCategory_Custom11 = 10,
    EWonderCustomCategory_Custom12 = 11,
}

class cGcWonderCustomCategory
{
    static unsigned long long muNameHash = 0x3ACABCA885CFF7F2;
    static unsigned long long muTemplateHash = 0xB2A2231AC6C1C0E0;

    eWonderCustomCategory WonderCustomCategory;
}
