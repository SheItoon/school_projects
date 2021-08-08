/*
** EPITECH PROJECT, 2021
** Audio.cpp
** File description:
** Audio.cpp
*/

#include "component/Audio.hpp"

#include <utility>

ray::Audio::Audio(sw::Entity &entityRef) :
sw::Component(entityRef),
m_sound(),
m_volume(100),
m_pitch(1.0f)
{}

void ray::Audio::play(const std::string& name)
{
    SetSoundVolume(m_sound[name], m_volume / 100);
    SetSoundPitch(m_sound[name], m_pitch);
    PlaySoundMulti(m_sound[name]);
}

float ray::Audio::getSoundTimeLength(const std::string& name)
{
    float totalSeconds = 0.0f;

    totalSeconds = (float)m_sound[name].sampleCount/(m_sound[name].stream.sampleRate*m_sound[name].stream.channels);

    return (totalSeconds);
}

void ray::Audio::playSolo(const std::string& name)
{
    if (!IsSoundPlaying(m_sound[name])) {
        SetSoundVolume(m_sound[name], m_volume / 100);
        SetSoundPitch(m_sound[name], m_pitch);
        PlaySound(m_sound[name]);
    }
}

ray::Audio & ray::Audio::addSound(std::string soundName, std::string name)
{
    auto& target_sound = dynamic_cast<ray::RSound &>(sw::Engine::activeScene().getSound(std::move(soundName)));

    m_sound.insert(std::pair<std::string, Sound>(name, *target_sound));
    return (*this);
}

ray::Audio & ray::Audio::setVolume(float volume)
{
    m_volume = volume;
    return (*this);
}

ray::Audio & ray::Audio::setPitch(float pitch)
{
    m_pitch = pitch;
    return (*this);
}