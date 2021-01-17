/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** PositionManager
*/

#include "PositionManager.hpp"

PositionManager::PositionManager(float x, float y)
{
    this->_position.x = x;
    this->_position.y = y;
    this->_size.x = 100;
    this->_size.y = 100;
}

PositionManager::~PositionManager()
{
}


void PositionManager::setPosition(const float &x, const float &y)
{
    this->_position.x = x;
    this->_position.y = y;
}

void PositionManager::setSize(const float &width, const float &height)
{
    this->_size.x = width;
    this->_size.y = height;
}

Vector2f PositionManager::getPosition() const
{
    return this->_position;
}

Vector2f PositionManager::getSize() const
{
    return this->_size;
}
