//
// Created by Mike Quinn on 3/19/21.
//

#ifndef SIMPLE_GAME_SCENE_H
#define SIMPLE_GAME_SCENE_H
/*
 * Here we keep all of the scene information:
 * Locations of things
 * Links to previous and next scene
 * player and monster(s)
 *
 */
#include <iostream>
#include <vector>
#include "Player.h"

class Scene {
public:
    Player player;
    Scene *fromScene; // prior scene

//    std::ostream &serialize(std::ostream &os) const override {
//        player.serialize(os);
//        // Exposition only. Maybe provide default serialization for things like std::vector and iterators.
//        for (const auto &scene : scenes) {
//            scene->serialize(os);
//        }
//        return os;
//    }

private:
    std::vector<std::shared_ptr<Scene>> scenes;
};

#endif //SIMPLE_GAME_SCENE_H
