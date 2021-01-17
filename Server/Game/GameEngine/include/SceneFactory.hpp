/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** SceneFactory
*/

#ifndef SCENEFACTORY_HPP_
#define SCENEFACTORY_HPP_

#include "Scene.hpp"
#include "Enemies.hpp"
#include "Animated.hpp"
#include "Button.hpp"
#include "MenuImage.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"

class SceneFactory {
    public:
        SceneFactory() = default;
        ~SceneFactory() = default;

        static std::shared_ptr<Scene> setupSplashScreen();
        static std::shared_ptr<Scene> setupMainMenuscreen();
        static std::shared_ptr<Scene> setupOfflineMenuscreen();
        static std::shared_ptr<Scene> setupOnlineMenuscreen();
        static std::shared_ptr<Scene> setupSettingsMenuscreen();
        static std::shared_ptr<Scene> setupGame(std::size_t port);
    private:
};

#endif /* !SCENEFACTORY_HPP_ */