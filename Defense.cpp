//
// Created by Mike Quinn on 3/16/21.
//

#include <memory>
#include "Defense.h"

Defense::Defense() {
}

NoneShield::NoneShield() {
    ShieldDefenses s;
    this->points = s.none;
    this->name = "None";
}

ArmShield::ArmShield() {
    ShieldDefenses s;
    this->points = s.arms;
    this->name = "Arms";
}

WoodShield::WoodShield() {
    ShieldDefenses s;
    this->points = s.wood;
    this->name = "Wood Shield";
}

BronzeShield::BronzeShield() {
    ShieldDefenses s;
    this->points = s.bronze;
    this->name = "Bronze Shield";
}

SteelShield::SteelShield() {
    ShieldDefenses s;
    this->points = s.steel;
    this->name = "Steel Shield";
}

Tungsten::Tungsten() {
    ShieldDefenses s;
    this->points = s.tungsten;
    this->name = "Tungsten Shield";
}
