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
#include <fstream>
#include <unistd.h>
#include <typeinfo>

#include "Player.h"
#include <pwd.h>


class Scene {
public:
    Scene(Player &player);

    Player *player;
    Scene *fromScene; // prior scene
    Scene *nextScene; // set when we have another scene to go to
    std::string saveFile = "save_file.dat";
    std::string sceneName;
    std::filesystem::path saveFilePath;

    void loadFromDisk();

    void saveToDisk();

    void setFromScene(Scene scene);

    void setNextScene(Scene scene);


private:
    std::vector<std::shared_ptr<Scene>> scenes;

};

#endif //SIMPLE_GAME_SCENE_H
