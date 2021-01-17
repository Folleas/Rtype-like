/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** UDPClient
*/

#include "UDPClient.hpp"

UDPClient::UDPClient(boost::asio::io_service& io_service, const std::string& host, const std::string& port) : io_service_(io_service), socket_(io_service, udp::endpoint(udp::v4(), 0)) {
    udp::resolver resolver(io_service_);
    udp::resolver::query query(udp::v4(), host, port);
    udp::resolver::iterator iter = resolver.resolve(query);
    endpoint_ = *iter;
}

UDPClient::~UDPClient()
{
    socket_.close();
}

void UDPClient::send(const std::string& msg) {
    socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
}

void UDPClient::receive() {
    socket_.receive_from(boost::asio::buffer(_recv_buf), endpoint_);
    this->_serverMessage = _recv_buf.data();
}