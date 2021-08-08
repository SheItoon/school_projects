/*
** EPITECH PROJECT, 2021
** Text.cpp
** File description:
** Text.cpp
*/

#include "component/Text.hpp"

ray::Text::Text(sw::Entity &entity) :
sw::Component(entity),
m_text("Hello World"),
m_size(10),
m_font(dynamic_cast<RFont &>(sw::Engine::activeScene().getFont("Verdana"))),
m_spacing(1),
m_color(),
m_nbrDisplayedChar(m_text.size())
{
    m_color.setColor(WHITE);
}

ray::Text& ray::Text::setString(std::string message)
{
    m_text = std::move(message);
    setNbrDisplayedChar(m_text.size());
    return (*this);
}

ray::Text& ray::Text::setSize(float size)
{
    m_size = size;
    return (*this);

}

ray::Text& ray::Text::setFont(std::string fontName)
{
    m_font = dynamic_cast<RFont &>(m_entity.m_scene.getFont(std::move(fontName)));
    return (*this);
}

ray::Text& ray::Text::setSpacing(float spacing)
{
    m_spacing = spacing;
    return (*this);
}

ray::Text& ray::Text::setColor(Color color)
{
    m_color.setColor(color);
    return (*this);
}

ray::Text & ray::Text::setColor(int r, int g, int b, int a = 255)
{
    m_color.setColor(r, g, b, a);
    return (*this);
}

ray::Text& ray::Text::setNbrDisplayedChar(unsigned int nbr)
{
    m_nbrDisplayedChar = nbr;
    return (*this);
}

std::string ray::Text::getString() const
{
    return (m_text);
}

float ray::Text::getSize() const
{
    return (m_size);
}

ray::RFont ray::Text::getFont() const
{
    return (m_font);
}

float ray::Text::getSpacing() const
{
    return (m_spacing);
}

ray::RColor ray::Text::getColor() const
{
    return (m_color);
}

unsigned int ray::Text::getNbrDisplayedChar() const
{
    return (m_nbrDisplayedChar);
}