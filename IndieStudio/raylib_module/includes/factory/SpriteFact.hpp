/*
** EPITECH PROJECT, 2021
** SpriteFact.hpp
** File description:
** SpriteFact.hpp
*/

#ifndef SPRITEFACT
#define SPRITEFACT

#include "SW/Factory.hpp"

namespace ray
{
    class Sprite;

    class SpriteFact :
        public sw::AFactory<Sprite>
    {
        public:
            using sw::AFactory<Sprite>::AFactory;

            void onLoad() override;
            void onUpdate() override;
            void onUnload() override;
    }; // class SpriteFact

} // namespace ray

#endif //SPRITEFACT
