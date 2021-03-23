//
// Created by Mike Quinn on 3/22/21.
//

#include "LowerDeck.h"

LowerDeck::LowerDeck(Player &player) : Scene(player) {
    this->saveFile = (std::string)"." + __func__ + ".dat";
    this->sceneName = "Lower Airplane Deck";
};
