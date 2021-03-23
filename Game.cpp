//
// Created by Mike Quinn on 3/18/21.
//

#include "Game.h"

#include <utility>

Game::Game(const Player &currentPlayer)
        : currentPlayer{currentPlayer} {};

void Game::selectWeapon(Weapon &weapon) {

    this->currentPlayer.equipWeapon(weapon);
}

void Game::uiWeapon(std::string *weapon_) {

}

// pass a string along to paint the picture of where you are
void Game::setSceneSetting(std::string setting) const {
    this->currentScene->setting = std::move(setting);
}

void Game::setSceneQuestions(SceneQuestionsT &questions){

}

void Game::sceneQuestions(){

}
