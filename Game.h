//
// Created by Mike Quinn on 3/18/21.
//

#ifndef SIMPLE_GAME_GAME_H
#define SIMPLE_GAME_GAME_H


#include "Player.h"
#include "Scene.h"

typedef std::vector<std::string> SceneOptionsT;
typedef std::vector<std::string> SceneQuestionsT;

// Should we pass around a struct instead? 
typedef struct {
    Player &player;
    Scene &fromScene;
    Scene &nextScene;
    Scene &currentScene;
    std::string screenTitle;
    SceneOptionsT sceneOptions;
} SceneStruct;

class Game {
public:
    bool playerIsDead = false;
    Player currentPlayer;
    Scene *currentScene;
    Scene *nextScene;

    explicit Game(const Player &currentPlayer);

    void selectWeapon(Weapon &weapon);

    void uiWeapon(std::string *weapon_);
    void setSceneSetting(std::string setting) const;

    void sceneQuestions();
    void setSceneQuestions(SceneQuestionsT &questions);
};

struct GameT {
    bool playerIsDead = false;
    int score = 0; // increment when an enemy is attacked.
};


#endif //SIMPLE_GAME_GAME_H
