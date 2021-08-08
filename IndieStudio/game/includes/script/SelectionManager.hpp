/*
** EPITECH PROJECT, 2021
** SelectionManager.hpp
** File description:
** SelectionManager.hpp
*/

#ifndef SELECTIONMANAGER_HPP
#define SELECTIONMANAGER_HPP

#include "SW/Components.hpp"
#include "utils/Chrono.hpp"

class SelectionManager : public sw::Script
{
private:
    bool m_selected;
    bool m_changed;
    int m_index;
    sw::Chrono m_chrono;
    int m_nbrPlayer;

    void startGame();
    void getInformation();
    void doAction();

public:
    explicit SelectionManager(sw::Entity& entity);
    ~SelectionManager() override = default;
    void start() override;
    void update() override;
    void resetSelection();
    void addPlayer();
    void removePlayer();
}; // class Player

#endif //SELECTIONMANAGER_HPP
