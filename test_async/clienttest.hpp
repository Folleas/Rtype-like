/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Client
*/

#ifndef CLIENTTEST_HPP_
#define CLIENTTEST_HPP_

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>


using boost::asio::ip::udp;

class Client {
    public:
        Client();
        ~Client();
		void handle_receive(const boost::system::error_code& error, std::size_t);
		void handle_send(std::string msg, const boost::system::error_code& error, std::size_t bytes_transferred);

        char *getServerResponse();
        void postServerResponse(std::string str, int passed);
        boost::array<char, 64> _recv_buf;

    protected:
        boost::asio::io_service _io_service;
        boost::asio::ip::udp::endpoint _thread_endpoint;
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _receiver_endpoint;

};

#endif /* !CLIENTTEST_HPP_ */