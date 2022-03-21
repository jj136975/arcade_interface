/*
** EPITECH PROJECT, 2021
** GameObject.hpp
** File description:
** header file for the GameObject class
*/

#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <string>

namespace Arcade {

    /**
     ** \struct VectorXY
     ** This structure contains x and y member
     ** to hold game object coordinates
     ** You are provided with overloaded operators which are going to facilitate
     ** certain comparisons.
     */
    struct VectorXY {
        bool operator==(const VectorXY &vector) const; ///< == operator
        ///< @param vector : other vector to compare with
        bool operator!=(const VectorXY &vector) const; ///< != operator
        ///< @param vector : other vector to compare with
        bool operator+=(const VectorXY &vector) const; ///< += operator
        ///< @param vector : other vector to add from
        bool operator-=(const VectorXY &vector) const; ///< -= operator
        ///< @param vector : other vector to substract from
        bool operator+(const VectorXY &vector) const; ///< + operator
        ///< @param vector : other vector to add from
        bool operator-(const VectorXY &vector) const; ///< - operator
        ///< @param vector : other vector to substract with
        bool operator=(const VectorXY &vector) const; ///< = operator
        ///< @param vector : other vector to copy from

        int x; ///< int value x
        int y; ///< int value y
    };

    struct Pixel
    {
        byte r;
        byte g;
        byte b;
        char c;
    };

    union pixel_data
    {
        unsigned int data;
        struct Pixel pixel;
    };

    /**
     ** \class GameObject
     ** This class will contain all the nessesary data to make a simple game object.
     ** This includes it's position, and its type
     ** We made this class canonical, so it will be easier to manipulate your objects
     ** by making copies.
     **/
    class GameObject
    {
    public:
        GameObject(void); ///< default constructor
        ///< the position will be at (0,0) by default
        GameObject(const VectorXY &position, const std::string &name = ""); ///< construct you class with it's position
        ///< @param position : the position at which we want the GameObject to be initialized.
        ///< @see VectorXY
        GameObject(const GameObject &old); ///< copy constructor
        ///< @param old : the GameObject to be copied
        ~GameObject(void);

        //getters
        const VectorXY &getPosition(void) const; ///< gets the current position of the given GameObject
        ///< @see VectorXY
        char getType(void) const; ///< gets the GameObject type
        ///< you are free to do wathever you want with it. This is just to make it easier to distinguish
        ///< certain game objects from others
        std::string &getName(void); ///< get the name of the object
        ///< @return Name of the object
        ///< the game object's name could be used for a variety of things, for example drawing
        ///< the player's name on the screen. Its main purpose
        ///< is to display information with the use of fonts
        ///< @see IDisplayModule for more information about the fonts

        //setters
        void setPosition(const VectorXY &newPosition); ///< sets the coordinates of the GameObject at the desired position
        ///< @param newPosition : position you want the GameObject to be at
        ///< @see VectorXY
        void setPosition(int x, int y); ///< sets the coordinates of the GameObject at the desired position
        ///< @param x : x position you want the GameObject to be at
        ///< @param y : y position you want the GameObject to be at
        void setType(char type); ///< sets the type of a certain GameObject
        ///< @param type : new type to be set
        void setName(const std::string &name); ///< sets the game object name
        ///< the game object's name could be used for a variety of things, for example drawing
        ///< the player's name on the screen. Its main purpose
        ///< is to display information with the use of fonts
        ///< @param name : the objects new name
        ///< @see IDisplayModule for more information about the fonts

        //operators
        GameObject &operator=(GameObject &gameObject); ///< copy operator
        ///< @param gameObject : the GameObject we want to copy

    private:
        VectorXY position;
        char type;
        std::string name;
    };

}

// union pixel_data px = 5;

// px.pixel.c = 97;

#endif
