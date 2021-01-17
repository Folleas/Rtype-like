/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "GameObject.hpp"

class Button : public GameObject {
    public:
        Button(std::string id, std::string path, float x, float y, std::shared_ptr<CallBack> callback, CallBack nextState);
        ~Button();

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

    private:
        CallBack _nextState;
        std::shared_ptr<CallBack> _callback;
};

#endif /* !BUTTON_HPP_ */