/*
** EPITECH PROJECT, 2021
** Texture.hpp
** File description:
** Texture.hpp
*/

#ifndef FONT
#define FONT

#include "raylib.h"
#include "SW/Resources.hpp"

namespace ray
{
    class RFont : public sw::IFont
    {
        private:
            Font m_font;

        public:
            explicit RFont(Font font);
            ~RFont() noexcept override;

            Font operator*() const;
    };
}

#endif //FONT
