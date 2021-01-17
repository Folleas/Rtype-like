/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Image
*/

#ifndef MENUIMAGE_HPP_
#define MENUIMAGE_HPP_

#include "GameObject.hpp"

class Image : public GameObject {
    public:
        Image(std::string id, std::string path, float x, float y);
        ~Image();

        void update(std::vector<std::shared_ptr<GameObject>> &sceneObjects);
        void event(std::vector<ClientResponse> clientResponses);
        ServerResponse display();
        void onTrigger(std::shared_ptr<GameObject> obj);

    private:
};

#endif /* !MENUIMAGE_HPP_ */