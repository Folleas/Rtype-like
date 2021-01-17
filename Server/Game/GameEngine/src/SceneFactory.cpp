/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** SceneFactory
*/

#include "SceneFactory.hpp"

std::shared_ptr<Scene> SceneFactory::setupGame(std::size_t port)
{
    std::shared_ptr<boost::asio::io_service> io_service = std::make_shared<boost::asio::io_service>();
    std::shared_ptr<Scene> gameScene = std::make_shared<Scene>(io_service, port);
    std::shared_ptr<Player> player = std::make_shared<Player>("1", 0, 0, 1);
    std::shared_ptr<Player> player2 = std::make_shared<Player>("2", 0, 500, 2);

    gameScene->addGameObject(player);
    gameScene->addGameObject(player2);
    return gameScene;
}