/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include "Types.hpp"

class Event {
    public:
        Event();
        ~Event();

        bool isPressed(std::string keyCode);
        sf::Keyboard::Key stringToKey(std::string str);

        void setClientResponses(std::vector<ClientResponse> clientResponses);
        std::vector<ClientResponse> getClientResponse() const;
    protected:
        std::vector<ClientResponse> _clientResponses;
        std::unordered_map<std::string, sf::Keyboard::Key> _keys;
        std::shared_ptr<sf::Event> _event;
};

#endif /* !EVENT_HPP_ */