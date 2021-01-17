/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>
#include "Types.hpp"
#include "Time.hpp"

struct bck {
    sf::Texture text_back;
    sf::Sprite sp_back;
    Time time;
    float x;
};

class Window {
    public:
        Window(int width, int height);
        ~Window();

        void drawBackground();
        void clear();
        void display();
        void drawSprite(std::string id, Vector2i position);
        bool isWindowOpen() const;

        Vector2i getSize();
    protected:
        bck back;
        Vector2i _size;
        sf::RenderWindow _window;
        std::unordered_map<std::string, sf::Texture> _textures;
};

#endif /* !WINDOW_HPP_ */