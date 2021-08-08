/*
** EPITECH PROJECT, 2021
** Main.cpp
** File description:
** Main.cpp
*/

#ifndef LOGO_HPP
#define LOGO_HPP

#include "SW/Components.hpp"

class Logo :
        public sw::Script
{
private:
    enum {
        FADE_IN,
        STAY,
        FADE_OUT
    } m_state;
public:
    explicit Logo(sw::Entity& entity);
    ~Logo() override = default;

    void start() override;
    void update() override;
};

#endif //LOGO_HPP
