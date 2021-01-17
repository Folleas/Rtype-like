/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Enemies
*/

#ifndef ENEMIES_HPP_
#define ENEMIES_HPP_

#include "GameObject.hpp"
#include "Time.hpp"
#include "Bullet.hpp"
#include <dlfcn.h>
#define ene1 "enemies.so"

enum Direction {
    UPI, DOWNI, LEFTI, RIGHTI
};

class Enemy : public GameObject {
    public:
        Enemy(std::string id, float x, float y);
        ~Enemy() {}

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void move(Direction direction);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

    private:
        int _speed;
        int _nb_move;
        Direction _direct;
        std::size_t _timeBetweenShots;
        std::unique_ptr<Time> _movementClock;
        std::unique_ptr<Time> _shootingClock;
};

typedef Enemy *create_t(std::string, float, float);

struct Shared {

    void *handle_enemy;
    char *enemy1;
    create_t *fnc_ene;
    GameObject *obj;
};

#endif