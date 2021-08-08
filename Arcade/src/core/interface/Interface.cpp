/*
** EPITECH PROJECT, 2021
** Interface.cpp
** File description:
** Interface.cpp
*/

#include <iostream>
#include "../../../inc/Interface.hpp"

void arc::Interface::start(arc::IDisplayModule* module)
{
    (void)module;
    m_libIndex = 0;
    m_gameIndex = 0;
    getList();
}

void arc::Interface::drawText(arc::IDisplayModule* graph, int index, const std::string &name, bool game) const
{
    arc::Color color = ((game && index == m_gameIndex) || (!game && index == m_libIndex)) ? arc::BLUE : arc::WHITE;
    float xPos = (game) ? 100 : 50;

    graph->drawText(name, 50, color, {xPos, 25 + (float)(index * 5)});
    if (game) {
        graph->drawText("Score: ", 50, arc::Color::WHITE, {xPos + 30, 25 + (float)(index * 5)});
        graph->drawText(m_score.find(name)->second, 50, arc::Color::WHITE, {xPos + 55, 25 + (float)(index * 5)});
    }
}

static std::string FormatName(const std::string &path)
{
    auto index = path.find_last_of('_');
    auto lastIndex = path.length() - 4;
    std::string result = path.substr(index + 1, lastIndex - index);

    return (result);
}

void arc::Interface::checkInput(arc::IDisplayModule* graph, arc::DLManager& manager)
{
    if (graph->getKeyDown(arc::Up))
        m_libIndex = (m_libIndex == 0) ? (int)m_lib.size() - 1 : m_libIndex - 1;
    else if (graph->getKeyDown(arc::Down))
        m_libIndex = (m_libIndex == (int)m_lib.size() - 1) ? 0 : m_libIndex + 1;
    if (graph->getKeyDown(arc::Right))
        m_gameIndex = (m_gameIndex == 0) ? (int)m_game.size() - 1 : m_gameIndex - 1;
    else if (graph->getKeyDown(arc::Left))
        m_gameIndex = (m_gameIndex == (int)m_game.size() - 1) ? 0 : m_gameIndex + 1;
    if (graph->getKeyDown(arc::Backspace))
        manager.ChangeGraphicModule(m_lib.at(m_libIndex));
    if (graph->getKeyDown(arc::Enter)) {
        manager.ChangeGameModule(m_game.at(m_gameIndex));
        manager.state = arc::DLManager::GAME;
    }
}

void arc::Interface::update(arc::IDisplayModule* graph, arc::DLManager& manager)
{
    int index = 0;

    graph->clearWindow();
    graph->checkEvent();
    checkInput(graph, manager);
    graph->drawText(std::string("Welcome ") + m_score.find("username")->second, 50, arc::GREEN, {70, 5});
    graph->drawText(std::string("Library:"), 50, arc::WHITE, {50, 20});
    for (auto& name : m_lib) {
        drawText(graph, index, FormatName(name), false);
        index++;
    }
    index = 0;
    graph->drawText(std::string("Game:"), 50, arc::WHITE, {100, 20});
    for (auto& name : m_game) {
        drawText(graph, index, FormatName(name), true);
        index++;
    }
    graph->displayWindow();
}
