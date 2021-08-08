/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** sdlLoadFunc.cpp
*/

#include <iostream>

#include "../inc/SdlModule.hpp"

__attribute__((constructor))
void libSdl_constructor()
{
    std::cout << "[Sdl Module] Starting Sdl Module..." << std::endl;
}

__attribute__((destructor))
void libSdl_destructor()
{
    std::cout << "[Sdl Module] Sdl Module stopped." << std::endl;
}

extern "C" void *entryPoint()
{
    auto *module = new sdl::SdlModule();

    std::cout << module->getName() << " Entrypoint created." << std::endl;
    return (module);
}