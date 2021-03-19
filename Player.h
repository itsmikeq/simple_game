//
// Created by Mike Quinn on 3/16/21.
//

#ifndef SIMPLE_GAME_PLAYER_H
#define SIMPLE_GAME_PLAYER_H
#include <iostream>
#include "Weapon.h"
#include "Defense.h"

class Player {
protected:

    int totalPower = 10;
    int killPoints; // how many damagePoints to award when this player is killed.
public:
    int remainingPower = totalPower;
    std::shared_ptr<Weapon> currentWeapon;
    std::shared_ptr<Defense> currentDefense;

    Player(int totalPower, const Weapon &currentWeapon, const Defense &defense);
    virtual void attack(Player &enemy);
    [[nodiscard]] float percentPowerRemaining() const;
    void equipWeapon(const Weapon &weapon);
    void equipDefense(const Defense &defense);

    void serialize(std::ostream &ostream);
};

class Archer : public Player {
public:
    Archer(int totalPower, const Weapon &currentWeapon, const Defense &defense);
};

class Gunman : public Player {
public:
    Gunman(int totalPower, const Weapon &currentWeapon, const Defense &defense);
};

class Swordsman : public Player {
public:
    Swordsman(int totalPower, const Weapon &currentWeapon, const Defense &defense);
};

class Slapper : public Player {
public:
    Slapper(int totalPower, const Weapon &currentWeapon, const Defense &defense);
};

class Batter : public Player {
public:
    Batter(int totalPower, const Weapon &currentWeapon, const Defense &defense);
};

class Boxer : public Player {
public:
    Boxer(int totalPower, const Weapon &currentWeapon, const Defense &defense);
};



#endif //SIMPLE_GAME_PLAYER_H
