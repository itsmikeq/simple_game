//
// Created by Mike Quinn on 3/16/21.
//

#include "Weapon.h"
#include "Damages.h"

#include <array>

Weapon::Weapon() {

}

std::string Weapon::name() const {
    return weapon_str(type).data();
}

Fist::Fist() {
    WeaponDamages w;
    this->damagePoints = w.fist;
    this->type = WeaponEnum::Fist;
}

Bat::Bat() {
    WeaponDamages w;
    this->damagePoints = w.bat;
    this->type = WeaponEnum::Bat;
}

Slap::Slap() {
    WeaponDamages w;
    this->damagePoints = w.slap;
    this->type = WeaponEnum::Slap;
}

Sword::Sword() {
    WeaponDamages w;
    this->damagePoints = w.sword;
    this->type = WeaponEnum::Sword;
}

Gun::Gun() {
    WeaponDamages w;
    this->damagePoints = w.gun;
    this->type = WeaponEnum::Gun;
}

Bow::Bow() {
    WeaponDamages w;
    this->damagePoints = w.bow;
    this->type = WeaponEnum::Bow;
}

std::once_flag weapons_generated;

WeaponEnum weapon_from_str(std::string_view str) {
    static std::array<std::string, std::size_t(WeaponEnum::_end)> weapons;
    std::call_once(weapons_generated, [] {
        for (std::size_t i = 0; i < std::size_t(WeaponEnum::_end); i++) {
            weapons[i] = weapon_str(WeaponEnum(i));
        }
    });
    for (std::size_t i = 0; i < weapons.size(); i++) {
        if (str == weapons[i]) {
            return WeaponEnum(i);
        }
    }

    return WeaponEnum::Unknown;
}
