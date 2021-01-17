/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Window
*/

#include "SFMLWindow.hpp"

Window::Window(int width, int height)
{
    this->_window.create(sf::VideoMode(width, height), "RTYPE");
    this->_size.x = width;
    this->_size.y = height;
    this->back.text_back.loadFromFile("../../Resources/background.png");
    this->back.sp_back.setTexture(this->back.text_back);
    this->back.x = 0;
    back.time.setSecToCheck(40);
}

Window::~Window()
{
}

void Window::clear()
{
    this->_window.clear();
}

Vector2i Window::getSize()
{
    return this->_size;
}

void Window::display()
{
    this->_window.display();
}

void Window::drawBackground()
{
    if (back.time.checkMilliseconds() == true) {
        back.x += 5;
        if (back.x >= 1920)
            back.x = 0;
        back.sp_back.setTextureRect({(int)back.x, 0, 1920, 1080});
    }
    this->_window.draw(back.sp_back);
}

void Window::drawSprite(std::string id, Vector2i position)
{
    sf::Sprite sprite;
    for (auto it = this->_textures.begin(); it != this->_textures.end(); it++) {
        if (it->first == id) {
            sprite.setTexture(it->second);
            sprite.setPosition((sf::Vector2f){(float)position.x, (float)position.y});
            this->_window.draw(sprite);
            return;
        }
    }
    sf::Texture text;
    text.loadFromFile(id.c_str());
    this->_textures.insert(std::make_pair(id, text));
    sprite.setTexture(text);
    sprite.setPosition((sf::Vector2f){(float)position.x, (float)position.y});
    this->_window.draw(sprite);
}

bool Window::isWindowOpen() const
{
    return this->_window.isOpen();
}