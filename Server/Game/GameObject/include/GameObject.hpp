/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include "PositionManager.hpp"
#include "StateManager.hpp"

class GameObject : public PositionManager, public StateManager {
    public:
        GameObject(std::string id, float x, float y);
        ~GameObject();

        virtual void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects) = 0;
        virtual void event(std::vector<ClientResponse> clientResponses) = 0;
        virtual ServerResponse display() = 0;

        virtual void onTrigger(std::shared_ptr<GameObject> obj) = 0;

        void setID(const std::size_t &id);

        GameObjectType getType() const;
        std::size_t getID() const;
    protected:
        GameObjectType _type;

        std::size_t _id;

};

#endif /* !GAMEOBJECT_HPP_ */