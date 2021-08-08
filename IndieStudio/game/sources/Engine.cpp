/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Engine.cpp
*/

#include "Module.hpp"
#include "SW/Engine.hpp"

///////////////////////////////////////////////////////////////////////////////
///
///     Initialize your Module here
//
void sw::Engine::onInitialize()
{
    sw::Engine::createModule<ray::Module>("RayLib");
}

///////////////////////////////////////////////////////////////////////////////
///
///     Update your Module here
//
void sw::Engine::onUpdate()
{

}

///////////////////////////////////////////////////////////////////////////////
///
///     Terminate your Module here
//
void sw::Engine::onTerminate()
{

}