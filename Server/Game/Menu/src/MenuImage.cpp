/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Image
*/

#include "MenuImage.hpp"

Image::Image(std::string id, std::string path, float x, float y) : GameObject(id, x, y)
{
}

Image::~Image()
{
}

ServerResponse Image::display()
{
    ServerResponse response;
    return response;
}

void Image::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{

}

void Image::event(std::vector<ClientResponse> clientResponses)
{

}

void Image::onTrigger(std::shared_ptr<GameObject> obj)
{
}
