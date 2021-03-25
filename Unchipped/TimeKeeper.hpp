/*************************
Himanshu Parchand - https://himan2104.github.io
A timekeeping library for SFML
Strictly to be used with SFML only
This message may not be removed from any iteration of this code
*************************/
#pragma once
#include<SFML/System.hpp>

class TimeKeeper
{
public:
    enum ClockType
    {
        Static, //Static = clock unaffected by the timescale
        Dynamic //Dynamic = clock that varies with the timescale
    };

    //use this right before your main game loop
    static void initializeTime();

    //returns the deltaTime in float
    static float deltaTime();

    //change the timescale
    /*
    default = 1.0f
    pause = 0.0f
    */
    static void timeScale(float multiplier);

    //call this at the beginning of your main loop
    static void updateTime();

    //get the time elapsed in seconds
    /*
    Static = clock unaffected by the timescale
    Dynamic = clock that varies with the timescale
    */
    static float timeSinceStart(ClockType _type);

    //returns the current timescale
    static float getTimeScale();

    //returns the frametime
    static float frameTime();

    static void resetClock(ClockType _type);

private:
    static sf::Clock* m_GameClock;
    static sf::Clock* m_FrameClock;
    static float m_timeScale;
    static float m_deltaTime;
    static float m_dynamicClockTime;
};
