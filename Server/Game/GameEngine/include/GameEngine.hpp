/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "SFMLGraphics.hpp"
#include "SceneManager.hpp"
#include "SceneFactory.hpp"


using boost::asio::ip::udp;

class GameEngine : public SceneManager {
    public:
        GameEngine(std::size_t port);
        ~GameEngine();

        void run();

    private:
};

#endif /* !GAMEENGINE_HPP_ */