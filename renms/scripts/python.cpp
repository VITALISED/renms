/**
 * @file python.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <scripts/python.h>

void __renms_log(const char *lpacMessage)
{
    std::shared_ptr<spdlog::logger> Logger = spdlog::get(GetScriptLoggerName());
    Logger->info(lpacMessage);
}

void __renms_debug(const char *lpacMessage)
{
    std::shared_ptr<spdlog::logger> Logger = spdlog::get(GetScriptLoggerName());
    Logger->debug(lpacMessage);
}

void __renms_warn(const char *lpacMessage)
{
    std::shared_ptr<spdlog::logger> Logger = spdlog::get(GetScriptLoggerName());
    Logger->warn(lpacMessage);
}

void __renms_error(const char *lpacMessage)
{
    std::shared_ptr<spdlog::logger> Logger = spdlog::get(GetScriptLoggerName());
    Logger->error(lpacMessage);
}

PYBIND11_EMBEDDED_MODULE(renms, m)
{
    m.doc() = "ReNMS Bindings";

    m.def("info", &__renms_log, "Binding for spdlog::info");
    m.def("debug", &__renms_debug, "Binding for spdlog::debug");
    m.def("warn", &__renms_warn, "Binding for spdlog::warn");
    m.def("error", &__renms_error, "Binding for spdlog::error");
}

RENMS_BEGIN

void CreateScriptEnvironment()
{
    py::initialize_interpreter();

    try
    {
        py::exec("import renms\nrenms.info(\"Calling spdlog from Py.\")");
    }
    catch (py::error_already_set const &pythonErr)
    {
        spdlog::error(pythonErr.what());
    }
}

void ExecutePythonFile(path lFilePath)
{
    try
    {
        py::eval_file(lFilePath.string());
    }
    catch (py::error_already_set const &pythonErr)
    {
        spdlog::error(pythonErr.what());
    }
}

RENMS_END