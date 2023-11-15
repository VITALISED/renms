#pragma once

#include <renms.h>

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

#include <filesystem>

using namespace std::filesystem;

namespace py = pybind11;

void __renms_log(const char *lpacMessage);

RENMS_BEGIN

void CreateScriptEnvironment();
void ExecutePythonFile(path lFilePath);

RENMS_END