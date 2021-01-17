/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Graphics
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include "SFMLEvent.hpp"
#include "SFMLWindow.hpp"
#include <memory>

class Graphics : public Event, public Window {
    public:
        Graphics(int width, int height);
        ~Graphics();

        bool closeWindow();
        bool pollEvent();
    private:
};

#endif /* !GRAPHIC_HPP_ */