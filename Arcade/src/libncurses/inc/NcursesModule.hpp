/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** NcursesModule.hpp
*/

#ifndef __NCURSES_MODULE_HPP__
#define __NCURSES_MODULE_HPP__

#include <curses.h>
#include <unordered_map>
#include <memory>

#include "../../../inc/IDisplayModule.hpp"

namespace ncs
{
    class NcursesModule :
        public arc::IDisplayModule
    {

        private:
            bool m_isOk;
            std::string m_name;
            int m_key;

        public:
            NcursesModule();
            ~NcursesModule() override;
            std::string getName() const override;

            void clearWindow() override;
            void displayWindow() override;
            void checkEvent() override;
            bool isOk() override;
            bool getKeyDown(arc::Keyboard key) override;

            void drawText(const std::string& text, int characterSize, arc::Color color, arc::Vector<float> position) override;
            void drawSquare(int size, arc::Color color, arc::Vector<float> position) override;

    }; // class NcursesModule

} // namespace ncs

#endif // __NCURSES_MODULE_HPP__