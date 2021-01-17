/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Animated
*/

#include "Animated.hpp"

Animated::Animated(std::string id, std::vector<std::string> paths, float x, float y, float delay) : GameObject(id, x, y)
{
    this->_time = std::make_shared<Time>(delay);
    this->_paths = paths;
    this->_spriteDisplayed = 0;
}

Animated::~Animated()
{
}

void Animated::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_time->checkSeconds()) {
        if (_spriteDisplayed < this->_paths.size() - 1)
            _spriteDisplayed++;
        else
            _spriteDisplayed = 0;
    }
}

void Animated::event(std::vector<ClientResponse> clientResponses)
{
    return;
}

ServerResponse Animated::display()
{
    ServerResponse response;
    return response;
}

void Animated::onTrigger(std::shared_ptr<GameObject> obj)
{
}
