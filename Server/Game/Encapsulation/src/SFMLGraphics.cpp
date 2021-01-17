/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Graphics
*/

#include "SFMLGraphics.hpp"

Graphics::Graphics(int width, int height) : Window(width, height)
{
}

Graphics::~Graphics()
{
}

bool Graphics::pollEvent()
{
    return (this->_window.pollEvent(*this->_event));
}

bool Graphics::closeWindow()
{
    if (_event->type == sf::Event::Closed) {
        this->_window.close();
        return true;
    }
    return false;
}