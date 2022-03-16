#pragma once
#include<iostream>
#include<fstream>
#include"core/Utility.hpp"


struct onScreenDD
{
    float FPS;
    float Static_clock_time;
    float Dynamic_clock_time;
    float timeScale;
    std::string currentState;
};

class Debug
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

    static std::string onScreenDebugData(onScreenDD& _dd);

private:
    static std::ofstream* _logfile;
    static bool _clf;
};