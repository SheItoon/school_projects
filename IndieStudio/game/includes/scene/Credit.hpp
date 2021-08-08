/*
** EPITECH PROJECT, 2021
** Credit.cpp
** File description:
** Credit.cpp
*/

#ifndef CREDIT_HPP
#define CREDIT_HPP

#include "SW/Scene.hpp"

class CreditScene :
    public sw::AScene
{
    private:
        std::vector<std::string> m_url;
    public:
        using sw::AScene::AScene;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;
};

#endif //CREDIT_HPP
