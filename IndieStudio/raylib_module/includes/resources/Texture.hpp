/*
** EPITECH PROJECT, 2021
** Texture.hpp
** File description:
** Texture.hpp
*/

#ifndef TEXTURE
#define TEXTURE

#include <raylib.h>
#include "SW/Resources.hpp"

namespace ray
{
    class RTexture : public sw::ITexture
    {
        private:
            Texture2D m_texture;

        public:
            explicit RTexture(Texture2D texture);
            ~RTexture() noexcept override;

            Texture2D operator*() const;
    };
}

#endif //TEXTURE
