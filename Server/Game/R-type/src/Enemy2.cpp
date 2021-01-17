/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Enemy2
*/

#include "Enemy2.hpp"

Enemy2::Enemy2(std::string id, float x, float y) : GameObject(id, x, y)
{
    this->_startingPosition = this->_position;
    this->_destroy = false;
    this->_speed = 3;
    this->_type = GameObjectType::MOB;
    this->_clock = std::make_unique<Time>(10);
    this->_direction = 1;
}

Enemy2::~Enemy2()
{
}

void Enemy2::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_clock->checkMilliseconds()) {
        this->_position.x -= this->_speed;
        if (this->_position.y >= this->_startingPosition.y + 100 || this->_position.y == 1850) {
            this->_direction = -1;
        }
        if (this->_position.y <= this->_startingPosition.y - 100 || this->_position.y == 100) {
            this->_direction = 1;
        }
        this->_position.y -= this->_speed * this->_direction;
    }
    if (this->_position.x <= 0)
        this->_destroy = true;
}

void Enemy2::event(std::vector<ClientResponse> clientResponses)
{

}


ServerResponse Enemy2::display()
{
    ServerResponse response;

    response.ID = this->_id;
    response.positionX = this->_position.x;
    response.positionY = this->_position.y;
    response.state = 0;
    response.textureID = 3;
    if (this->_destroy)
        response.value = DELETE_DISPLAY_INFO;
    else
        response.value = 0;
    return response;
}

void Enemy2::onTrigger(std::shared_ptr<GameObject> obj)
{
    // obj->setDestroyed(true);
}