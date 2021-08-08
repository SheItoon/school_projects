/*
** EPITECH PROJECT, 2021
** MenuSelect.hpp
** File description:
** MenuSelect.hpp
*/

#ifndef MENUSELECT_HPP
#define MENUSELECT_HPP

#include "SW/Scene.hpp"

class MenuSelect :
    public sw::AScene
{
public:
    using sw::AScene::AScene;

    void onLoad() override;
    void onUpdate() override;
    void onUnload() override;
};

#endif //MENUSELECT_HPP
