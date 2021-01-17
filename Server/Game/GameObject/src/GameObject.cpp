/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** GameObject
*/

#include "GameObject.hpp"

GameObject::GameObject(std::string id, float x, float y) : PositionManager(x, y)
{
    this->_id = stoi(id);
    this->_type = GameObjectType::GOUNDEFINED;
    this->_destroy = false;
}

GameObject::~GameObject()
{
}

void GameObject::onTrigger(std::shared_ptr<GameObject> obj)
{
}

std::size_t GameObject::getID() const
{
    return this->_id;
}

GameObjectType GameObject::getType() const
{
    return this->_type;
}
