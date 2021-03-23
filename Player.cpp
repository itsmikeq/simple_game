//
// Created by Mike Quinn on 3/16/21.
//

#include "Player.h"
#include "Weapon.h"
#include "Defense.h"

using namespace std;

Player::Player(int totalPower, const Weapon &currentWeapon, const Defense &currentDefense) :
        totalPower{totalPower},
        remainingPower{totalPower},
        currentWeapon{std::make_shared<Weapon>(currentWeapon)},
        currentDefense{std::make_shared<Defense>(currentDefense)} {}

void Player::attack(Player &enemy) {
    cout << "player weapon damagePoints " << this->currentWeapon->damagePoints << endl;
    cout << "enemy defense damagePoints " << enemy.currentDefense->points << endl;
    int totalDamage = (this->currentWeapon->damagePoints - enemy.currentDefense->points);
    cout << "Total damage " << totalDamage << endl;
    if (totalDamage > 0) {
        enemy.remainingPower = enemy.remainingPower - totalDamage;
    }
}

float Player::percentPowerRemaining() const {
    auto pwr = ((float) this->remainingPower / (float) this->totalPower) * 100;
    if (pwr > 0.0 && pwr < 100.00) {
        return pwr;
    } else if (pwr < 0.0) {
        return 0.0;
    } else {
        return 100.00;
    };
}

void Player::equipWeapon(const Weapon &weapon) {
    cout << "Changing weapon power to " << weapon.damagePoints << endl;
    this->currentWeapon = std::make_shared<Weapon>(weapon);
}

void Player::equipDefense(const Defense &defense) {
    this->currentDefense = std::make_shared<Defense>(defense);
}

std::ostream &Player::serialize(ostream &os) {
    // TODO implement serialization for Player
    return os;
}

Archer::Archer(int totalPower, const Weapon &currentWeapon, const Defense &currentDefense)
        : Player(totalPower, currentWeapon, currentDefense) {
    this->equipDefense(ArmShield());
    this->equipWeapon(Bow());
    this->totalPower = 5;
}

Gunman::Gunman(int totalPower, const Weapon &currentWeapon, const Defense &currentDefense)
        : Player(totalPower, currentWeapon, currentDefense) {
    this->equipDefense(ArmShield());
    this->equipWeapon(Bow());
    this->totalPower = 5;
}

Swordsman::Swordsman(int totalPower, const Weapon &currentWeapon, const Defense &defense)
        : Player(totalPower,
                 currentWeapon,
                 defense) {
    this->equipDefense(ArmShield());
    this->equipWeapon(Sword());
    this->totalPower = 5;
}

Batter::Batter(int totalPower, const Weapon &currentWeapon, const Defense &defense)
        : Player(totalPower, currentWeapon,
                 defense) {
    this->equipDefense(ArmShield());
    this->equipWeapon(Bat());
    this->totalPower = 6;
}

Slapper::Slapper(int totalPower, const Weapon &currentWeapon, const Defense &defense)
        : Player(totalPower,
                 currentWeapon, defense) {
    this->equipDefense(ArmShield());
    this->equipWeapon(Slap());
    this->totalPower = 4;
}

Boxer::Boxer(int totalPower, const Weapon &currentWeapon, const Defense &defense)
        : Player(totalPower,
                 currentWeapon, defense) {
    this->equipDefense(ArmShield());
    this->equipWeapon(Fist());
    this->totalPower = 4;
}
