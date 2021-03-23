//
// Created by Mike Quinn on 3/22/21.
//

#ifndef SIMPLE_GAME_LOWERDECK_H
#define SIMPLE_GAME_LOWERDECK_H


#include <iostream>
#include "Player.h"
#include "Player.h"
#include "Scene.h"

class LowerDeck : public Scene{
public:
    explicit LowerDeck(Player &player);
};


#endif //SIMPLE_GAME_LOWERDECK_H
