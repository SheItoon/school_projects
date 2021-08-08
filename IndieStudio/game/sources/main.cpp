/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#ifdef WIN32
#include <windows.h>
extern "C"
{
    __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
    __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}
#endif
#include "engine/Engine.hpp"

int main()
{
    sw::Engine::initialize();
    sw::Engine::update();
    //sw::Engine::terminate();
    return (0);
}
