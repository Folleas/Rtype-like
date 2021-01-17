#include <vector>
#include <iterator>
#include <iostream>
#include <thread>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "BinaryConverter.hpp"

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "GameEngine.hpp"

class Server {
	public:
		Server();
		~Server();
		void Start_Server();
		void threadFunc(void* param);
		bool checkInput(std::string input);
};

#endif /* !SERVER_HPP_ */
