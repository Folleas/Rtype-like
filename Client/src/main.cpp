/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** main
*/

#include "Client.hpp"

bool checkPort(std::string portString, std::size_t nb)
{
    int port = std::stoi(portString);

    if (port < 1024) {
        std::cout << "Illegal Port" << std::endl;
        return false;
    }
    if (nb > 2)
        return false;
    return true;
}

int main(int ac, char **av)
{
    boost::asio::io_service io_service;
    if (ac == 3 && checkPort(av[1], std::stoi(av[2]))) {
        Client client(io_service, "127.0.0.1", av[1], std::stoi(av[2]));
        client.run();
    }
    else
        return 84;
    return 0;
}