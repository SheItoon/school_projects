/*
** EPITECH PROJECT, 2021
** Audio.hpp
** File description:
** Audio.hpp
*/

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "raylib.h"
#include "SW/Components.hpp"
#include "resources/Sound.hpp"

namespace ray
{
    class Audio :
        public sw::Component
    {
    private:
        std::map<std::string, Sound> m_sound;
        float m_volume;
        float m_pitch;

    public:
        ////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param engine
        /// \param entity
        ////////////////////////////////////////////////////////////////////////////
        explicit Audio(sw::Entity& entityRef);

        ////////////////////////////////////////////////////////////////////////////
        /// \brief Play the audio you want with the specified name
        ///
        /// \param name
        ////////////////////////////////////////////////////////////////////////////
        void play(const std::string& name);

        ////////////////////////////////////////////////////////////////////////////
        /// \brief Play the audio you want in the current thread with the specified name
        ///
        /// \param name
        ////////////////////////////////////////////////////////////////////////////
        void playSolo(const std::string& name);

        ////////////////////////////////////////////////////////////////////////////
        /// \brief Add audio on your component with specified name
        ///
        /// \param sound
        /// \param name
        /// \return the component
        Audio& addSound(std::string soundName, std::string name);

        ////////////////////////////////////////////////////////////////////////////
        /// \brief Return the length of the specified sound
        ///
        /// \param name
        /// \return length of the sound in seconds
        float getSoundTimeLength(const std::string& name);

        Audio& setVolume(float volume);
        Audio& setPitch(float pitch);
    };
} // namespace ray

#endif //AUDIO_HPP
