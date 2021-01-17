/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** SpeedPowerUp
*/

#include "SpeedPowerUp.hpp"

SpeedPowerUp::SpeedPowerUp(std::string id, float x, float y) : GameObject(id, x, y)
{
    this->_type = GameObjectType::SPEEDPOWERUP;
    this->_trigger = true;
    this->_startingPosition = this->_position;
    this->_destroy = false;
    this->_speed = 3;
    this->_clock = std::make_unique<Time>(10);
    this->_direction = 1;
}

SpeedPowerUp::~SpeedPowerUp()
{
}

void SpeedPowerUp::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_clock->checkMilliseconds()) {
        this->_position.x -= this->_speed;
    }
    if (this->_position.x <= 10)
        this->_destroy = true;
}

void SpeedPowerUp::event(std::vector<ClientResponse> clientResponses)
{

}


ServerResponse SpeedPowerUp::display()
{
    ServerResponse response;

    response.ID = this->_id;
    response.positionX = this->_position.x;
    response.positionY = this->_position.y;
    response.state = 0;
    response.textureID = 7;
    if (this->_destroy)
        response.value = DELETE_DISPLAY_INFO;
    else
        response.value = 0;
    return response;
}

void SpeedPowerUp::onTrigger(std::shared_ptr<GameObject> obj)
{
    // if (obj->getType() == GameObjectType::PLAYER) {
        // std::cerr << "speed power up taken by player " << obj->getID() << std::endl;
        // std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(obj);
        // std::size_t speed = player->getSpeed();

        // if (speed <= 10)
        //     player->setSpeed(speed + 3);
    // }
}