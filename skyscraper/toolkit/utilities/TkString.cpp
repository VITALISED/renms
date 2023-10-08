#include "TkString.h"

SKYSCRAPER_BEGIN

template <unsigned int size, typename T>
void cTkFixedString<size, T>::Copy(const char* lpacBuffer)
{
	strcpy_s(macBuffer, size, lpacBuffer);
}

SKYSCRAPER_END