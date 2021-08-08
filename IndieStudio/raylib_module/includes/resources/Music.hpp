/*
** EPITECH PROJECT, 2021
** Texture.hpp
** File description:
** Texture.hpp
*/

#ifndef SOUND
#define SOUND

#include "raylib.h"
#include "SW/Resources.hpp"

namespace ray
{
    class RMusic :
            public sw::IMusic
    {
        private:
            Music m_music;

        public:
            RMusic() = delete;
            RMusic(RMusic&&) = delete;
            RMusic(const RMusic&) = delete;
            explicit RMusic(Music music);
            ~RMusic() noexcept override;

            Music operator*();
    }; // class RSound

} // namespace ray

#endif //SOUND
