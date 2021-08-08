/*
** EPITECH PROJECT, 2021
** AudioFact.hpp
** File description:
** AudioFact.hpp
*/

#ifndef MUSICFACT_HPP
#define MUSICFACT_HPP

#include "SW/Factory.hpp"

namespace ray
{

    class MusicStream;

    class MusicFact :
            public sw::AFactory<MusicStream>
    {
    public:
        using AFactory<MusicStream>::AFactory;

        void onLoad() override {};
        void onUpdate() override;
        void onUnload() override {};

    }; // class MusicFact

} // namespace ray

#endif //MUSICFACT_HPP
