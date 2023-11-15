#include <scripts/python.h>

void __renms_log(const char *lpacMessage)
{
    std::shared_ptr<spdlog::logger> Logger = spdlog::get(GetScriptLoggerName());
    Logger->info(lpacMessage);
}

PYBIND11_EMBEDDED_MODULE(renms, m)
{
    m.doc() = "ReNMS Bindings";

    m.def("info", &__renms_log, "Binding for spdlog::info, must be const char*");
}

RENMS_BEGIN

void CreateScriptEnvironment()
{
    py::initialize_interpreter();

    try
    {
        // auto renms_logger = py::module_::import("renms");
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