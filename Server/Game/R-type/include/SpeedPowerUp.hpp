/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** SpeedPowerUp
*/

#ifndef SpeedPowerUp_HPP_
#define SpeedPowerUp_HPP_

#include "Player.hpp"
#include "Time.hpp"

class SpeedPowerUp : public GameObject {
    public:
        SpeedPowerUp(std::string id, float x, float y);
        ~SpeedPowerUp();

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

#endif /* !SpeedPowerUp_HPP_ */