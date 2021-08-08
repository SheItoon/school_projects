/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IScene.hpp
*/

#ifndef __SHIPWRECK_ISCENE_HPP__
#define __SHIPWRECK_ISCENE_HPP__

#include <string>

namespace sw
{

    class Entity;
    class Texture;
    class Sound;
    class Font;

    class IScene
    {

        public:
            virtual ~IScene() = default;

            virtual void load() = 0;
            virtual void update() = 0;
            virtual void unload() = 0;

            virtual Entity& createEntity(const std::string& name) = 0;
            virtual Entity& getEntity(const std::string& name) = 0;
            virtual bool hasEntity(const std::string& name) = 0;
            virtual void deleteEntity(const std::string& name) = 0;

            virtual bool hasFactory(const std::string& name) = 0;
            virtual void deleteFactory(const std::string& name) = 0;

            virtual sw::Texture& getTexture(std::string name) = 0;
            virtual sw::Sound& getSound(std::string name) = 0;
            virtual sw::Font& getFont(std::string name) = 0;

    }; // class IScene

} // namespace sw

#endif // __SHIPWRECK_ISCENE_HPP__