/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Animated
*/

#ifndef ANIMATED_HPP_
#define ANIMATED_HPP_

#include <vector>
#include "GameObject.hpp"
#include "Time.hpp"
#include "SFMLWindow.hpp"

class Animated : public GameObject {
    public:
        Animated(std::string id, std::vector<std::string> paths, float x, float y, float delay);
        ~Animated();

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

    private:
        std::size_t _spriteDisplayed;
        std::vector<std::string> _paths;
        std::shared_ptr<Time> _time;
};

#endif /* !ANIMATED_HPP_ */