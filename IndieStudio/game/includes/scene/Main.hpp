/*
** EPITECH PROJECT, 2021
** Main.cpp
** File description:
** Main.cpp
*/

#ifndef MAIN_SCENE
#define MAIN_SCENE

#include "SW/Scene.hpp"

class Main :
    public sw::AScene
{
public:
    using sw::AScene::AScene;
    static enum loadMode_e {
        NEW_GAME,
        LOADED
    } loadMode;
    void onLoad() override;
    void onUpdate() override;
    void onUnload() override;
};

#endif //MAIN_SCENE