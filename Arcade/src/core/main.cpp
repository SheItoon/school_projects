/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** main.cpp
*/

#include <iostream>
#include "../../inc/IDisplayModule.hpp"
#include "../../inc/IGame.hpp"
#include "../../inc/DLLoader.hpp"
#include "../../inc/Chrono.hpp"
#include "../../inc/DLManager.hpp"
#include "../../inc/Interface.hpp"

void arc::GameLoop(arc::DLManager& manager, arc::Interface& interface)
{
    if (manager.getGraphicsInstance()->getKeyDown(arc::P)) {
        manager.getGameInstance()->terminate(manager.getGraphicsInstance());
        manager.state = arc::DLManager::MENU;
    }
    if (manager.getGraphicsInstance()->getKeyDown(arc::N)) {
        interface.m_libIndex = (interface.m_libIndex == (int)interface.m_lib.size() - 1) ? 0 : interface.m_libIndex + 1;
        manager.ChangeGraphicModule(interface.m_lib.at(interface.m_libIndex));
    }
    if (manager.getGraphicsInstance()->getKeyDown(arc::B)) {
        interface.m_libIndex = (interface.m_libIndex == 0) ? (int)interface.m_lib.size() - 1 : interface.m_libIndex - 1;
        manager.ChangeGraphicModule(interface.m_lib.at(interface.m_libIndex));
    }
    if (manager.getGraphicsInstance()->getKeyDown(arc::V)) {
        interface.m_gameIndex = (interface.m_gameIndex == (int)interface.m_game.size() - 1) ? 0 : interface.m_gameIndex + 1;
        manager.ChangeGameModule(interface.m_game.at(interface.m_gameIndex));
    }
    if (manager.getGraphicsInstance()->getKeyDown(arc::C)) {
        interface.m_gameIndex = (interface.m_gameIndex == 0) ? (int)interface.m_game.size() - 1 : interface.m_gameIndex - 1;
        manager.ChangeGameModule(interface.m_game.at(interface.m_gameIndex));
    }
    if (manager.getGraphicsInstance()->getKeyDown(arc::R))
        manager.ChangeGameModule(interface.m_game.at(interface.m_gameIndex));
    manager.getGameInstance()->update(manager.getGraphicsInstance());
}

int main(int ac, char **av)
{
    arc::Interface interface;

    if (ac != 2) {
        std::cout << "Usage:" << std::endl << "\t./arcade [GRAPHICAL_LIBRARY]" << std::endl
        << std::endl << "\tGRAPHICAL_LIBRARY:\t- see the lib folder to see the list of the graphical library" << std::endl;
        return (84);
    }
    try {
        arc::DLManager manager(av[1]);

        arc::Chrono clock;

        clock.start();
        interface.start(manager.getGraphicsInstance());
        while (manager.getGraphicsInstance()->isOk()) {
            if (clock.getElapsedTime() < 0.03)
                continue;
            if (manager.state == arc::DLManager::MENU) {
                interface.update(manager.getGraphicsInstance(), manager);
            } else if (manager.state == arc::DLManager::GAME)
                arc::GameLoop(manager, interface);
            manager.updateGraphics();
            manager.updateGame();
            clock.tour();
        }
        clock.stop();
    } catch (const arc::Error &e) {
        std::cout << "Error: " << e << std::endl;
        return (84);
    }
    return (0);
}