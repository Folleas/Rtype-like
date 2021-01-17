/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "GameObject.hpp"
#include "PlayerControler.hpp"
#include "Time.hpp"
#include "Bullet.hpp"

class Player : public GameObject, public PlayerControler {
    public:
        Player(std::string id, float x, float y, std::size_t playerNb);
        ~Player();

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

        void setTimeBetweenShots(const std::size_t &value);
        std::size_t getTimeBetweenShots() const;

        void setSpeed(const std::size_t &value);
        std::size_t getSpeed() const;

    protected:
        std::size_t _timeBetweenShots;
        float _speed;
        std::unique_ptr<Time> _movementClock;
        std::unique_ptr<Time> _shootingClock;
};

#endif /* !PLAYER_HPP_ */