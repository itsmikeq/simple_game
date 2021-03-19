//
// Created by Mike Quinn on 3/18/21.
//

#include "Game.h"

Game::Game(const Player &currentPlayer)
        : currentPlayer{currentPlayer} {};

void Game::selectWeapon(Weapon &weapon) {

    this->currentPlayer.equipWeapon(weapon);
}