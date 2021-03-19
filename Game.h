//
// Created by Mike Quinn on 3/18/21.
//

#ifndef SIMPLE_GAME_GAME_H
#define SIMPLE_GAME_GAME_H


#include "Player.h"

class Game {
public:
    bool playerIsDead = false;
    Player currentPlayer;
    Game(const Player &currentPlayer);

    void selectWeapon(Weapon &weapon);

    void uiWeapon(std::string *weapon_);
};

struct GameT {
    bool playerIsDead = false;
    int score = 0; // increment when an enemy is attacked.
};



#endif //SIMPLE_GAME_GAME_H
