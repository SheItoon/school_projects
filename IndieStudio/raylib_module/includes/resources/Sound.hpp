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
    class RSound :
            public sw::ISound
    {
        private:
            Sound m_sound;

        public:
            RSound() = default;
            explicit RSound(Sound music);
            ~RSound() noexcept override;

            Sound operator*();
    }; // class RSound

} // namespace ray

#endif //SOUND
