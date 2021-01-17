/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** DisplayInfo
*/

#ifndef DISPLAYINFO_HPP_
#define DISPLAYINFO_HPP_

#include <vector>
#include <memory>
#include <iostream>
#include "Types.hpp"

class DisplayInfo {
    public:
        DisplayInfo(std::size_t ID, std::size_t textureID, std::size_t value, Vector2i position, std::size_t state);
        ~DisplayInfo();

        void setID(const std::size_t &ID);
        void setTextureID(const std::size_t &textureID);
        void setPosition(const std::size_t &positionX, const std::size_t &positionY);
        void setState(const std::size_t &state);
        void setValue(const std::size_t &value);

        std::size_t getTextureID() const;
        Vector2i getPosition() const;
        std::size_t getID() const;
        std::size_t getState() const;
        std::size_t getValue() const;

    private:
        std::size_t _ID;
        std::size_t _textureID;
        std::size_t _value;
        Vector2i _position;
        std::size_t _state;
};

#endif /* !DISPLAYINFO_HPP_ */