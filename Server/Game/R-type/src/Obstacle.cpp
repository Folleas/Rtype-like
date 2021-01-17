/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Obstacle
*/

#include "Obstacle.hpp"

Obstacle::Obstacle(std::string id, float x, float y) : GameObject(id, x, y)
{
    this->_type = GameObjectType::MOB;
    this->_destroy = false;
    this->_speed = 10;
    this->_clock = std::make_unique<Time>(10);
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_clock->checkMilliseconds()) {
        this->_position.x -= this->_speed;
    }
    if (this->_position.x <= 0)
        this->_destroy = true;
}

void Obstacle::event(std::vector<ClientResponse> clientResponses)
{

}


ServerResponse Obstacle::display()
{
    ServerResponse response;

    response.ID = this->_id;
    response.positionX = this->_position.x;
    response.positionY = this->_position.y;
    response.state = 0;
    response.textureID = 4;
    if (this->_destroy)
        response.value = DELETE_DISPLAY_INFO;
    else
        response.value = 0;
    return response;
}

void Obstacle::onTrigger(std::shared_ptr<GameObject> obj)
{
    obj->setDestroyed(true);
}

