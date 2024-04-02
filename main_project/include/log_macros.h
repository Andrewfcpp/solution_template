//Used from "Progrematic" https://www.youtube.com/watch?v=DQCkMnMNFBI ;

#ifdef _MSC_VER
#pragma once
#endif

#ifndef LOG_MACROS_H
#define LOG_MACROS_H



//Using external {fmt} library
#define SPDLOG_FMT_EXTERNAL
#define FMT_HEADER_ONLY
#include "spdlog/spdlog.h"



#define DEFAULT_LOGGER_NAME "spdlogger"

#ifndef NDEBUG //Debug mode, enable logging

#define LOG_TRACE(...) if (spdlog::get(DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__);}
#define LOG_DEBUG(...) if (spdlog::get(DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(DEFAULT_LOGGER_NAME)->debug(__VA_ARGS__);}
#define LOG_INFO(...)  if (spdlog::get(DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(DEFAULT_LOGGER_NAME)->info(__VA_ARGS__);}
#define LOG_WARN(...)  if (spdlog::get(DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(DEFAULT_LOGGER_NAME)->warn(__VA_ARGS__);}
#define LOG_ERROR(...) if (spdlog::get(DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(DEFAULT_LOGGER_NAME)->error(__VA_ARGS__);}
#define LOG_FATAL(...) if (spdlog::get(DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(DEFAULT_LOGGER_NAME)->critical(__VA_ARGS__);}

#else //Release mode, disable logging

#define LOG_TRACE(...) /*NOTHING*/ // (void)0
#define LOG_DEBUG(...) /*NOTHING*/ // (void)0
#define LOG_INFO(...)  /*NOTHING*/ // (void)0
#define LOG_WARN(...)  /*NOTHING*/ // (void)0
#define LOG_ERROR(...) /*NOTHING*/ // (void)0
#define LOG_FATAL(...) /*NOTHING*/ // (void)0

#endif //NDEBUG



#endif