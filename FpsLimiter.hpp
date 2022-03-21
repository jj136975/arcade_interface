/*
** EPITECH PROJECT, 2021
** FpsLimiter.hpp
** File description:
** header file for the FpsLimiter class
*/

#ifndef _FPSLIMITER_H_
#define _FPSLIMITER_H_

namespace Arcade {

    /**
     ** @class FpsLimiter
     ** This class will provide the nessesary functions to be able to
     ** control and slow down the main gameloop
     ** For more information about why we included this class
     ** visit:
     ** https://www.gafferongames.com/post/fix_your_timestep/
     */
    class FpsLimiter
    {
    public:
        FpsLimiter(void);
        ~FpsLimiter(void);

        void setMaxFps(float fps); ///< set the desired FPS
        ///< this function should be called upon initialization
        ///< @param fps : desired fps
        void beginCompute(float startTicks); ///< stores the actual ticks at the beginning of the loop
        ///< this function should be called at the beginning of the loop
        ///< @param startTicks : the ticks you get with the timer class
        ///< @see Time
        float endCompute(float actualTicks); ///< makes the nessesary steps to slow down the main gameloop
        ///< this function should be called at the end of the main gameloop
        ///< @param actualTicks : the ticks you get with the timer class
        ///< @see Time

    private:
        void computeFps(float actualTicks); ///< this function should be called at the beginning of endCompute
        ///< @param actualTicks : the ticks you get with the timer class
        ///< @see Time
    private:
        unsigned int startTicks;
        float fps;
        float frameTime;
        float maxFps;
    };

}

#endif
