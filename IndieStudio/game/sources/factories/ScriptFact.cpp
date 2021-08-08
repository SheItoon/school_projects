/*
** EPITECH PROJECT, 2021
** ScriptFact.cpp
** File description:
** ScriptFact.cpp
*/

#include "factory/ScriptFact.hpp"
#include "component/Script.hpp"

void sw::ScriptFact::onLoad()
{
    for (auto& [_, script] : m_componentMap)
        script->start();
}

void sw::ScriptFact::onUnload()
{

}