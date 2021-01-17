#include "servertest.hpp"

using boost::asio::ip::udp;

Server::Server()
{
	this->_socket = std::make_shared<boost::asio::ip::udp::socket>(_io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 1234));
	_nbThreads = 0;
	_io_service.run();
}

Server::~Server()
{

}

void Server::handle_receive(const boost::system::error_code& error, std::size_t)
{
	if (!error || error == boost::asio::error::message_size)
    {
		std::cout << "Client response saved." << std::endl;
	}
}

void Server::handle_send(std::string msg, const boost::system::error_code& error, std::size_t bytes_transferred)
{
	if (!error || error == boost::asio::error::message_size)
    {
		std::cout << "Client request sent." << std::endl;
	}
}

std::string Server::getClientResponse(udp::socket &my_socket, std::vector<udp::endpoint> myClient)
{
	boost::system::error_code error;
	// std::vector<decode_c> structVec;
	udp::socket *socket = _socket.get();
	udp::endpoint try_endpoint;

	for (auto it = (myClient).begin(); it != (myClient).end(); it++) { //ce qui est envoyé ici vers *it sera envoyé à tous les clients gérés par ce thread
		(socket)->async_receive_from(boost::asio::buffer(_recv_buf), *it,
		boost::bind(&Server::handle_receive, this, boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
		// structVec.push_back(Decode_fromClient(_recv_buf.data()));
    }
	return (_recv_buf.data());
}

void Server::postClientResponse(udp::socket &my_socket, std::vector<udp::endpoint> myClient, std::string str)
{
	boost::array<char, 64> send_buf;
	boost::system::error_code error;
	// std::vector<decode_c> structVec;
	std::string toSend = str;
	udp::socket *socket = _socket.get();

	for (auto it = (myClient).begin(); it != (myClient).end(); it++) { //ce qui est envoyé ici vers *it sera envoyé à tous les clients gérés par ce thread
		std::cout << "client endpoint: " << *it << std::endl;
		// my_socket.send_to(boost::asio::buffer(toSend), *it);

		socket->async_send_to(boost::asio::buffer(toSend), *it,
		boost::bind(&Server::handle_send, this, toSend, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
		// structVec.push_back(Decode_fromClient(send_buf.data()));
    }
}

bool Server::checkClientList(udp::endpoint remote)
{
	for (auto it = _clientList.begin(); it != _clientList.end(); it++) {
		if ((*it) == remote)
			return (true);
	}
	return (false);
}

void Server::threadFunc(void* param_list)
{
    std::vector<udp::endpoint> *paramList = static_cast<std::vector<udp::endpoint>*>(param_list);
	std::vector<udp::endpoint> clients;
	std::string data = "Mange tes morts from Server";
	udp::socket *socket = _socket.get();
	boost::asio::io_service io_service;
	udp::socket my_socket (io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 6969));

    std::cout << "\nEntering thread" << std::endl;
    while (clients.empty()) {
		clients.push_back(_clientList.back());
    }
	std::string data_client = getClientResponse(my_socket, *paramList);
	// (my_socket).async_receive_from(boost::asio::buffer(_recv_buf), clients[0],
	// 	boost::bind(&Server::handle_receive, this, boost::asio::placeholders::error,
    //     boost::asio::placeholders::bytes_transferred));
	while (1) {
		for (auto it = (*paramList).begin(); it != (*paramList).end(); it++) {
			std::cout << "\nEndpoint in thread: " << *it << std::endl;
		}
		std::cout << "\npost Client: " << data << std::endl;
		postClientResponse(my_socket, *paramList, data);
		std::cout << "\nget Client: " << data_client << std::endl;
	}
}

void Server::Start_Server()
{
	boost::array<char, 64> recv_buf;
	udp::endpoint remote_endpoint;
	boost::system::error_code error;
	int clientListSize = 0;
	int nbClients = 0;
	while (1)
	{
		if (nbClients == 0)
			_socket->receive_from(boost::asio::buffer(recv_buf), remote_endpoint, 0, error);
		if (error && error != boost::asio::error::message_size)
			throw boost::system::system_error(error);
		if (checkClientList(remote_endpoint) == false) {
			_clientList.push_back(remote_endpoint);
			nbClients++;
		}
		std::string message = "Bienvenue sur le serveur ! Mode non connecté.";
		// postClientResponse(_clientList, "Bienvenue sur le serveur !");
		for (auto it = (_clientList).begin(); it != _clientList.end(); it++) {
			std::cout << "\nEndpoint in lobby: " << *it << std::endl;
		}
		// _socket->send_to(boost::asio::buffer(message), remote_endpoint, 0, ignored_error);
		if (nbClients == 1) {
			std::cout << "\nCreating new thread" << std::endl;
			std::thread newThread(&Server::threadFunc, this, &_clientList);
			newThread.detach();
			_nbThreads++;
			 nbClients = 2;
		}
		std::cout << "Client count: " << nbClients << std::endl;
		std::cout << "Threads count: " << _nbThreads << std::endl;
	}
}

int main()
{
    Server new_server;

    new_server.Start_Server();
	return (0);
}