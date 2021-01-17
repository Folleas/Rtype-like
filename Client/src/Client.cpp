/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(boost::asio::io_service &io_service, const std::string &host, const std::string &port, const std::size_t &player) : UDPClient(io_service, host, port)
{
    this->_playerNumber = player;
    this->_graphics = std::make_shared<Graphics>(1920, 1080);
    initTextureMap();
}

Client::~Client()
{
}

void Client::initTextureMap()
{
    std::ifstream fileStream("../../Configuration/texture.conf");
    std::size_t id;
    std::string texture;

    while (fileStream >> id >> texture)
        this->_textureMap[id] = texture;
}

void Client::drawBackground()
{
    this->_graphics->drawBackground();
}

void Client::run()
{
    while (this->_graphics->isWindowOpen()) {
        ClientResponse clientResponse = manageEvent(std::dynamic_pointer_cast<Event>(this->_graphics));
        this->postServerResponse(clientResponse.vertical, clientResponse.horizontal, clientResponse.other, this->_playerNumber);
        manageDisplayInfo();
        while (this->_graphics->pollEvent()) {
            this->_graphics->closeWindow();
        }
        this->_graphics->clear();
        drawBackground();
        for (std::shared_ptr<DisplayInfo> info : this->_displayInfo) {
            if (info->getPosition().x <= 1800)
                this->_graphics->drawSprite(this->IDtoPath(info->getTextureID(), info->getID()), info->getPosition());
        }
        this->_graphics->display();
    }
}

ServerResponse Client::getServerResponse()
{
	ServerResponse serverResponse;
    serverResponse.ID = -1;
    this->receive();
    decode_s decode = Decode_fromServ(this->_serverMessage);

    serverResponse.ID = decode.Id;
    serverResponse.textureID = decode.Texture_Id;
    serverResponse.positionX = decode.X;
    serverResponse.positionY = decode.Y;
    serverResponse.state = decode.State;
    serverResponse.value = decode.Value;
	return serverResponse;
}

void Client::postServerResponse(int Vertical, int Horizontal, int Other, int ID)
{
    std::string toSend = Encode_toServ(Vertical, Horizontal, Other, ID);
    this->send(toSend);
}

std::string Client::IDtoPath(std::size_t textureID, std::size_t ID)
{
    return "../../Resources/" + this->_textureMap[textureID] + ".png";
}

void Client::manageDisplayInfo()
{
    ServerResponse serverResponse = this->getServerResponse();

    if (serverResponse.ID != -1 && !modifyDisplayInfo(serverResponse)) {
        std::shared_ptr<DisplayInfo> displayInfo = std::make_shared<DisplayInfo>(serverResponse.ID, serverResponse.textureID, serverResponse.value, (Vector2i){serverResponse.positionX, serverResponse.positionY}, serverResponse.state);
        this->_displayInfo.push_back(displayInfo);
    }
}

bool Client::modifyDisplayInfo(ServerResponse serverResponse)
{
    bool deleteInfo = false;

    if (serverResponse.value == DELETE_DISPLAY_INFO || serverResponse.positionX >= 3000) {
        deleteInfo = true;
    }
    for (std::size_t i = 0; i != this->_displayInfo.size(); i++) {
        if (this->_displayInfo.at(i)->getID() == serverResponse.ID && this->_displayInfo.at(i)->getTextureID() == serverResponse.textureID) {
            if (deleteInfo) {
                this->_displayInfo.erase(this->_displayInfo.begin() + i);
            }
            else {
                this->_displayInfo.at(i)->setPosition(serverResponse.positionX, serverResponse.positionY);
                this->_displayInfo.at(i)->setState(serverResponse.state);
                this->_displayInfo.at(i)->setValue(serverResponse.value);
            }
            return true;
        }
    }
    return false;
}