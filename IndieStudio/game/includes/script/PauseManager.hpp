/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** PauseManager.hpp
*/

#ifndef __PAUSEMENU_HPP__
#define __PAUSEMENU_HPP__

#include "SW/Components.hpp"

class PauseManager :
    public sw::Script
{

    private:
        unsigned m_index;
        bool m_changed;
        bool m_selected;
        bool m_isShow;
        enum {
            OPTION,
            NOTOPTION
        } m_state;

    public:

        PauseManager(sw::Entity& entity);
        ~PauseManager() = default;

        void start() override;
        void update() override;

        void doAction();
        void activation();
        void reset();

}; // class PauseManager

#endif // __PAUSEMENU_HPP__