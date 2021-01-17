/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Bullet
*/

#ifndef BULLET_HPP_
#define BULLET_HPP_

#include "GameObject.hpp"
#include "Time.hpp"

class Bullet : public GameObject {
    public:
        Bullet(std::string id, float x, float y);
        ~Bullet();

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

    private:
        float _speed;
        std::unique_ptr<Time> _clock;
};

#endif /* !BULLET_HPP_ */