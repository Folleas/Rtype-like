/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** DisplayInfo
*/

#include "DisplayInfo.hpp"

DisplayInfo::DisplayInfo(std::size_t ID, std::size_t textureID, std::size_t value, Vector2i position, std::size_t state)
{
    this->_ID = ID;
    this->_textureID = textureID;
    this->_value = value;
    this->_position = position;
    this->_state = state;
}

DisplayInfo::~DisplayInfo()
{
}

void DisplayInfo::setID(const std::size_t &ID)
{
    this->_ID = ID;
}

void DisplayInfo::setTextureID(const std::size_t &textureID)
{
    this->_textureID = textureID;
}

void DisplayInfo::setPosition(const std::size_t &positionX, const std::size_t &positionY)
{
    this->_position.x = positionX;
    this->_position.y = positionY;
}

void DisplayInfo::setState(const std::size_t &state)
{
    this->_state = state;
}

void DisplayInfo::setValue(const std::size_t &value)
{
    this->_value = value;
}

std::size_t DisplayInfo::getValue() const
{
    return this->_value;
}

std::size_t DisplayInfo::getTextureID() const
{
    return this->_textureID;
}

Vector2i DisplayInfo::getPosition() const
{
    return this->_position;
}

std::size_t DisplayInfo::getID() const
{
    return this->_ID;
}

std::size_t DisplayInfo::getState() const
{
    return this->_state;
}
