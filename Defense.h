//
// Created by Mike Quinn on 3/16/21.
//

#ifndef SIMPLE_GAME_DEFENSE_H
#define SIMPLE_GAME_DEFENSE_H
#include <iostream>

struct ShieldDefenses {
    const int none = 0;
    const int arms = 1;
    const int wood = 2;
    const int bronze = 3;
    const int steel = 4;
    const int tungsten = 5;
};

class Defense {
public:
    int points = 0;
    int life = 100;
    std::string name;
    Defense();
};

class NoneShield : public Defense {
public:
    NoneShield();
};

class WoodShield : public Defense {
public:
    WoodShield();
};

class ArmShield : public Defense {
public:
    ArmShield();
};

class BronzeShield : public Defense {
public:
    BronzeShield();
};

class SteelShield : public Defense {
public:
    SteelShield();
};

class Tungsten: public Defense {
public:
    Tungsten();
};


#endif //SIMPLE_GAME_DEFENSE_H
