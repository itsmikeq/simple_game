//
// Created by Mike Quinn on 3/19/21.
//

#include "Scene.h"
#include <pwd.h>

namespace fs = std::filesystem;

//struct SceneSerialized {
//    Player *player;
//    Scene *fromScene; // prior scene
//    Scene *nextScene; // set when we have another scene to go to
//    std::string saveFile ;
//    std::string sceneName;
//
//};

Scene::Scene(Player &player) : player(&player) {
    this->saveFile = ".savefile.dat";
    this->loadFromDisk();
};

void Scene::setFromScene(Scene scene) {
    this->fromScene = &scene;
}

void Scene::setNextScene(Scene scene) {
    this->nextScene = &scene;
}

void Scene::loadFromDisk() {
    std::cout << "Loading" << std::endl;
    std::ifstream saveFileStream(this->saveFile, std::ios::in | std::ios::binary);
    if (access(this->saveFile.c_str(), F_OK) == -1 || !saveFileStream.is_open()) return;
    std::string line;
    while (getline(saveFileStream, line)) {
        std::cout << line << '\n';
    }
    saveFileStream.close();
}

void Scene::saveToDisk() {
    std::cout << "Saving " << this->saveFile << std::endl;
//    std::string path_string{this->saveFilePath.u8string()};
    std::cout << "PATH: " << this->saveFile << std::endl;
    std::ofstream saveFileStream;
    saveFileStream.open(this->saveFile, std::ios::out | std::ios::binary);
    saveFileStream << "Writing this to a file.\n";
    saveFileStream.close();
}
