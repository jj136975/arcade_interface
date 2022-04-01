/*
** EPITECH PROJECT, 2021
** IDisplayModule.hpp
** File description:
** header file for the IDisplayModule class
*/

#pragma once

#include <map>
#include <vector>
#include <string>

#include "EventManager.hpp"

namespace Arcade {
    
    enum Colors {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE
    };

    struct Data	{
        Colors color;
        Colors backgroundColor;
        char type;
        std::string texture;
    };

    struct TextData
    {
        std::string text;
        VectorXY pos;
        Colors txt;
        Colors bg;
        int id;
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
        virtual void init(const std::map<char, struct Data> *data, const VectorXY &windowSize) = 0; ///< init function
        virtual void setEventManager(Arcade::EventManager *eventManager) = 0;
        virtual void display(const char *map, const std::vector<TextData> *texts) = 0;
        virtual void start(void) = 0;
        virtual void stop(void) = 0;
        virtual const std::string &getName(void) const = 0;
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
