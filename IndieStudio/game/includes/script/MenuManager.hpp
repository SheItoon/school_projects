/*
** EPITECH PROJECT, 2021
** MenuManager.hpp
** File description:
** MenuManager.hpp
*/

#ifndef MENUMANAGER_HPP
#define MENUMANAGER_HPP

#include "component/components.hpp"
#include "utils/Chrono.hpp"

class MenuManager : public sw::Script
{
private:
    std::string m_play;
    std::string m_option;
    std::string m_exit;
    std::string m_credit;
    std::string m_load;
    unsigned int m_index;
    bool m_changed;
    bool m_selected;
    sw::Chrono m_chrono;

    void doAction();
public:
    explicit MenuManager(sw::Entity& entity);
    ~MenuManager() override = default;
    void start() override;
    void update() override;

    void resetSelection();
};

#endif //MENUMANAGER_HPP
