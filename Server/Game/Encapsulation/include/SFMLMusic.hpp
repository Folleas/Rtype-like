/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** SFMLMusic
*/

#ifndef SFMLMUSIC_HPP_
#define SFMLMUSIC_HPP_

#include <SFML/Audio.hpp>

class SFMLMusic {
    public:
        SFMLMusic() {
            sf::Music music;
            if (!music.openFromFile("../../Resources/Music_Rtype.ogg"))
                exit(84);
            music.play();
        }
        ~SFMLMusic() = default;

    protected:
    private:
};

#endif /* !SFMLMUSIC_HPP_ */