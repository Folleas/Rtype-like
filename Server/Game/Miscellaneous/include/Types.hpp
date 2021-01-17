/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Types
*/

#ifndef TYPES_HPP_
#define TYPES_HPP_

#define LEFT 2
#define RIGHT 1
#define UP 2
#define DOWN 1
#define SHOOT 1
#define PAUSE 2
#define UNDEFINED 0
#define WINDOW_SIZE_X 1920
#define SPAWN_ENEMY_1 1
#define SPAWN_ENEMY_2 2
#define SPAWN_SHOOTPOWERUP 3
#define SPAWN_SPEEDPOWERUP 4
#define DELETE_DISPLAY_INFO 10

typedef struct ServerResponse {
    int ID;
    int textureID;
    int value;
    int positionX;
    int positionY;
    int state;
}ServerResponse;

typedef struct ClientResponse {
    int horizontal;
    int vertical;
    int other;
    int id;
}decode_cdecode_c;

typedef struct Vector2f {
    float x;
    float y;
}Vector2f;

typedef struct Vector2i {
    int x;
    int y;
}Vector2i;

typedef struct Vector4i {
    int x;
    int y;
    int h;
    int w;
}Vector4i;

typedef enum Keys {
    Left = 0,
    Right = 1,
    Up = 2,
    Down = 3,
    Shoot = 4,
    Pause = 5
}Keys;

typedef enum GameObjectType {
    ANIMATED, IMAGE, BUTTON, PLAYER, GOUNDEFINED, SPEEDPOWERUP, SHOOTPOWERUP, MOB
}GameObjectType;

typedef enum CallBack {
    TitleScreen, MainMenu, OfflineMenu, OnlineMenu, Settings, Quit, Undefined
}CallBack;

#endif /* !TYPES_HPP_ */
