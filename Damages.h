//
// Created by Mike Quinn on 3/16/21.
//

#ifndef SIMPLE_GAME_DAMAGES_H
#define SIMPLE_GAME_DAMAGES_H

//struct Bow {
//    const int damage = 1;
//    const int distance = 2;
//    const string name = "";
//};

struct WeaponDamages {
    const int fist = 1;
    const int bat = 2;
    const int slap = 3;
    const int sword = 4;
    const int bow = 4;
    const int gun = 10;
};

struct ShieldDefenses {
    const int none = 0;
    const int arms = 1;
    const int wood = 2;
    const int bronze = 3;
    const int steel = 4;
    const int tungsten = 5;
};

#endif //SIMPLE_GAME_DAMAGES_H
