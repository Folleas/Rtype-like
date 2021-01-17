/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** UDPServer
*/

#include "UDPServer.hpp"

UDPServer::UDPServer(std::shared_ptr<boost::asio::io_service> io_service, std::size_t port) : _socket(*io_service, udp::endpoint(udp::v4(), port))
{
    receive();
}

UDPServer::~UDPServer()
{
}

void UDPServer::receive() {
    _socket.async_receive_from(
        boost::asio::buffer(_recvBuffer), _remoteEndpoint,
        boost::bind(&UDPServer::receiveHandler, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void UDPServer::receiveHandler(const boost::system::error_code& error, std::size_t bytes_transferred) {
    if (!_recvBuffer.empty()) {
        std::string temp;
        for (int i = 0; i != 32; i++)
            temp.push_back((_recvBuffer.data())[i]);
        this->_clientMessage = temp;
    }
    if (!error || error == boost::asio::error::message_size && !this->_toSend.empty()) {
        _socket.async_send_to(boost::asio::buffer(this->_toSend), _remoteEndpoint,
            boost::bind(&UDPServer::sendHandler, this, this->_toSend,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
    }
}

void UDPServer::sendHandler(std::string message, const boost::system::error_code& ec, std::size_t bytes_transferred) {
    receive();
}