#pragma once

#ifdef RENMS // don't define this if you're a plugin dev
#define RENMS_API __declspec(dllimport)
#else
#define RENMS_API __declspec(dllexport)
#endif

void RENMS_API PluginMain();