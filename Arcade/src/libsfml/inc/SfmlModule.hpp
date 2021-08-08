/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SfmlModule.hpp
*/

#ifndef __SFML_MODULE_H__
#define __SFML_MODULE_H__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/Color.hpp"

namespace sfml
{
    class SfmlModule :
        public arc::IDisplayModule
    {

        private:
            sf::RenderWindow m_window;
            sf::Event m_event;
            std::string m_name;
            sf::Font m_font;

        public:
            SfmlModule();
            ~SfmlModule() override;
            std::string getName() const override;

            void clearWindow() override;
            void displayWindow() override;
            void checkEvent() override;
            bool isOk() override;
            bool getKeyDown(arc::Keyboard key) override;

            void drawText(const std::string& text, int characterSize, arc::Color color, arc::Vector<float> position) override;
            void drawSquare(int size, arc::Color color, arc::Vector<float> position) override;

    }; // class SfmlModule

} // namespace sfml

extern "C" void *entryPoint();

#endif // __SFML_MODULE_H__