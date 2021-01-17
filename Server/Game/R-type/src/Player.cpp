/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::string id, float x, float y, std::size_t playerNb) : GameObject(id, x, y)
{
    this->_type = GameObjectType::PLAYER;
    this->_playerNb = playerNb;
    this->_timeBetweenShots = 150;
    this->_movementClock = std::make_unique<Time>(10);
    this->_shootingClock = std::make_unique<Time>(this->_timeBetweenShots);
    this->setKeys("Q", "D", "Z", "S", "X", "C");
    this->setSize(128, 56);
    this->_speed = 5;
}

Player::~Player()
{
}

void Player::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_movementClock->checkMilliseconds()) {
        this->_position.x += this->_direction.x * this->_speed;
        this->_position.y += this->_direction.y * this->_speed;
    }
    if (this->_shootingClock->checkMilliseconds()) {
        if (this->_isShooting) {
            std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>("8", _position.x + this->_size.x + 25, _position.y);
            sceneObjects.push_back(bullet);
        }
    }
}

void Player::event(std::vector<ClientResponse> clientResponses)
{
    if (!clientResponses.empty())
        this->computeInput(clientResponses.at(0));
}

ServerResponse Player::display()
{
    ServerResponse response;

    response.ID = _playerNb;
    response.positionX = this->_position.x;
    response.positionY = this->_position.y;
    response.state = 0;
    response.textureID = 1;
    if (this->_destroy)
        response.value = DELETE_DISPLAY_INFO;
    else
        response.value = 0;
    return response;
}

void Player::setTimeBetweenShots(const std::size_t &value)
{
    this->_timeBetweenShots = value;
}

std::size_t Player::getTimeBetweenShots() const
{
    return this->_timeBetweenShots;
}

void Player::setSpeed(const std::size_t &value)
{
    this->_speed = value;
}

std::size_t Player::getSpeed() const
{
    return this->_speed;
}

void Player::onTrigger(std::shared_ptr<GameObject> obj)
{
    if (obj->getType() == GameObjectType::SPEEDPOWERUP) {
        std::size_t speed = this->getSpeed();

        if (speed <= 10)
            this->setSpeed(speed + 1);
        obj->setDestroyed(true);
    }
    else if (obj->getType() == GameObjectType::SHOOTPOWERUP) {
        std::size_t timeBetweenShots = this->getTimeBetweenShots();

        if (timeBetweenShots >= 50)
            this->setTimeBetweenShots(timeBetweenShots - 5);
        obj->setDestroyed(true);
    }
    else if (obj->getType() == GameObjectType::MOB) {
        this->setDestroyed(true);
    }
}