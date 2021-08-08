/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SdlModule.hpp
*/

#ifndef __SDL_MODULE_HPP__
#define __SDL_MODULE_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../../../inc/IDisplayModule.hpp"
#include "SdlKeyboard.hpp"
#include "SdlColor.hpp"

namespace sdl
{
    class SdlModule : public arc::IDisplayModule
    {
        private:
            std::string m_name;
            bool m_isOk;
            SDL_Window *m_window;
            Uint8 *m_keystate;
            SDL_Event m_event;
            SDL_Renderer *m_renderer;
            TTF_Font *m_font;

        public:
            SdlModule();
            ~SdlModule() override;
            std::string getName() const override;

            void clearWindow() override;
            void displayWindow() override;
            void checkEvent() override;
            bool isOk() override;
            bool getKeyDown(arc::Keyboard key) override;

            void drawText(const std::string& text, int characterSize, arc::Color color, arc::Vector<float> position) override;
            void drawSquare(int size, arc::Color color, arc::Vector<float> position) override;
    };
}

#endif // __SDL_MODULE_HPP__