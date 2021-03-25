#pragma once
#include<iostream>
#include<fstream>
#include"Utility.hpp"


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

private:
    static std::ofstream* _logfile;
    static bool _clf;
};