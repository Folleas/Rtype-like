/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** UDPServer
*/

#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::udp;

class UDPServer {
    public:
        UDPServer( std::shared_ptr<boost::asio::io_service> io_service, std::size_t port);
        ~UDPServer();
    protected:
        void receive();
        void receiveHandler(const boost::system::error_code& error, std::size_t bytes_transferred);

        void sendHandler(std::string message, const boost::system::error_code& ec, std::size_t bytes_transferred);

        udp::socket _socket;
        udp::endpoint _remoteEndpoint;
        std::array<char, 32> _recvBuffer;
        std::string _toSend;
        std::string _clientMessage = "";
};

#endif /* !UDPSERVER_HPP_ */