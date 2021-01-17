#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <iostream>
#include "server.hpp"

Server::Server()
{

}

Server::~Server()
{

}

void Server::Server_Error(const char *str)
{
    std::cerr << str << std::endl;
    exit(84);
}

void *New_Thread(void* param)
{
    char buf[1024];
    int count;
    pthread_detach(pthread_self());
    int s = static_cast<int>(reinterpret_cast<std::uintptr_t>(param));

    while(count = read(s, buf, 1023) > 0 ) {
        std::cout << "Server received a new client" << std::endl;
	std::cout << "Server received : " << buf << std::endl;
	std::cout << "Server sending it back after changing it\n" << std::endl;
        write(s, "NTNN sale fdp", 14);
    }
    close(s);
}

void Server::Start_Server()
{
    int sockfd;
    int newsockfd;
    int portno = 1234;

    // création de la socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       Server_Error("ERROR opening socket");
    struct sockaddr_in serv_addr;
    // clear de l'adresse
    bzero((char *) &serv_addr, sizeof(serv_addr));
    // byte order 
    serv_addr.sin_family = AF_INET;
    // rennplis avec l'IP du host
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    // on affecte le port
    serv_addr.sin_port = htons(portno);
    // Bind socket sur l'IP
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        Server_Error("ERROR on binding");
    listen(sockfd,5);
    //Boucle de création de nouveaux threads
    while(newsockfd = accept(sockfd, 0, 0)) {
        pthread_t t;
        pthread_create(&t, 0, New_Thread, (void*)newsockfd);
    }
}

int main()
{
    Server new_server;

    new_server.Start_Server();
}
