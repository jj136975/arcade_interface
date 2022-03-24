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
#include "GameObjectManager.hpp"

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
        virtual void setEventManager(const Arcade::EventManager *eventManager) = 0;
        virtual void start(void) = 0; ///< starts/stops the game
        virtual char *getMap(void) const = 0;
        virtual bool isGameOver(void) const = 0;
        virtual int getScore(void) const = 0;
        virtual std::map<char, struct Data> &getConfig(void);
        virtual void restart(void) = 0; ///< restarts the game
        virtual void pause(void) = 0; ///< pauses the game
        ///< @return true if the KEYEXIT has been pressed
        ///< @see Keyboard for more information about the keys
        virtual void update(void) = 0; ///< this function updates the game data if needed
    };

}

#endif
