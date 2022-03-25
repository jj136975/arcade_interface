/*
** EPITECH PROJECT, 2022
** Events.hpp
** File description:
** header file listing all events
*/


namespace Arcade
{
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

    namespace Events
    {
        /*!
        ** \enum Keyboard
        ** The KeyBoard enum's role is to make the key input as generic as possible
        ** This way, we can modify input for every display module we want.
        */
        enum Keyboard {
            A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
            UP, DOWN, LEFT, RIGHT, ESCAPE, SPACE, ENTER, TAB,
            Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
            UNKNOWN
        };

        enum EventType
        {
            KEY_EVENT,
            MOUSE_EVENT,
            WINDOW_RESIZE,
            WINDOW_CLOSE,
        };
        
        struct KeyEvent
        {
            Keyboard key;
            bool pressed;
        };
        
        struct MouseEvent
        {
            VectorXY pos;
            bool pressed;
            bool isRightClick;
        };
        struct WindowResize
        {
            VectorXY prevSize;
            VectorXY size;
        };
        struct WindowClose
        {
            bool close;
        };
        struct Event
        {
            EventType type;
            union eventInfo
            {
                KeyEvent keyEvent;
                MouseEvent mouseEvent;
                WindowResize windowResize;
                WindowClose windowClose;
            } event;
        
        };
    }
}
