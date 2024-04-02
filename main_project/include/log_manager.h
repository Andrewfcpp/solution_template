//Used from "Progrematic" https://www.youtube.com/watch?v=DQCkMnMNFBI ;

#ifdef _MSC_VER
#pragma once
#endif

#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H



class LogManager
{
public:

    LogManager() = default;
    ~LogManager() = default;

    void init();
    void shutdown();
};



#endif