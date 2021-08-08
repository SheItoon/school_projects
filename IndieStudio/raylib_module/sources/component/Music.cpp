/*
** EPITECH PROJECT, 2021
** Music.cpp
** File description:
** Music.cpp
*/

#include "component/Music.hpp"

ray::MusicStream::MusicStream(sw::Entity &entityRef) :
sw::Component(entityRef),
m_music(),
m_volume(50),
m_pitch(1.0f),
m_playing()
{}

void ray::MusicStream::play(std::string name)
{
    if (m_playing != name) {
        PlayMusicStream(*m_music[name]);
        m_playing = name;
    }
}

ray::MusicStream & ray::MusicStream::addSound(std::string soundName, std::string name)
{
    auto& target_sound = dynamic_cast<ray::RMusic &>(m_entity.m_scene.getMusic(std::move(soundName)));

    m_music.insert(std::pair<std::string, std::shared_ptr<Music>>(name, std::make_shared<Music>(*target_sound)));
    return (*this);
}

ray::MusicStream & ray::MusicStream::setVolume(float volume)
{
    m_volume = volume;
    SetMusicVolume(*m_music.begin()->second, m_volume / 100);
    return (*this);
}

ray::MusicStream & ray::MusicStream::setVolumeDown(float volume)
{
    if (m_volume - volume <= 0)
        m_volume = 0;
    else
        m_volume -= volume;
    SetMusicVolume(*m_music.begin()->second, m_volume / 100);
    return (*this);
}

ray::MusicStream & ray::MusicStream::setVolumeUp(float volume)
{
    m_volume += volume;
    SetMusicVolume(*m_music.begin()->second, m_volume / 100);
    return (*this);
}

void ray::MusicStream::pause()
{
    StopMusicStream(*m_music[m_playing]);
}

void ray::MusicStream::stop()
{
    if (m_playing.empty())
        return;
    StopMusicStream(*m_music[m_playing]);
    m_playing.clear();
}

ray::MusicStream & ray::MusicStream::setPitch(float pitch)
{
    m_pitch = pitch;
    SetMusicPitch(*m_music.begin()->second, m_pitch);
    return (*this);
}

std::shared_ptr<Music> ray::MusicStream::getMusic() const
{
    return (m_music.begin()->second);
}

float ray::MusicStream::getVolume() const
{
    return (m_volume);
}

float ray::MusicStream::getPitch() const
{
    return (m_pitch);
}