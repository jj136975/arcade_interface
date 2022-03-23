/*
** EPITECH PROJECT, 2021
** Time.hpp
** File description:
** header file for the Time class
*/

#ifndef _TIME_H_
#define _TIME_H_

#define INCREASE_TICK 0.01f

namespace Arcade {

    class Time
    {
    public:
        Time(void);
        ~Time(void);
        void startTimer(void); ///< starts the timer, set at 0 by default
        void startTimer(float tick); ///< starts the timer
        ///< @param tick : desired ticks to start at
        void increaseTime(void); ///< increases the ticks of the clock
        ///< this function should be called at the end of the gameloop

        //getters
        float getTicks(void); ///< member function for getting the time

        //setters
        void setTicks(float tick); ///< sets the time of the clock
        ///< @param tick : desired ticks

    private:
        float ticks;
    };

}

#endif
