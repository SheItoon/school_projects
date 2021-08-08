/*
** EPITECH PROJECT, 2021
** Audio.hpp
** File description:
** Audio.hpp
*/

#ifndef MUSIC_HPP
#define MUSIC_HPP

#include "raylib.h"
#include "SW/Components.hpp"
#include "resources/Music.hpp"

namespace ray
{
    class MusicStream :
            public sw::Component
    {
    private:
        std::map<std::string, std::shared_ptr<Music>> m_music;
        float m_volume;
        float m_pitch;
        std::string m_playing;

    public:
        ////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param engine
        /// \param entity
        ////////////////////////////////////////////////////////////////////////////
        explicit MusicStream(sw::Entity& entityRef);

        ////////////////////////////////////////////////////////////////////////////
        /// \brief Play the audio you want with the specified name
        ///
        /// \param name
        ////////////////////////////////////////////////////////////////////////////
        void play(std::string name);

        void pause();

        void stop();

        ////////////////////////////////////////////////////////////////////////////
        /// \brief Add audio on your component with specified name
        ///
        /// \param sound
        /// \param name
        /// \return the component
        MusicStream& addSound(std::string soundName, std::string name);

        MusicStream& setVolume(float volume);
        MusicStream& setVolumeDown(float volume);
        MusicStream& setVolumeUp(float volume);
        MusicStream& setPitch(float pitch);

        [[nodiscard]]std::shared_ptr<Music> getMusic() const;
        [[nodiscard]]float getPitch() const;
        [[nodiscard]]float getVolume() const;
    };
} // namespace ray

#endif //MUSIC_HPP
