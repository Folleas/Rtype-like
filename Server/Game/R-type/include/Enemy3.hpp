/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Enemy3
*/

#ifndef Enemy3_HPP_
#define Enemy3_HPP_

#include "GameObject.hpp"
#include "Time.hpp"

class Enemy3 : public GameObject {
    public:
        Enemy3(std::string id, float x, float y);
        ~Enemy3();

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

#endif /* !Enemy3_HPP_ */