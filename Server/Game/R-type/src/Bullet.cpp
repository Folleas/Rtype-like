/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Bullet
*/

#include "Bullet.hpp"

Bullet::Bullet(std::string id, float x, float y) : GameObject(id, x, y)
{
    static int i = 0;
    this->_id = i++;
    if (i >= 100)
        i = 0;
    this->_destroy = false;
    this->_speed = 20;
    this->_clock = std::make_unique<Time>(10);
    this->setSize(37, 32);
}

Bullet::~Bullet()
{
}

void Bullet::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_position.x >= 1920 || this->_position.x < 10) {
        this->_destroy = true;
    }
    else if (this->_clock->checkMilliseconds()) {
        this->_position.x += this->_speed;
    }
}

void Bullet::event(std::vector<ClientResponse> clientResponses)
{

}

ServerResponse Bullet::display()
{
    ServerResponse response;

    response.ID = this->_id;
    response.positionX = this->_position.x;
    response.positionY = this->_position.y;
    response.state = 0;
    response.textureID = 5;
    if (this->isDestroyed()) {
        response.value = DELETE_DISPLAY_INFO;
        response.state = DELETE_DISPLAY_INFO;
    }
    else
        response.value = 0;
    return response;
}

void Bullet::onTrigger(std::shared_ptr<GameObject> obj)
{
    if (!obj->isTrigger()) {
        obj->setDestroyed(true);
        this->setDestroyed(true);
    }
}