/*
** EPITECH PROJECT, 2021
** AudioFact.hpp
** File description:
** AudioFact.hpp
*/

#ifndef AUDIOFACT_HPP
#define AUDIOFACT_HPP

namespace ray
{

    class Audio;

    class AudioFact :
            public sw::AFactory<Audio>
    {
    public:
        using AFactory<Audio>::AFactory;

        void onLoad() override {};
        void onUpdate() override {};
        void onUnload() override {};

    }; // class AudioFact

}

#endif //AUDIOFACT_HPP
