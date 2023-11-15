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