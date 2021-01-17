/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** ShootPowerUp
*/

#ifndef PowerUp_HPP_
#define PowerUp_HPP_

#include "Player.hpp"
#include "Time.hpp"

class ShootPowerUp : public GameObject {
    public:
        ShootPowerUp(std::string id, float x, float y);
        ~ShootPowerUp();

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

    private:
        std::size_t _direction;
        Vector2f _startingPosition;
        float _speed;
        std::unique_ptr<Time> _clock;
};

#endif /* !PowerUp_HPP_ */