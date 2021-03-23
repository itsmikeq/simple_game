//
// Created by Mike Quinn on 3/19/21.
//

#include "AirplaneCabin.h"
AirplaneCabin::AirplaneCabin(Player &player) : Scene(player) {
    this->saveFile = (std::string)"." + __func__ + ".dat";
    this->sceneName = "Airplane Cabin";
};