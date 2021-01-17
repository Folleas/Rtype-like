/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** TIME
*/

#include "../include/Time.hpp"

Time::Time(float sec_to_check)
{
    this->sec_to_check = sec_to_check;
    this->time_before = std::chrono::system_clock::now();
}

bool Time::checkSeconds()
{
    this->time_now = std::chrono::system_clock::now();
    this->seconds = std::chrono::duration_cast<std::chrono::seconds>(this->time_now - this->time_before);
    if (this->seconds.count() > this->sec_to_check) {
        this->time_before = std::chrono::system_clock::now();
        return (true);
    }
    return (false);
}

bool Time::checkMilliseconds()
{
    this->time_now = std::chrono::system_clock::now();
    this->milliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(this->time_now - this->time_before);
    if (this->milliSeconds.count() > this->sec_to_check) {
        this->time_before = std::chrono::system_clock::now();
        return (true);
    }
    return (false);
}

void Time::reset()
{
    this->time_before = std::chrono::system_clock::now();
    this->time_now = std::chrono::system_clock::now();
}

void Time::setSecToCheck(float new_sec_to_check)
{
    this->sec_to_check = new_sec_to_check;
    reset();
}