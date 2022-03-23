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
        VectorXY &operator+=(const VectorXY &vector) const; ///< += operator
        ///< @param vector : other vector to add from
        VectorXY &operator-=(const VectorXY &vector) const; ///< -= operator
        ///< @param vector : other vector to substract from
        VectorXY &operator+(const VectorXY &vector) const; ///< + operator
        ///< @param vector : other vector to add from
        VectorXY &operator-(const VectorXY &vector) const; ///< - operator
        ///< @param vector : other vector to substract with
        VectorXY &operator=(const VectorXY &vector) const; ///< = operator
        ///< @param vector : other vector to copy from

        int x; ///< int value x
        int y; ///< int value y
    };

    /**
     ** \struct Pixel
     ** This structure contains pixel information
     **/
    struct Pixel
    {
        unsigned char r; ///< red
        unsigned char g; ///< green
        unsigned char b; ///< blue
        char c; ///< type or alpha
    };

    /**
     ** \union pixelData
     ** The union is provided to facilitate the pixel customization
     ** Each member of the Pixel struct will be converted to
     ** an unsigned int data
     **/
    union pixelData
    {
        unsigned int data; ///< converted data
        struct Pixel pixel; ///< pixel data
    };

    enum GameType {
        EMPTY,
        SPRITE,
        ANIMATED_SPRITE,
        TEXT,
        PIXEL
        // GEOMETRY,
        //CUSTOM_SPRITE
    };

    /**
     ** \class GameObject
     ** This class will contain all the nessesary data to make a simple game object.
     ** This includes it's position, and its type
     ** We made this class canonical, so it will be easier to manipulate your objects
     ** by making copies.
     **/
    class AGameObject
    {
    public:
        AGameObject(void) = delete; ///< default constructor
        ///< the position will be at (0,0) by default
        AGameObject(const VectorXY &position, GameType type = EMPTY); ///< construct you class with it's position
        ///< @param position : the position at which we want the GameObject to be initialized.
        ///< @see VectorXY
        AGameObject(const AGameObject &old); ///< copy constructor
        ///< @param old : the GameObject to be copied
        ~AGameObject(void);

        //getters
        const VectorXY &getPosition(void) const; ///< gets the current position of the given GameObject
        ///< @see VectorXY
        GameType getType(void) const; ///< gets the GameObject type
        ///< you are free to do wathever you want with it. This is just to make it easier to distinguish
        ///< certain game objects from others

        //setters
        void setPosition(const VectorXY &newPosition); ///< sets the coordinates of the GameObject at the desired position
        ///< @param newPosition : position you want the GameObject to be at
        ///< @see VectorXY
        void setPosition(int x, int y); ///< sets the coordinates of the GameObject at the desired position
        ///< @param x : x position you want the GameObject to be at
        ///< @param y : y position you want the GameObject to be at

        void setActive(bool); ///< change the GameObject state
        bool isActive(void); ///< gets the GameObjects state
        //operators
        AGameObject &operator=(const AGameObject &gameObject); ///< copy operator
        ///< @param gameObject : the GameObject we want to copy

    private:
        VectorXY position;
        GameType type;
        bool active;
    };

}

// union pixel_data px = 5;

// px.pixel.c = 97;

#endif
