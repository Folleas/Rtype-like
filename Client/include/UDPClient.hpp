/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** UDPClient
*/

#ifndef UDPCLIENT_HPP_
#define UDPCLIENT_HPP_

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::udp;

class UDPClient {
    public:
        UDPClient(boost::asio::io_service& io_service, const std::string& host, const std::string& port);

        ~UDPClient();

        void send(const std::string& msg);
        void receive();

    protected:
        boost::asio::io_service& io_service_;
        udp::socket socket_;
        udp::endpoint endpoint_;
        boost::array<char, 64> _recv_buf;
        std::string _serverMessage;
};

#endif /* !UDPCLIENT_HPP_ */