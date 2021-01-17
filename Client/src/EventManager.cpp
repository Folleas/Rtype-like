/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** EventManager
*/

#include "EventManager.hpp"

EventManager::EventManager()
{
    this->setKeys("Q", "D", "Z", "S", "X", "C");
}

EventManager::~EventManager()
{
}

void EventManager::setKeys(std::string leftKeyCode, std::string rightKeyCode, std::string upKeyCode, std::string downKeyCode, std::string shootKeyCode, std::string pauseKeyCode)
{
    this->_keyCodes.push_back(leftKeyCode);
    this->_keyCodes.push_back(rightKeyCode);
    this->_keyCodes.push_back(upKeyCode);
    this->_keyCodes.push_back(downKeyCode);
    this->_keyCodes.push_back(shootKeyCode);
    this->_keyCodes.push_back(pauseKeyCode);
}

ClientResponse EventManager::manageEvent(std::shared_ptr<Event> event)
{
    ClientResponse clientResponse;
    clientResponse.horizontal = 0;
    clientResponse.vertical = 0;
    clientResponse.other = 0;

    if (event->isPressed(this->_keyCodes.at(Keys::Left))) {
        clientResponse.horizontal = LEFT;
    }
    else if (event->isPressed(this->_keyCodes.at(Keys::Right)))
        clientResponse.horizontal = RIGHT;
    else
        clientResponse.horizontal = UNDEFINED;
    if (event->isPressed(this->_keyCodes.at(Keys::Down)))
        clientResponse.vertical = DOWN;
    else if (event->isPressed(this->_keyCodes.at(Keys::Up)))
        clientResponse.vertical = UP;
    else
        clientResponse.vertical = UNDEFINED;
    if (event->isPressed(this->_keyCodes.at(Keys::Shoot)))
        clientResponse.other = SHOOT;
    else
        clientResponse.other = UNDEFINED;
    if (event->isPressed(this->_keyCodes.at(Keys::Pause)))
        clientResponse.other = PAUSE;
    return clientResponse;
}