#include "TimeKeeper.hpp"


sf::Clock* TimeKeeper::m_GameClock = new sf::Clock();
sf::Clock* TimeKeeper::m_FrameClock = new sf::Clock();

float TimeKeeper::m_deltaTime = 0.0f;

float TimeKeeper::m_timeScale = 1.0f;

float TimeKeeper::m_dynamicClockTime = 0.0f;

void TimeKeeper::initializeTime()
{
    m_GameClock->restart().asSeconds();
    m_FrameClock->restart().asSeconds();
}

void TimeKeeper::timeScale(float multiplier)
{
    m_timeScale = multiplier;
}

void TimeKeeper::updateTime()
{
    m_deltaTime = m_FrameClock->getElapsedTime().asSeconds();
    m_FrameClock->restart().asSeconds();
    m_dynamicClockTime += m_deltaTime * m_timeScale;
}

float TimeKeeper::timeSinceStart(ClockType _type)
{
    if (_type == ClockType::Static) return m_GameClock->getElapsedTime().asSeconds();
    else  return m_dynamicClockTime;
}

float TimeKeeper::deltaTime()
{
    return m_deltaTime * m_timeScale;
}

float TimeKeeper::getTimeScale()
{
    return m_timeScale;
}

float TimeKeeper::frameTime()
{
    return m_deltaTime;
}

void TimeKeeper::resetClock(ClockType _type)
{
    if (_type == Static) m_GameClock->restart().asSeconds();
    else if (_type == Dynamic) m_dynamicClockTime = 0;
}