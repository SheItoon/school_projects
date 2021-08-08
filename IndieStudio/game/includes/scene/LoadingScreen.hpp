/*
** EPITECH PROJECT, 2021
** Main.cpp
** File description:
** Main.cpp
*/

#ifndef LOADINGSCREEN_HPP
#define LOADINGSCREEN_HPP

#include "SW/Scene.hpp"

class LoadingScene :
public sw::AScene
{
public:
    using sw::AScene::AScene;
    void onLoad() override;
    void onUpdate() override;
    void onUnload() override;
};

#endif //LOADINGSCREEN_HPP
