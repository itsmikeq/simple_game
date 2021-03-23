//
// Created by Mike Quinn on 3/22/21.
//

#include "AirplaneLuggageArea.h"
AirplaneLuggageArea::AirplaneLuggageArea(Player &player) : Scene(player) {
    this->saveFile = (std::string)"." + __func__ + ".dat";
    this->sceneName = "Airplane Hanger";
};
