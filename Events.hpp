/*
** EPITECH PROJECT, 2022
** Events.hpp
** File description:
** header file listing all events
*/


namespace Arcade
{
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
            Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9
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
            Keys key;
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
