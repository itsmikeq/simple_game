#include <iostream>
#include "Player.h"
#include "utils.hpp"
#include "Game.h"

using namespace std;

void printPower(Player &player) {
    cout << (int) player.percentPowerRemaining() << "% damagePoints left";
}

template<typename T>
void printer(T t) {
    cout << t << endl;
}

template <typename T, typename ...U>
void printer(T t, U ...u)
{
    cout << t;
    printer(u...);
}

std::string collectInput(){
    string stuff_;
    cin >> stuff_;
    stuff_ = choppa(stuff_, " ");
    return stuff_;
}

Weapon makeWeapon(WeaponEnum weapon) {
    switch (weapon) {
        case WeaponEnum::Fist:
            return Fist();
        case WeaponEnum::Bat:
            return Bat();
        case WeaponEnum::Slap:
            return Slap();
        case WeaponEnum::Sword:
            return Sword();
        case WeaponEnum::Bow:
            return Bow();
        case WeaponEnum::Gun:
            return Gun();
        default:
            throw;
    }
}
int main(int argc, char *argv[]) {
    serialize(std::cout, Gun());
//    return 0;

    auto player = Player(10, Bat(), NoneShield());
    auto enemy = Player(10, Fist(), NoneShield());
    Game * g = new Game(player);

    WeaponEnum weapon;
    do {
        printer("Select your weapon ");
        std::string s = collectInput();
        weapon = weapon_from_str(s);

        if (weapon == WeaponEnum::Unknown) {
            cout << "That's not a weapon!\n";
            continue;
        }

        player.equipWeapon(makeWeapon(weapon));
    } while (weapon == WeaponEnum::Unknown);

//    cout << "selected " << weapon_str(weapon) << endl;
    cout << "selected " << player.currentWeapon->name() << endl;


//    enemy.attack(player);
//    player.attack(enemy);
//    player.equipWeapon(Gun());
//    cout << "my weapon damagePoints is " << player.currentWeapon->damagePoints << endl;
//    enemy.equipDefense(Tungsten());
//    enemy.equipWeapon(Gun());
//    cout << "enemy defense damagePoints is " << enemy.currentDefense->damagePoints << endl;
//
//    player.attack(enemy);
//    enemy.attack(player);
//    cout << "Enemy now has " << enemy.remainingPower << endl;
//    cout << "I have " << player.remainingPower << " left" << endl;
    return 0;
}
