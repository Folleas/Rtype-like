/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** ShootPowerUp
*/

#include "ShootPowerUp.hpp"

ShootPowerUp::ShootPowerUp(std::string id, float x, float y) : GameObject(id, x, y)
{
    this->_type = GameObjectType::SHOOTPOWERUP;
    this->_trigger = true;
    this->_startingPosition = this->_position;
    this->_destroy = false;
    this->_speed = 3;
    this->_clock = std::make_unique<Time>(10);
    this->_direction = 1;
}

ShootPowerUp::~ShootPowerUp()
{
}

void ShootPowerUp::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_clock->checkMilliseconds()) {
        this->_position.x -= this->_speed;
    }
    if (this->_position.x <= 10)
        this->_destroy = true;
}

void ShootPowerUp::event(std::vector<ClientResponse> clientResponses)
{

}


ServerResponse ShootPowerUp::display()
{
    ServerResponse response;

    response.ID = this->_id;
    response.positionX = this->_position.x;
    response.positionY = this->_position.y;
    response.state = 0;
    response.textureID = 6;
    if (this->_destroy)
        response.value = DELETE_DISPLAY_INFO;
    else
        response.value = 0;
    return response;
}

void ShootPowerUp::onTrigger(std::shared_ptr<GameObject> obj)
{
    // if (obj->getType() == GameObjectType::PLAYER) {
    //     std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(obj);
    //     std::size_t timeBetweenShots = player->getTimeBetweenShots();

    //     if (timeBetweenShots >= 50)
    //         player->setTimeBetweenShots(timeBetweenShots - 20);
    // }
}