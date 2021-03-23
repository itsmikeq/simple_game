//
// Created by Mike Quinn on 3/19/21.
//

#include "AirplaneHanger.h"

AirplaneHanger::AirplaneHanger(Player &player) : Scene(player) {
    std::cout << "YEET " << __func__ << std::endl;
    this->saveFile = (std::string)"." + __func__ + ".dat";
    this->sceneName = "Airplane Hanger";
};
