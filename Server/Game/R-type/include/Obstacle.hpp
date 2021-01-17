/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Obstacle
*/

#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include "GameObject.hpp"
#include "Time.hpp"

class Obstacle : public GameObject {
    public:
        Obstacle(std::string id, float x, float y);
        ~Obstacle();

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

    private:
        float _speed;
        std::unique_ptr<Time> _clock;
};

#endif /* !OBSTACLE_HPP_ */