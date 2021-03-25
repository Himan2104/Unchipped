#pragma once
#include<iostream>
#include<fstream>
#include"Utility.hpp"

struct onScreenDD
{
    float FPS;
    float Static_clock_time;
    float Dynamic_clock_time;
    float timeScale;
    std::string currentState;
};

class Debug : sf::NonCopyable
{
public:
    enum MessageType
    {
        INFO,
        MESSAGE,
        ERROR
    };
    static void log();
    static void log(std::string message, MessageType m_type = MessageType::MESSAGE);

    static void createLogFile(std::ofstream& logfile);

    static std::string onScreenDebugData(onScreenDD& _dd)
    {
        return std::string("FPS: " + std::to_string(_dd.FPS)
            + "\nTime(Static): " + std::to_string(_dd.Static_clock_time)
            + "\nTime(Dynamic): " + std::to_string(_dd.Dynamic_clock_time)
            + "\nTimeScale: " + std::to_string(_dd.timeScale)
            + "\nCurrent State: " + _dd.currentState);
    }

private:
    static std::ofstream* _logfile;
    static bool _clf;
};