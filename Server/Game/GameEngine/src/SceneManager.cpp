/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::playScene(std::string sceneID)
{
    if (this->_scenes[sceneID])
        this->_scenes[sceneID]->play();
    else
        std::cerr << "SceneManager [playScene] : Invalid SceneID" << std::endl;
}

void SceneManager::addScene(std::string sceneID, std::shared_ptr<Scene> scene)
{
    if (!sceneID.empty() && scene)
        this->_scenes[sceneID] = scene;
    else
        std::cerr << "SceneManager [addScene] : Invalid SceneID or Scene" << std::endl;
}