/*
** EPITECH PROJECT, 2021
** Arcade.hpp
** File description:
** header file for the Arcade class
*/

namespace Arcade {
/*! \mainpage The golden Arcade game engine
**
** \section intro_sec Introduction
**
** We focused on ease of usage and simplicity when developping our game engine.
** You won't be able to develop complex games but you will be able to develop simple games
** with fast and easily.
** We gave read access to the private members in the documentation.
** We provided you with all the documentation you needenjoy.
** Feedback and optimizations are appreciated.
**
** \section Composition
** Our engine is composed with several classes, namespaces, enums, structures and templates.
** These are listed below
**
** \subsection namespace_sect Namespaces
** We put our whole game engine in the Arcade namespace in order to avoid
** confusion if other libraries are being used with this one.
**
** \subsection classes_sect Classes
** Our library comes with several classes who will help you finish this project.
** - Arcade.Arcade
** - IGameModule
** - IDisplayModule
** - Time
** - FpsLimiter
**
** \subsection template_sect Templates
** We provided you with a template class who will load the libraries automatically for you.
** @see DLLoader
**
** \subsection struct_sect Structures
** There is only one structure provided in this engine.
** All the nessesary information is documented:
** @see VectorXY
**
** \subsection enum_sect Enumerations
** We made our own Keyboard type:
** @see Keyboard
** 
** \section architecture_sec Architecture
** This is the sequence diagram of our architecture.
** \image html arcade_seq.png
** \image latex arcade_seq.eps
**
** \section ressource_sect Ressources
** Some ressources who justify the implementation of certain classes
** and gave some ideas. Feel free to take a look.
** - Timesteps: https://www.gafferongames.com/post/fix_your_timestep/
** - Game dev:  http://gameprogrammingpatterns.com/contents.html
**
** \section authors_sect Authors
** This article was written by:
** @author Santana Graham
** @author Vindevogel Victor
**/
}

#ifndef _ARCADE_H_
#define _ARCADE_H_

#include <vector>

#include "IGameModule.hpp"
#include "IDisplayModule.hpp"
#include "Time.hpp"
#include "FpsLimiter.hpp"
#include "DLLoader.hpp"

/*!
** \namespace Arcade
** \section arcade_sec The Arcade namespace.
** We put our whole game engine in the Arcade namespace in order to avoid
** confusion if other libraries are being used with this one.
**/
namespace Arcade {

    /*!
    ** \class Arcade
    ** The Arcade class will manage the whole game loop.
    ** It contains all the functions you need to make everything work smoothly.
    ** You have total access to private members with the getters and setters.
    **/
    class Arcade
    {
    public:
        Arcade(void);
        ~Arcade(void);
        void init(void); ///< Initialization
        void registerEvents(void); ///< Calls the eventHandler from the current IDisplayModule to log events
                                   ///< @see eventHandler
                                   ///< @see IDisplayModule
        void updateKeys(void); ///< calls the getKeys from IDisplayModule and passes it to checkKeyState from IGameModule
                               ///< @see IDisplayModule @see IGameModule
        bool isQuitPressed(void); ///< calls the isQuitPressed from IGameModule and updates isRunning if nessesary
                                  ///< @see isQuitPressed @see IGameModule @see isRunning
        void draw(void); ///< gets all GameObjects and passes the data to the draw function @see GameObject
        void setFpsLimiter(int fps); ///< function to configure the FPS of the main game loop
        ///< @param fps : Desired FPS

        //getters
        std::vector<IGameModule *> &getIGameModuleList(void); ///< List containing all IGameModules @see IGameModule
        std::vector<IDisplayModule *> &getIDisplayModuleList(void); ///< List containing all IDisplayModules @see IDisplayModule
        bool getState(void); ///< Get the member who will start and stop the game loop
        std::size_t getGameIndex(void); ///< Index of gameModules vector @see getIGameModuleList
        std::size_t getDisplayIndex(void); ///< Index of gameModules @see getIDisplayModuleList
        Time &getTimer(void); ///< Gets the internal clock of the main gameloop
        ///< @see Time
        FpsLimiter &getFpsLimiter(void); ///< Gets the FpsLimiter to initialize it and let it do the work later
        ///< @see FpsLimiter

        //setters
        void addIGameModule(const IGameModule *newGameModule); ///< Adds a new IGameModule to the gameModules list
        ///< @param newGameModule : the IGameModule to be added
        ///< @see IGameModule @see getIGameModuleList
        void addIDisplayModule(const IDisplayModule *newDisplayModule); ///< adds a new IDisplayModule to the displayModules list
        ///< @param newDisplayModule : the IDisplayModule to be added
        ///< @see IDisplayModule @see getIDisplayModuleList
        void setState(bool state); ///< sets the gameloop state
        ///< @param state : state of the gameloop
        void setGameIndex(std::size_t index); ///< sets the index of the IGameModule list
        ///< This has the effect of swapping the game
        ///< @param index : desired index to be switched on
        void setDisplayIndex(std::size_t index); ///< sets the index of the IDisplayModule list
        ///< This has the effect of swapping the graphical environment
        ///< @param index : desired index to be switched on

    private:
        std::vector<IGameModule *> gameModules;
        std::vector<IDisplayModule *> displayModules;
        bool state;
        std::size_t gameIndex;
        std::size_t displayIndex;
        Time timer;
        FpsLimiter fpsLimiter;
        DLLoader<IGameModule> gameModuleLoader;
        DLLoader<IDisplayModule> displayModuleLoader;
    };

}

#endif
