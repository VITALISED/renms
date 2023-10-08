#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/data/TkClassPointer.h>
#include <toolkit/system/memory/pools/TkLinearMemoryPool.h>
#include <engine/source/shared/utxmlparser.h>

SKYSCRAPER_BEGIN

class cTkMetaDataXMLFunctionLookup
{
public:
    cTkFixedString<64, char> mName;
    void (*mWriteFunction)(const cTkClassPointer *, XMLNode *, bool);
    void (*mReadFunction)(cTkClassPointer *, XMLNode *, cTkLinearMemoryPool *);
    bool (*mSaveFunction)(const cTkClassPointer *, const char *);
};

class cTkMetaDataXML
{
public:
    typedef cTkMetaDataXMLFunctionLookup *(*GetLookup)(const char *lpacName);

    template <class T>
    class Registrar
    {
    public:
        static void ClassPointerRead(cTkClassPointer *lPtr, XMLNode *lDataNode, cTkLinearMemoryPool *lpAllocator);
        static bool ClassPointerSave(const cTkClassPointer *lPtr, const char *lpacFilename);
        static void ClassPointerWrite(const cTkClassPointer *lPtr, XMLNode *lDataNode, bool lbForceShortForm);
        void WriteToXMLNode(XMLNode *lDataNode, bool lbForceShortForm, bool lbGlobal);
    };
};

SKYSCRAPER_END