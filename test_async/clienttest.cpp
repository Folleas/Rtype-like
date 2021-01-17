/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Client
*/

#include "clienttest.hpp"

Client::Client() : _receiver_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234), _thread_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 6969), _socket(_io_service)
{
	_socket.open(udp::v4());
    // _receiver_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234),
}

Client::~Client()
{

}

void Client::handle_receive(const boost::system::error_code& error, std::size_t)
{
    if (!error || error == boost::asio::error::message_size)
    {
		std::cout << "Server response saved." << std::endl;
	}
    std::cout << "Received." << std::endl;
}

void Client::handle_send(std::string msg, const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::message_size)
    {
		std::cout << "Client request sent." << std::endl;
	}
    std::cout << "Sent." << std::endl;
}

char *Client::getServerResponse()
{
	udp::endpoint sender_endpoint;
    std::cout << "server addr: " << _thread_endpoint << std::endl;


    (_socket).async_receive_from(boost::asio::buffer(_recv_buf), _thread_endpoint,
		boost::bind(&Client::handle_receive, this, boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));

    // _socket.receive_from(boost::asio::buffer(_recv_buf), _thread_endpoint);

    // std::cout << _recv_buf.data() << std::endl;
    // std::cout << "getServerReponse binary : " << recv_buf.data() << std::endl;
	return (_recv_buf.data());
}

void Client::postServerResponse(std::string str, int passed)
{
    std::string toSend = str;

    if (passed == 0)
        _socket.send_to(boost::asio::buffer(toSend), _receiver_endpoint);
    else {
        // std::cout << "thread endpoint: " << _thread_endpoint;
	    // _socket.send_to(boost::asio::buffer(toSend), _thread_endpoint);
        _socket.async_send_to(boost::asio::buffer(toSend), _thread_endpoint,
        boost::bind(&Client::handle_send, this, toSend, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
    }
    // _socket.async_send_to(boost::asio::buffer(toSend), _receiver_endpoint,
    // boost::bind(&Client::handle_send, this, toSend, boost::asio::placeholders::error,
    //     boost::asio::placeholders::bytes_transferred));
}

int main()
{
    Client client;

	boost::array<char, 1> send_buf  = { 0 };
    std::string data_thread = "Je te boucle la chatte from Client";
    std::string data_lobby = "Hi server";
	client.postServerResponse(data_lobby, 0);
    std::cout << "Passed" << std::endl;
    // client._socket.send_to(boost::asio::buffer(data_lobby), client._receiver_endpoint);

    client.getServerResponse();
	while (1) {
        std::cout << "get server: " << client._recv_buf.data() << std::endl;
        std::cout << "post server: " << data_thread << std::endl;
        client.postServerResponse(data_thread, 0);
	}
    return (0);
}