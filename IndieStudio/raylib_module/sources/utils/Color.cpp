/*
** EPITECH PROJECT, 2021
** Color.cpp
** File description:
** Color.cpp
*/

#include "utils/Color.hpp"

ray::RColor::RColor() :
m_color(WHITE)
{}

void ray::RColor::setColor(int red, int blue, int green, int alpha = 255)
{
    m_color.r = red;
    m_color.g = green;
    m_color.b = blue;
    m_color.a = alpha;
}


void ray::RColor::setColor(Color color)
{
    m_color = color;
}

Color ray::RColor::getColor() const
{
    return (m_color);
}