/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** StateManager
*/

#include "StateManager.hpp"

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

void StateManager::setTrigger(const bool &state)
{
    this->_trigger = state;
}

bool StateManager::isTrigger() const
{
    return this->_trigger;
}

bool StateManager::isDestroyed() const
{
    return this->_destroy;
}

void StateManager::setDestroyed(const bool &state)
{
    this->_destroy = state;
}