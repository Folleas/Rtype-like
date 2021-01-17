#include <vector>
#include <iterator>
#include <iostream>
#include <thread>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
// #include "BinaryConverter.hpp"

#ifndef SERVERTEST_HPP_
#define SERVERTEST_HPP_

class Server {
	private:
		std::vector<boost::asio::ip::udp::endpoint> _clientList;
		boost::asio::io_service _io_service;
		std::shared_ptr<boost::asio::ip::udp::socket> _socket;
		boost::array<char, 64> _recv_buf;
		int _nbThreads;
		typedef struct comBinServer_s
		{
			int Texture_Id;
			int Value;
			int X;
			int Y;
			int State;
			int Id;
		} comBinServer_t;
		typedef struct comBinClient_s
		{
			int Vertical;
			int Horizontal;
			int Other;
		} comBinClient_t;

	public:
		Server();
		~Server();
		void Server_Error(const char *str);
		void Start_Server();
		void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);	
		void handle_send(std::string msg, const boost::system::error_code& error, std::size_t bytes_transferred);
		void threadFunc(void* param);
		std::string getClientResponse(boost::asio::ip::udp::socket &my_socket, std::vector<boost::asio::ip::udp::endpoint> myClient);
		void postClientResponse(boost::asio::ip::udp::socket &my_socket, std::vector<boost::asio::ip::udp::endpoint> myClient, std::string str);
		bool checkClientList(boost::asio::ip::udp::endpoint remote_address);
};

#endif /* !SERVERTEST_HPP_ */
