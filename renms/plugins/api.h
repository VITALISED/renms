#pragma once

#ifdef RENMS
#define RENMS_ENTRY __declspec(dllimport)
#else
#define RENMS_ENTRY __declspec(dllexport)
#endif

#define RENMS_API extern

void RENMS_ENTRY PluginMain();
void RENMS_API   ConstructFSM();

// may want to redefine different functions in stages as