#include"core/Debug.hpp"

void Debug::log()
{
    std::cout << util::getCurrentTime() << " INFO : " << "Empty Log function called! If enabled, it won't be logged in the logfile." << std::endl;
}
void Debug::log(std::string message, MessageType m_type)
{
    std::string type;
    switch(m_type)
    {
        case INFO: type = " INFO : ";
            break;
        case MESSAGE: type = " MESSAGE : ";
            break;
        case ERROR: type = " ERROR : ";
            break;
        default: type = " UNKNOWN : ";
            break;
    }
    std::cout << util::getCurrentTime() << type << message << std::endl;
    if(_clf) *_logfile << util::getCurrentTime() << type << message << std::endl;
}

bool Debug::_clf = false;

std::ofstream *Debug::_logfile = nullptr;

void Debug::createLogFile(std::ofstream &logfile)
{
    _clf = true;
    if(_clf)
    {
        _logfile = &logfile;   
        std::cout << "LOGGER ENABLED\n";
    }
    else std::cout << "CLF MANUALLY DISABLED\n";
}

std::string Debug::onScreenDebugData(onScreenDD& _dd)
{
    
     return std::string("FPS: " + std::to_string(_dd.FPS)
         + "\nTime(Static): " + std::to_string(_dd.Static_clock_time)
         + "\nTime(Dynamic): " + std::to_string(_dd.Dynamic_clock_time)
         + "\nTimeScale: " + std::to_string(_dd.timeScale)
         + "\nCurrent State: " + _dd.currentState);
    
}