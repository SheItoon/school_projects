/*
** ShipWreck engine, 2021
** script.cpp.c
*/

#include "factory/ScriptFact.hpp"
#include "component/Script.hpp"

void sw::ScriptFact::onUpdate()
{
    for (auto&[name, obj] : m_componentMap) {
        if (obj->isActive() && obj->m_entity.isActive())
            obj->update();
    }
}