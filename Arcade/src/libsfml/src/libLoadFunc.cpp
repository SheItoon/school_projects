/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libLoadFunc.cpp
*/

#include <iostream>

#include "../inc/SfmlModule.hpp"

__attribute__((constructor))
void libSfml_constructor()
{
    printf("[Sfml Module] Starting SFML module...\n");
}

__attribute__((destructor))
void libSfml_destructor()
{
    printf("[Sfml Module] SFML module stopped.\n");
}

extern "C" void *entryPoint()
{
    auto *module = new sfml::SfmlModule();

    std::cout << module->getName() << " Entrypoint created." << std::endl;
    return (module);
}