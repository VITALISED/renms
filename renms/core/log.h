#pragma once

#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#define MAX_LOG_FILESIZE (1024 * 1024 * 10) // 10mb

inline std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> ConsoleSink()
{
    return std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
};
inline std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> FileSink()
{
    return std::make_shared<spdlog::sinks::rotating_file_sink_mt>("renms.log", MAX_LOG_FILESIZE, 3);
};

#ifdef _DEBUG
inline void SetConsoleSinkParams(std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink)
{
    console_sink->set_level(spdlog::level::debug);
};
#else  //!_DEBUG
inline void SetConsoleSinkParams(std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink)
{
    console_sink->set_level(spdlog::level::info);
};
#endif //_DEBUG

inline void CreateLogger(const char *lpacLoggerName)
{
    std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> file_sink   = FileSink();
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink = ConsoleSink();

    SetConsoleSinkParams(console_sink);
    file_sink->set_level(spdlog::level::debug);
    spdlog::set_default_logger(
        std::make_shared<spdlog::logger>(lpacLoggerName, spdlog::sinks_init_list({console_sink, file_sink})));
};