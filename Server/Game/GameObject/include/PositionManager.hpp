/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** PositionManager
*/

#ifndef POSITIONMANAGER_HPP_
#define POSITIONMANAGER_HPP_

#include "Types.hpp"

class PositionManager {
    public:
        PositionManager(float x, float y);
        ~PositionManager();

        Vector2f getPosition() const;
        Vector2f getSize() const;

        void setPosition(const float &x, const float &y);
        void setSize(const float &width, const float &height);
    protected:
        Vector2f _position;
        Vector2f _size;
};

#endif /* !POSITIONMANAGER_HPP_ */
