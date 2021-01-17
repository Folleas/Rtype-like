/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <vector>
#include <unordered_map>
#include "Scene.hpp"

class SceneManager {
    public:
        SceneManager();
        ~SceneManager();

        void playScene(std::string sceneID);

        void addScene(std::string sceneID, std::shared_ptr<Scene> scene);
    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> _scenes;
};

#endif /* !SCENEMANAGER_HPP_ */