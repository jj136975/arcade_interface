/*
** EPITECH PROJECT, 2021
** EventManager.hpp
** File description:
** header file for the EventManager class
*/

#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include <vector>
#include <memory>

#include "Events.hpp"

namespace Arcade
{

    class EventManager
    {
    public:
        EventManager(void); ///< default constructor
        ~EventManager(void); ///< destructor
        void pushEvent(Events::Event *event); ///< pushes a new event
        ///< @param event : event to be pushed
        Events::Event popEvent(void); ///< pops an event from the queue
        ///< @return the first event of the queue
        bool hasEvent(void); ///< checks if there are still events remaining in the queue
        void clearEvents(void); ///< removes all events from the events vector
        bool hasQuite(void) const; ///< Check if a quite signal has been sent
        void setQuite(bool status); ///< Set the quite status
    private:
        std::vector<Events::Event> events;
        bool quitStatus;
    };

}
#endif
