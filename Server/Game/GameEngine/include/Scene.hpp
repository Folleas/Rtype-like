/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>
#include "SFMLGraphics.hpp"
#include "GameObject.hpp"
#include "BinaryConverter.hpp"
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "UDPServer.hpp"
#include "ShootPowerUp.hpp"
#include "SpeedPowerUp.hpp"
#include "Obstacle.hpp"
#include "Enemy2.hpp"

using boost::asio::ip::udp;

class Scene : public UDPServer {
    public:
        Scene(std::shared_ptr<boost::asio::io_service> io_service, std::size_t port);
        ~Scene();

        void play();
        void addGameObject(std::shared_ptr<GameObject> gameObject);
        int getServerResponseIndexByID(int &ID);
        void manageDestroy();
        void manageEvent();
        void manageCollision();
        void manageClients();
        void manageLevel();
        void communicateToClient(std::vector<ServerResponse> &serverResponse);
        bool isColliding(std::shared_ptr<PositionManager> obj1, std::shared_ptr<PositionManager> obj2);

        void setClientResponses(std::vector<ClientResponse> clientResponses);
        std::vector<ClientResponse> getClientResponse();
		void postClientResponse(ServerResponse serverResponse);
        void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
		void handle_send(std::string msg, const boost::system::error_code& error, std::size_t bytes_transferred);
    private:
        std::vector<ClientResponse> _clientResponses;
        std::shared_ptr<boost::asio::io_service> _io_service;
        std::vector<ServerResponse> _serverResponses;
        std::vector<std::shared_ptr<GameObject>> _gameObjects;
        std::unique_ptr<Time> _clock;
        std::unique_ptr<Time> _clockComunication;
};

#endif /* !SCENE_HPP_ */