/*
** EPITECH PROJECT, 2021
** BillBoard.cpp
** File description:
** BillBoard.cpp
*/

#include "component/BillBoard.hpp"

ray::BillBoard::BillBoard(sw::Entity &entityRef) :
sw::Component(entityRef),
m_texture(dynamic_cast<ray::RTexture&>(m_entity.m_scene.getTexture("MissingTexture")))
{}

ray::BillBoard & ray::BillBoard::setTexture(std::string name)
{
    m_texture = dynamic_cast<ray::RTexture&>(m_entity.m_scene.getTexture(name));
    return (*this);
}

ray::RTexture& ray::BillBoard::getTexture()
{
    return (m_texture);
}