/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "DisplayInfo.hpp"
#include "SFMLGraphics.hpp"
#include "SFMLMusic.hpp"
#include "EventManager.hpp"
#include "../../Com/BinaryConverter.hpp"
#include "UDPClient.hpp"

using boost::asio::ip::udp;

class Client : public EventManager, public UDPClient, public SFMLMusic {
    public:
        Client(boost::asio::io_service& io_service, const std::string& host, const std::string& port, const std::size_t &player);
        ~Client();

        void initTextureMap();

        void drawBackground();
        void run();
        void manageDisplayInfo();
        bool modifyDisplayInfo(ServerResponse serverResponse);
        std::string IDtoPath(std::size_t textureID, std::size_t ID);

        ServerResponse getServerResponse();
        void postServerResponse(int Vertical, int Horizontal, int Other, int ID);

    protected:
        std::unordered_map<std::size_t, std::string> _textureMap;
        std::vector<std::shared_ptr<DisplayInfo>> _displayInfo;
        std::shared_ptr<Graphics> _graphics;
        std::size_t _playerNumber;
};

#endif /* !CLIENT_HPP_ */