/*
** EPITECH PROJECT, 2021
** IDisplayModule.hpp
** File description:
** header file for the IDisplayModule class
*/

#ifndef _IDISPLAYMODULE_H_
#define _IDISPLAYMODULE_H_

#include <map>
#include <vector>

#include "EventManager.hpp"

namespace Arcade {

    struct Data	{
	int color;
	int backgroundColor;
        char type;
        void *texture;
    };
    /*!
    ** \interface IDisplayModule
    ** This is an interface class containing pure virual functions.
    ** It contains the functions to make every renderer generically.
    ** Some functions aren't nessesary for all renderers, this interface was
    ** designed to be modulable.
    **/
    class IDisplayModule
    {
    public:
        virtual ~IDisplayModule(void) = default; ///< default destructor
        virtual void init(std::map<char, struct Data> &data) = 0; ///< init function
        virtual void setEventManager(const Arcade::EventManager *eventManager) = 0;
        virtual void display(char *map) const = 0;
        virtual void start(void) = 0;
        virtual void stop(void) = 0;
        virtual void clear(void) = 0; ///< clears the screen
        ///< The draw function needs all the data coming from IGameModule in order to render it on the screen.
        ///< The Arcade class is responsible for passing the data between the two classes.
        virtual void setWindowSize(int x, int y) = 0;
        virtual void setWindowSize(const VectorXY size) = 0; ///< sets the window size for the renderer
        ///< The purpose of this function it to set all window sizes generically.
        ///< Ideally, it should be used in the init function.
        ///< Some renderers won't need this function
        ///< @param size : the dimensions of the window, x representing its width and y representing its height
        ///< @see VectorXY
    };

}

#endif
