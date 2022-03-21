/*
** EPITECH PROJECT, 2021
** IGameModule.hpp
** File description:
** header file for the IGameModule class
*/

#ifndef _IGAMEMODULE_H_
#define _IGAMEMODULE_H_

#include <string>

#include "IDisplayModule.hpp"
#include "GameObject.hpp"

namespace Arcade {

    /*!
    ** \interface IGameModule
    ** This is an interface containing only pure virtual functions.
    ** The purpose of this class is to manage all data related to its game.
    ** It the passes it to the Arcade class, which the passes the data
    ** to the IDisplayModule class
    **/
    class IGameModule
    {
    public:
        virtual ~IGameModule(void) = default; ///< default destructor
        virtual void init(void) = 0; ///< Class initialization
        virtual void checkKeyState(const std::vector<Keyboard> &keys) = 0; ///< function for checking the state of each key
        ///< We use the Keyboard enum to check if any data needs to be updated.
        ///< The game data will be modified accordingly
        ///< @param keys : array of Keyboard keys
        ///< @see Keyboard for more information
        virtual bool isQuitPressed(void) const = 0; ///< function whose only purpose is to check if the KEYEXIT has been pressed
        ///< Function whose only purpose is to check if the KEYEXIT has been pressed
        ///< @return true if the KEYEXIT has been pressed
        ///< @see Keyboard for more information about the keys
        virtual void updateGameObjects(void) = 0; ///< this function updates the game data if needed
        ///< After checking the keys, the GameObjects will be modified accordingly
        ///< @see GameObject
        virtual const std::vector<GameObject *> &getGameObjects(void) const = 0; ///< returns a vector of GameObjects
        ///< Function to get all game data
        ///< @return vector of pointers to game objects containing the mage data
        ///< @see GameObject
        virtual bool loadFile(const std::string &filepath) = 0; ///< Function to load a map from a filepath
        ///< Function to load a map | configuration filefrom a filepath
        ///< This function has been designed in order to facilitate the loading of game data through
        ///< files.
        ///< Those can be configuration files or just plain data.
        ///< @param filepath : filepath to the map | configuration file
        ///< @return true if the map has been loaded succesfully
    };

}

#endif
