/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** PlayerControler
*/

#include "PlayerControler.hpp"

PlayerControler::PlayerControler()
{
    this->_isShooting = false;
    this->_direction.x = 0;
    this->_direction.y = 0;
    this->_isPaused = false;
}

PlayerControler::~PlayerControler()
{

}

void PlayerControler::computeInput(ClientResponse clientResponse)
{
    if (clientResponse.id == this->_playerNb) {
        if (clientResponse.horizontal == LEFT) {
            this->_direction.x = -1;
        }
        else if (clientResponse.horizontal == RIGHT)
            this->_direction.x = 1;
        else
            this->_direction.x = 0;
        if (clientResponse.vertical == DOWN)
            this->_direction.y = 1;
        else if (clientResponse.vertical == UP)
            this->_direction.y = -1;
        else
            this->_direction.y = 0;
        if (clientResponse.other == SHOOT)
            this->_isShooting = true;
        else
            this->_isShooting = false;
        if (clientResponse.other == PAUSE)
            this->_isPaused = true;
        else
            this->_isPaused = false;
    }
}

std::vector<std::string> PlayerControler::getKeys()
{
    return this->_keyCodes;
}

void PlayerControler::setKeys(std::string leftKeyCode, std::string rightKeyCode, std::string upKeyCode, std::string downKeyCode, std::string shootKeyCode, std::string pauseKeyCode)
{
    this->_keyCodes.push_back(leftKeyCode);
    this->_keyCodes.push_back(rightKeyCode);
    this->_keyCodes.push_back(upKeyCode);
    this->_keyCodes.push_back(downKeyCode);
    this->_keyCodes.push_back(shootKeyCode);
    this->_keyCodes.push_back(pauseKeyCode);
}
