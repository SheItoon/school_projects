/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libsfml.cpp
*/

#include <iostream>
#include <SFML/Window/Event.hpp>
#include <set>
#include "../inc/SfmlModule.hpp"
#include "../inc/SfmlColor.hpp"
#include "../inc/SfmlKeyboard.hpp"

sfml::SfmlModule::SfmlModule() :
    m_window(),
    m_name("libSfml"),
    m_font()
{
    std::cout << "[" << m_name << "] initializing..." << std::endl;
    m_font.loadFromFile("rsc/8bitPix.ttf");
    m_window.create({1920, 1080, 32}, "arcade_sfml");
}

sfml::SfmlModule::~SfmlModule()
{
    m_window.close();
    std::cout << "[" << m_name << "] stopping...\n";
}

std::string sfml::SfmlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

void sfml::SfmlModule::clearWindow()
{
    m_window.clear();
}

void sfml::SfmlModule::displayWindow()
{
    m_window.display();
}

void sfml::SfmlModule::checkEvent()
{
    while (m_window.pollEvent(m_event))
        if (m_event.type == sf::Event::Closed)
            m_window.close();
}

bool sfml::SfmlModule::isOk()
{
    return (m_window.isOpen());
}

void sfml::SfmlModule::drawText(const std::string& message, int size, arc::Color color, arc::Vector<float> position)
{
    sf::Text text(message, m_font, size);

    text.setFillColor(sfml::sfmlColorMap.find(color)->second);
    text.setPosition(position.x * 10, position.y * 10);
    m_window.draw(text);
}

void sfml::SfmlModule::drawSquare(int size, arc::Color color, arc::Vector<float> position)
{
    sf::RectangleShape shape({(float)size * 10, (float)size * 10});

    shape.setFillColor(sfml::sfmlColorMap.find(color)->second);
    shape.setPosition(position.x * 10, position.y * 10);
    m_window.draw(shape);
}

bool sfml::SfmlModule::getKeyDown(arc::Keyboard key)
{
    static std::set<arc::Keyboard> list;
    auto value = sfml::keyboardMap.find(key)->second;

    if (list.find(key) == list.end() && sf::Keyboard::isKeyPressed(value)) {
        list.insert(key);
        return (true);
    }
    else if (!sf::Keyboard::isKeyPressed(value)) {
        auto it = list.find(key);
        if (it != list.end())
            list.erase(it);
    }
    return (false);
}