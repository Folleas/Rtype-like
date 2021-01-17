/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(std::string id, std::string path, float x, float y, std::shared_ptr<CallBack> callback, CallBack nextState) : GameObject(id, x, y)
{
    this->_callback = callback;
    this->_nextState = nextState;
}

Button::~Button()
{
}

void Button::event(std::vector<ClientResponse> clientResponses)
{

}

void Button::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    // Vector2i mousePosition = ;

    // this->_mousePosition.first = mousePosition.x;
    // this->_mousePosition.second = mousePosition.y;
    // if (_mousePosition.first >= this->_position.first && _mousePosition.first <=  this->_position.first + this->_dimension.first && _mousePosition.second >= this->_position.second && _mousePosition.second <= this->_position.second + this->_dimension.second) {
    //     this->setColor((RGBA_t){78, 0, 22, 200});
    // }
}

ServerResponse Button::display()
{
    ServerResponse response;
    return response;
}

void Button::onTrigger(std::shared_ptr<GameObject> obj)
{
}
