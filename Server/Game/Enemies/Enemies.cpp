/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Enemies
*/

#include "Enemies.hpp"

Enemy::Enemy(std::string id, float x, float y) : GameObject(id, x, y)
{
    srand (time(NULL));
    this->_timeBetweenShots = 100;
    this->_movementClock = std::make_unique<Time>(10);
    this->_shootingClock = std::make_unique<Time>(this->_timeBetweenShots);
    _direct = DOWNI;
    _nb_move = 0;
    _speed = 10;
}

void Enemy::move(Direction direction)
{
    switch (direction) {
        case RIGHTI:
            if (this->_position.x < 1700) {
                this->_position.x += this->_speed;
                _direct = direction;
            } else
                move(LEFTI);
            break;
        case LEFTI:
            if (this->_position.x > 1300) {
                this->_position.x -= this->_speed;
                _direct = direction;
            } else
                move(RIGHTI);
            break;
        case DOWNI:
            if (this->_position.y < 800) {
                this->_position.y += this->_speed;
                _direct = direction;
            } else
                move(UPI);
            break;
        case UPI:
            if (this->_position.y > 200) {
                this->_position.y -= this->_speed;
                _direct = direction;
            } else
                move(DOWNI);
            break;
        default:
            break;
    }
}

void Enemy::update(std::vector<std::shared_ptr<GameObject>> &sceneObjects)
{
    if (this->_movementClock->checkMilliseconds()) {
        std::cerr << "enemy moves !" << std::endl;
        _nb_move +=1;
        if (_nb_move != 50)
            move(_direct);
        else {
            move(Direction(rand()%4));
            _nb_move = 0;
        }
    }
    if (this->_shootingClock->checkMilliseconds()) {
        std::cerr << "enemy shoot !" << std::endl;
        std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>("8", this->_position.x + 15, this->_position.y + 5);
        sceneObjects.push_back(bullet);
    }
}

void Enemy::event(std::vector<ClientResponse> clientResponses)
{
    return;
}

ServerResponse Enemy::display()
{
    ServerResponse response;

    response.ID = this->_id;
    response.positionX = this->_position.x;
    response.positionY = this->_position.y;
    response.state = 0;
    response.textureID = 6;
    if (this->_destroy)
        response.value = DELETE_DISPLAY_INFO;
    else
        response.value = 0;
    return response;
}


void Enemy::onTrigger(std::shared_ptr<GameObject> obj)
{
    if (obj->isTrigger()) {

    }
    else {
        this->_destroy = true;
    }
}

extern "C" GameObject *create(std::string id, float x, float y)
{
    return (new Enemy(id, x, y));
}
/*
int main()
{
    void *handle_enemy;
    char *enemy1 = ene1;
    GameObject *enemy;
    create_t *fnc_ene;

    if ((!(handle_enemy = dlopen(enemy1, RTLD_NOW))) || (!(fnc_ene = (create_t *)dlsym(handle_enemy, "create")))) {
        std::cerr << dlerror() << std::endl;
        exit(84);
    }
    enemy = fnc_ene("cc", "alo", 100, 100);
}*/