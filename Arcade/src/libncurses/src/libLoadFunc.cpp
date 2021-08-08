/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libLoadFunc.cpp
*/

#include <iostream>
#include "../inc/NcursesModule.hpp"

__attribute__((constructor))
void libNcurses_constructor()
{
    std::cout << "[Ncurses Module] Starting Ncurses Module..." << std::endl;
}

__attribute__((destructor))
void libNcurses_destructor()
{
    std::cout << "[Ncurses Module] Ncurses Module stopped." << std::endl;
}

extern "C" void *entryPoint()
{
    auto *module = new ncs::NcursesModule();

    std::cout << module->getName() << " Entrypoint created." << std::endl;
    return (module);
}