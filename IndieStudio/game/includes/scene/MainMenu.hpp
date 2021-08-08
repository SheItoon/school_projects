/*
** EPITECH PROJECT, 2021
** MainMenu.hpp
** File description:
** MainMenu.hpp
*/

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "SW/Scene.hpp"

class MainMenu :
    public sw::AScene
{
public:
    using sw::AScene::AScene;

    void onLoad() override;
    void onUpdate() override;
    void onUnload() override;
};

#endif //MAINMENU_HPP
