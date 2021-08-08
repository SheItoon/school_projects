/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.hpp
*/

#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#include <string>
#include <array>

#include "../../../inc/IGame.hpp"
#include "Entity.hpp"

class PacMan :
    public arc::IGame
{
    private:
        Player player;
        std::array<Ghost, 4> ghosts;

        std::array<std::string, heightMap> m_map;
        int pacGumNb;

    public:
        PacMan();
        ~PacMan() = default;

        void start(arc::IDisplayModule *) override;
        void update(arc::IDisplayModule *) override;
        void terminate(arc::IDisplayModule* module) override;

        void playerTurn(arc::IDisplayModule *module);
        void ghostTurn();
        void checkBoth();
        void drawing(arc::IDisplayModule *module);
};

extern "C" void *entryPoint();

#endif // __PACMAN_HPP__
