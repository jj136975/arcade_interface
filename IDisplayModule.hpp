/*
** EPITECH PROJECT, 2021
** IDisplayModule.hpp
** File description:
** header file for the IDisplayModule class
*/

#ifndef _IDISPLAYMODULE_H_
#define _IDISPLAYMODULE_H_

#include <vector>

#include "GameObjectManager.hpp"
#include "GameObject.hpp"
#include "EventManager.hpp"

namespace Arcade {

    /*!
    ** \enum Keyboard
    ** The KeyBoard enum's role is to make the key input as generic as possible.
    ** This way, we can modify input for every display module we want.
    */
    enum Keyboard {
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        UP, DOWN, LEFT, RIGHT, ESCAPE, SPACE, ENTER, TAB,
        Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9
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
        virtual void init(void) = 0; ///< init function
        virtual void setEventManager(const Arcade::EventManager *eventManager) = 0;
        virtual void setGameObjectManager(const Arcade::GameObjectManager *gameObjectManager) = 0;
        virtual void display(void) const = 0;
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
