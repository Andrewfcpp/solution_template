
#include "log_macros.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "log_manager.h"

#include <memory>
#include <vector>



void LogManager::init()
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    //"[2024-01-01 12:22:33.12345678] Message..." - Msg format example
    //console_sink->set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] %v%$"); //Milliseconds
    console_sink->set_pattern("%^[%Y-%m-%d %H:%M:%S.%f] %v%$"); //Microseconds
    //console_sink->set_pattern("%^[%Y-%m-%d %H:%M:%S.%F] %v%$"); //Nanoseconds

    std::vector<spdlog::sink_ptr> sinks{ console_sink };
    auto logger = std::make_shared<spdlog::logger>(DEFAULT_LOGGER_NAME, sinks.begin(), sinks.end());
    logger->set_level(spdlog::level::trace);
    logger->flush_on(spdlog::level::trace);
    spdlog::register_logger(logger);
}



void LogManager::shutdown()
{
    spdlog::shutdown();
}
