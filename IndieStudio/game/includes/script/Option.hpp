/*
** EPITECH PROJECT, 2021
** Option.h
** File description:
** Option.h
*/

#ifndef OPTION_HPP
#define OPTION_HPP

#include "SW/Components.hpp"

class Option : public sw::Script
{
private:
    int m_index;
    enum {
        HIDE,
        SHOW
    } m_state;
    bool m_changed;
    bool m_selected;
public:
    explicit Option(sw::Entity& entity);
    ~Option() override = default;

    void start() override;
    void update() override;
    void doAction();

    void show();
    void hide();
};


#endif //OPTION_HPP
