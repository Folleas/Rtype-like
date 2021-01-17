/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "SFMLGraphics.hpp"
#include <iostream>

class EventManager {
    public:
        EventManager();
        ~EventManager();

        ClientResponse manageEvent(std::shared_ptr<Event> event);
        std::vector<std::string> getKeys();
        void setKeys(std::string leftKeyCode, std::string rightKeyCode, std::string upKeyCode, std::string downKeyCode, std::string shootKeyCode, std::string pauseKeyCode);
    protected:
        std::vector<std::string> _keyCodes;
};

#endif /* !EVENTMANAGER_HPP_ */