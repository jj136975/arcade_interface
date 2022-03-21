/*
** EPITECH PROJECT, 2021
** IDisplayModule.hpp
** File description:
** header file for the IDisplayModule class
*/

#ifndef _IDISPLAYMODULE_H_
#define _IDISPLAYMODULE_H_

#include <vector>

#include "GameObject.hpp"

namespace Arcade {

    /*!
    ** \enum Keyboard
    ** The KeyBoard enum's role is to make the key input as generic as possible.
    ** This way, we can modify input for every display module we want.
    */
    enum Keyboard {
	KEYPREVLIB      = 1,    ///< key for switching to the previous lib
        KEYNEXTLIB      = 2,    ///< key for switching to the next lib
        KEYPREVGAME     = 4,    ///< key for switching to the previous game
        KEYNEXTGAME     = 8,    ///< key for switching to the next game
        KEYRESTARTGAME  = 16,   ///< key for restarting the game
        KEYMENU         = 32,   ///< key to go back to the main menu
        KEYEXIT         = 64,   ///< key for exiting the program
        KEYFORWARD      = 128,  ///< key for moving the player forward
        KEYBACKWARD     = 256,  ///< key for moving the player backward
        KEYLEFT         = 512,  ///< key for moving the player left
        KEYRIGHT        = 1024  ///< key for moving the player right
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
        virtual void eventHandler(void) = 0; ///< function for catching events called from the main loop
        virtual const std::vector<Keyboard> &getKeys(void) const = 0; ///< function to send the updated Keyboard to the main loop
        ///< The purpose of this function is to facilitate the transmission of the data from IDisplayModule to the Arcade class
        ///< @return vector containing all key information
        ///< @see Arcade
        virtual void draw(const std::string &map) const = 0;
        ///< The draw function needs all the data coming from IGameModule in order to render it on the screen.
        ///< The Arcade class is responsible for passing the data between the two classes.
        ///< @param map : map of pixels to be drawn on the screen
        virtual void draw(const std::vector<GameObject *> &drawData) const = 0; ///< the draw function to render everything on screen
        ///< The draw function needs all the data coming from IGameModule in order to render it on the screen.
        ///< The Arcade class is responsible for passing the data between the two classes.
        ///< @param drawData : Contains x and y positions for drawing the object on the screen and its type so we
        ///< don't get confused between each object
        ///< @see GameObject @see Arcade @see IGameModule
        virtual void draw(const std::vector<GameObject *> &drawData, const std::string &map) const = 0; ///< the draw function to render everything on screen
        ///< The draw function needs all the data coming from IGameModule in order to render it on the screen.
        ///< The Arcade class is responsible for passing the data between the two classes.
        ///< @param drawData : the game objects will have special attributes that we can handle
        ///< @param map : map of pixels to be drawn on the screen
        ///< @see GameObject @see Arcade @see IGameModule
        virtual void setWindowSize(const VectorXY &size) = 0; ///< sets the window size for the renderer
        ///< The purpose of this function it to set all window sizes generically.
        ///< Ideally, it should be used in the init function.
        ///< Some renderers won't need this function
        ///< @param size : the dimensions of the window, x representing its width and y representing its height
        ///< @see VectorXY
        virtual void setSquareSize(int size) = 0; ///< sets the size of each square on screen
        ///< Since our engine only renders squares, we provided a function to set its size on the screen.
        ///< Ideally, it should be used in the init function.
        ///< Some renderers won't need this function
        ///< @param size : the width AND heigth for each square
        virtual bool loadFontSet(void) = 0; ///< function to load a fontset if needed
        ///< Some renderers need a fontset to load in order to be able to display characters on screen.
        ///< Since the renderer is the only one who can do that we made it possible to manage
        ///< fonts in this class.
        ///< @return true if the fontset was successfully loaded.
    };

}

#endif
