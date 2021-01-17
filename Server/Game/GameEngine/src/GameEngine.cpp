/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

GameEngine::GameEngine(std::size_t port)
{
    std::shared_ptr<Scene> playerScene = SceneFactory::setupGame(port);
    this->addScene("PlayerScreen", playerScene);
}

GameEngine::~GameEngine()
{
}

void GameEngine::run()
{
    this->playScene("PlayerScreen");
}