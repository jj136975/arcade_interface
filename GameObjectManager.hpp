/*
** EPITECH PROJECT, 2021
** GameObjectManager.hpp
** File description:
** header file for the GameObjectManager class
*/

#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_

#include <vector>
#include "GameObject.hpp"

namespace Arcade
{
    /**
     ** \class GameObjectManager
     **/
    class GameObjectManager
    {
    public:
        GameObjectManager(void);
        ~GameObjectManager(void);
        void addGameObject(const AGameObject *gameObject); ///< adds the given game object to the list
        void removeGameObject(const AGameObject *gameObject); ///< removes the given AGameObject
        ///< @param gameObject : AGameObject to be removed from the list
        void clearList(void); ///< clears the list
        const std::vector<AGameObject *> &getGameObjectList(void) const; ///< gets the list of AGameObjects

    private:
        std::vector<AGameObject *> gameObjectsList;
    };

}

#endif
