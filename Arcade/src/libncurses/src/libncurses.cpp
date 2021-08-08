/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libncurses.cpp
*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "../inc/NcursesModule.hpp"
#include "../inc/NcursesKeyboard.hpp"

ncs::NcursesModule::NcursesModule() :
    m_isOk(true),
    m_name("Ncurses"),
    m_key(0)
{
    std::cout << this->getName() << " initializing..." << std::endl;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    timeout(0);
    curs_set(false);
    start_color();
    init_pair(arc::BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(arc::RED, COLOR_BLACK, COLOR_RED);
    init_pair(arc::GREEN, COLOR_BLACK, COLOR_GREEN);
    init_pair(arc::YELLOW, COLOR_BLACK, COLOR_YELLOW);
    init_pair(arc::BLUE, COLOR_BLACK, COLOR_BLUE);
    init_pair(arc::MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(arc::CYAN, COLOR_BLACK, COLOR_CYAN);
    init_pair(arc::WHITE, COLOR_BLACK, COLOR_WHITE);
    init_pair(arc::ORANGE, COLOR_BLACK, COLOR_RED);
}

ncs::NcursesModule::~NcursesModule()
{
    std::cout << this->getName() << " stopping...\n";
    curs_set(true);
    endwin();
}

std::string ncs::NcursesModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

void ncs::NcursesModule::clearWindow()
{
    clear();
}

void ncs::NcursesModule::displayWindow()
{
    refresh();
}

void ncs::NcursesModule::checkEvent()
{
    m_key = getch();

    if (m_key == 'l')
        m_isOk = false;
}

bool ncs::NcursesModule::isOk()
{
    return (m_isOk);
}

void ncs::NcursesModule::drawText(const std::string& message, int size, arc::Color color, arc::Vector<float> position)
{
    (void)size;
    attron(COLOR_PAIR(color));
    mvprintw(position.y, position.x, message.c_str());
    attron(COLOR_PAIR(arc::BLACK));
}

void ncs::NcursesModule::drawSquare(int size, arc::Color color, arc::Vector<float> position)
{
    size /= 2;
    position.x /= 3;
    position.y /= 3;
    attron(COLOR_PAIR(color));
    for (int line = 0; line < size; line += 1)
        for (int col = 0; col < size; col += 1)
            mvprintw(position.y + line, position.x + col, " ");
    attron(COLOR_PAIR(arc::BLACK));
}

bool ncs::NcursesModule::getKeyDown(arc::Keyboard key)
{
    if (m_key == ncs::keyboardMap.find(key)->second)
        return (true);
    return (false);
}