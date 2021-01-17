#include "server.hpp"

using boost::asio::ip::udp;

Server::Server()
{
}

Server::~Server()
{

}

void Server::threadFunc(void* param)
{
	std::string *port = static_cast<std::string *>(param);
	GameEngine gameEngine(std::stoi(*port));
	gameEngine.run();
}

bool Server::checkInput(std::string input) {
	int port = std::stoi(input);

	if (port < 1024)
		return false;
	return true;
}

void Server::Start_Server()
{
	std::string port;

	while (1) {
		std::cin >> port;
		if (checkInput(port)) {
			std::thread newThread(&Server::threadFunc, this, &port);
			newThread.detach();
		}
		else {
			std::cout << "Illegal Port" << std::endl;
		}
	}
}