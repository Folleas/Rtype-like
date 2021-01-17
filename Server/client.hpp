#include "server.hpp"

#ifndef CLIENT_UDP_HPP_
#define CLIENT_UDP_HPP_

using boost::asio::ip::udp;

#include "Types.hpp"

ServerResponse getServerResponse(udp::socket socket);

void postServerResponse(udp::socket socket, udp::endpoint receiver_endpoint, int Vertical, int Horizontal, int Other);


#endif /* !CLIENT_HPP_ */