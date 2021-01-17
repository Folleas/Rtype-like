/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Enemy2
*/

#ifndef Enemy2_HPP_
#define Enemy2_HPP_

#include "GameObject.hpp"
#include "Time.hpp"

class Enemy2 : public GameObject {
    public:
        Enemy2(std::string id, float x, float y);
        ~Enemy2();

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

#endif /* !Enemy2_HPP_ */