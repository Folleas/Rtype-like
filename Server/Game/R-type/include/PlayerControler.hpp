/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** PlayerControler
*/

#ifndef PLAYERCONTROLER_HPP_
#define PLAYERCONTROLER_HPP_

#include <vector>
#include "SFMLGraphics.hpp"
#include <iostream>
#include "Types.hpp"

class PlayerControler {
    public:
        PlayerControler();
        ~PlayerControler();

        void computeInput(ClientResponse clientResponse);

        std::vector<std::string> getKeys();
        void setKeys(std::string leftKeyCode, std::string rightKeyCode, std::string upKeyCode, std::string downKeyCode, std::string shootKeyCode, std::string pauseKeyCode);
    protected:
        std::size_t _playerNb;
        Vector2i _direction;
        bool _isShooting;
        bool _isPaused;
        std::vector<std::string> _keyCodes;
};

#endif /* !PLAYERCONTROLER_HPP_ */