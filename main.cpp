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

int main() {
    auto player = Player(10, Bat(), NoneShield());
    auto enemy = Player(10, Fist(), NoneShield());
    Game * g = new Game(player);

    WeaponEnum weapon;
    do {
        printer("Select your weapon ");
        std::string s = collectInput();
        weapon = weapon_from_str(s);
        switch (weapon) {
            case WeaponEnum::Fist:
                player.equipWeapon(Fist());
                break;
            case WeaponEnum::Bat:
                player.equipWeapon(Bat());
                break;
            case WeaponEnum::Slap:
                player.equipWeapon(Slap());
                break;
            case WeaponEnum::Sword:
                player.equipWeapon(Sword());
                break;
            case WeaponEnum::Bow:
                player.equipWeapon(Bow());
                break;
            case WeaponEnum::Gun:
                player.equipWeapon(Gun());
                break;
            default:
                cout << "That's not a weapon!\n";
        }
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
