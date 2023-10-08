#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct XMLAttribute
{
	const char *lpszName;
	const char *lpszValue;
};

struct XMLClear
{
	const char *lpszValue;
	const char *lpszOpenTag;
	const char *lpszCloseTag;
};

struct XMLNode
{
	struct XMLNodeDataTag
	{
		const char *lpszName;
		int nChild;
		int nText;
		int nClear;
		int nAttribute;
		char isDeclaration;
		XMLNode::XMLNodeDataTag *pParent;
		XMLNode *pChild;
		const char **pText;
		XMLClear *pClear;
		XMLAttribute *pAttribute;
		int *pOrder;
		int ref_count;
	};

	XMLNode::XMLNodeDataTag *d;
};

SKYSCRAPER_END