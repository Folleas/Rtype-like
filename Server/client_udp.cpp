#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "server.hpp"
#include "Types.hpp"

using boost::asio::ip::udp;

ServerResponse getServerResponse(udp::socket socket)
{
	boost::array<char, 128> recv_buf;
	udp::endpoint sender_endpoint;
	size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);

	ServerResponse serverResponse;
	decode_s decode = Decode_fromServ(recv_buf.data());

	serverResponse.ID = decode.Id;
	serverResponse.positionX = decode.X;
	serverResponse.positionY = decode.Y;
	serverResponse.state = decode.State;
	serverResponse.value = decode.Value;
	return serverResponse;
}

void postServerResponse(udp::socket socket, udp::endpoint receiver_endpoint, int Vertical, int Horizontal, int Other)
{
	socket.send_to(boost::asio::buffer(Encode_toServ(Vertical, Horizontal, Other)), receiver_endpoint);
}

int main()
{
	boost::asio::io_service io_service;
	udp::endpoint receiver_endpoint (boost::asio::ip::address::from_string("127.0.0.1"), 1234);

	udp::socket socket(io_service);
	socket.open(udp::v4());

	boost::array<char, 1> send_buf  = { 0 };
    std::string data = "010101111111111111111111110";
	socket.send_to(boost::asio::buffer(send_buf), receiver_endpoint);
	socket.send_to(boost::asio::buffer(data), receiver_endpoint);

	while (1) { //Client loop (replace condition by corresponding exit game key)

		// boost::array<char, 128> recv_buf;
		// udp::endpoint sender_endpoint;
		// size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);
		// socket.send_to(boost::asio::buffer(data), receiver_endpoint);

		// std::cout << recv_buf.data() << std::endl;
	}
	return 0;
}