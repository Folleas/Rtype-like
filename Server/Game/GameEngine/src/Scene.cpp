/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene(std::shared_ptr<boost::asio::io_service> io_service, std::size_t port) : UDPServer(io_service, port)
{
    this->_io_service = io_service;
    this->_clock = std::make_unique<Time>(5);
    this->_clockComunication = std::make_unique<Time>(1);
}

Scene::~Scene()
{
}

void Scene::manageLevel()
{
    if (this->_clock->checkMilliseconds()) {
        int i = rand() % 1000;
        if (i == SPAWN_ENEMY_1) {
            std::shared_ptr<Obstacle> obstacle = std::make_shared<Obstacle>("4", 100 + rand()%1700, 100 + rand()%800);
            this->_gameObjects.push_back(obstacle);
        }
        if (i == SPAWN_ENEMY_2) {
            std::shared_ptr<Enemy2> obstacle = std::make_shared<Enemy2>("3", 100 + rand()%1700, 100 + rand()%800);
            this->_gameObjects.push_back(obstacle);
        }
        if (i == SPAWN_SHOOTPOWERUP) {
            std::shared_ptr<ShootPowerUp> shootPowerUp = std::make_shared<ShootPowerUp>("6", 100 + rand()%1700, 100 + rand()%800);
            this->_gameObjects.push_back(shootPowerUp);
        }
        if (i == SPAWN_SPEEDPOWERUP) {
            std::shared_ptr<SpeedPowerUp> shootPowerUp = std::make_shared<SpeedPowerUp>("7", 100 + rand()%1700, 100 + rand()%800);
            this->_gameObjects.push_back(shootPowerUp);
        }
    }
}

void Scene::play()
{
    while (1) {
        this->manageEvent();
        this->manageDestroy();
        this->manageLevel();
        std::vector<ServerResponse> serverResponse;
        for (std::size_t i = 0; i != this->_gameObjects.size(); i++) {
            this->_gameObjects.at(i)->event(this->_clientResponses);
            this->_gameObjects.at(i)->update(this->_gameObjects);
            serverResponse.push_back(this->_gameObjects.at(i)->display());
        }
        this->manageCollision();
        this->communicateToClient(serverResponse);
        this->_io_service->poll();
    }
}

std::vector<ClientResponse> Scene::getClientResponse()
{
    std::vector<ClientResponse> clientResponses;
    if (this->_clientMessage.empty()) {
        ClientResponse res;
        res.horizontal = 0;
        res.id = 1;
        res.other = 0;
        res.vertical = 0;
        clientResponses.push_back(res);
    }
    else {
        boost::array<char, 32> recv_buf;
        boost::system::error_code error;
        std::vector<decode_c> structVec;

        decode_c dec = Decode_fromClient(this->_clientMessage);
        ClientResponse clientResponse;
        clientResponse.horizontal = dec.Horizontal;
        clientResponse.vertical = dec.Vertical;
        clientResponse.other = dec.Other;
        clientResponse.id = dec.Id;
        clientResponses.push_back(clientResponse);
    }
    return clientResponses;
}

void Scene::postClientResponse(ServerResponse serverResponse)
{
	boost::array<char, 64> send_buf;
	boost::system::error_code error;
	std::vector<decode_c> structVec;
    decode_s dec;
    dec.Id = serverResponse.ID;
    dec.State = serverResponse.state;
    dec.Texture_Id = serverResponse.textureID;
    dec.Value = serverResponse.value;
    dec.X = serverResponse.positionX;
    dec.Y = serverResponse.positionY;
    this->_toSend = Encode_toClient(dec);
}

void Scene::setClientResponses(std::vector<ClientResponse> clientResponses)
{
    this->_clientResponses = clientResponses;
}

void Scene::manageEvent()
{
    this->setClientResponses(getClientResponse());
}

int Scene::getServerResponseIndexByID(int &ID)
{
    for (int j = 0; j != this->_serverResponses.size(); j++) {
        if (this->_serverResponses.at(j).ID == ID)
            return j;
    }
    return -1;
}

void Scene::communicateToClient(std::vector<ServerResponse> &serverResponse)
{
    if (this->_serverResponses.empty()) {
        this->_serverResponses = serverResponse;
    }
    else {
        for (int j = 0; j != serverResponse.size(); j++) {
            int index = getServerResponseIndexByID(serverResponse.at(j).ID);
            if (index == -1) {
                this->_serverResponses.push_back(serverResponse.at(j));
            }
            else {
                this->_serverResponses.at(index) = serverResponse.at(j);
            }
        }
    }
    if (!this->_serverResponses.empty()) {
        postClientResponse(this->_serverResponses.at(0));
        this->_serverResponses.erase(this->_serverResponses.begin());
    }
}

void Scene::manageCollision()
{
    for (std::size_t i = 0; i != this->_gameObjects.size(); i++) {
        for (std::size_t j = i + 1; j != this->_gameObjects.size(); j++) {
            if (isColliding(this->_gameObjects.at(i), this->_gameObjects.at(j))) {
                this->_gameObjects.at(i)->onTrigger(this->_gameObjects.at(j));
                this->_gameObjects.at(i)->onTrigger(this->_gameObjects.at(i));
            }
        }
    }
}

bool Scene::isColliding(std::shared_ptr<PositionManager> obj1, std::shared_ptr<PositionManager> obj2)
{
    Vector2f positionObj1 = obj1->getPosition();
    Vector2f positionObj2 = obj2->getPosition();
    Vector2f sizeObj1 = obj1->getSize();
    sizeObj1.x += positionObj1.x;
    sizeObj1.y += positionObj1.y;
    Vector2f sizeObj2 = obj2->getSize();
    sizeObj2.x += positionObj2.x;
    sizeObj2.y += positionObj2.y;

    if (positionObj2.x >= positionObj1.x && positionObj2.x <= sizeObj1.x && positionObj2.y >= positionObj1.y && positionObj2.y <= sizeObj1.y)
        return true;
    else if (positionObj1.x >= positionObj2.x && positionObj1.x <= sizeObj2.x && positionObj1.y >= positionObj2.y && positionObj1.y <= sizeObj2.y)
        return true;
    else if (sizeObj2.x >= positionObj1.x && sizeObj2.x <= sizeObj1.x && sizeObj2.y >= positionObj1.y && sizeObj2.y <= sizeObj1.y)
        return true;
    else if (sizeObj1.x >= positionObj2.x && sizeObj1.x <= sizeObj2.x && sizeObj1.y >= positionObj2.y && sizeObj1.y <= sizeObj2.y)
        return true;
    return false;
}

void Scene::manageDestroy()
{
    for (std::size_t i = 0; i != this->_gameObjects.size(); i++) {
        if (this->_gameObjects.at(i)->isDestroyed()) {
            this->_gameObjects.erase(this->_gameObjects.begin() + i);
            break;
        }
    }
}

void Scene::addGameObject(std::shared_ptr<GameObject> gameObject)
{
    if (gameObject)
        this->_gameObjects.push_back(gameObject);
}