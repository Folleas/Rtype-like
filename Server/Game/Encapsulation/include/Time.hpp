/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** TIME
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <chrono>

class Time {

    public:
        Time(float sec_to_check = 1000);
        bool checkMilliseconds();
        bool checkSeconds();
        void reset();
        void setSecToCheck(float new_sec_to_check);

    private:
        float sec_to_check;
        std::chrono::system_clock::time_point time_before;
        std::chrono::system_clock::time_point time_now;
        std::chrono::milliseconds milliSeconds;
        std::chrono::seconds seconds;
};

#endif