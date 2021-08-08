/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Resources.hpp
*/

#ifndef __SHIPWRECK_RESOURCES_HPP__
#define __SHIPWRECK_RESOURCES_HPP__

#include <string>
#include <unordered_map>
#include <memory>

#include "error/Error.hpp"
#include "IResources.hpp"
#include "jsnp.hpp"

namespace sw
{

    class Resources
    {

        private:
            std::unordered_map<std::string, std::string> m_neededTextures;
            std::unordered_map<std::string, std::string> m_neededSounds;
            std::unordered_map<std::string, std::string> m_neededModels;
            std::unordered_map<std::string, std::string> m_neededFonts;
            std::unordered_map<std::string, std::string> m_neededMusic;

            void loadTextures();
            void loadSounds();
            void loadFonts();
            void loadModel();
            void loadMusic();

        public:
            class TexturesMap :
                private std::unordered_map<std::string, std::shared_ptr<ITexture>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<ITexture>>::operator[];

                friend Resources;

            } textures;

            class SoundsMap :
                private std::unordered_map<std::string, std::shared_ptr<ISound>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<ISound>>::operator[];

                friend Resources;

            } sounds;

        class MusicMap :
                private std::unordered_map<std::string, std::shared_ptr<IMusic>>
        {
        public:
            using std::unordered_map<std::string, std::shared_ptr<IMusic>>::operator[];

            friend Resources;

        } music;

            class FontsMap :
                private std::unordered_map<std::string, std::shared_ptr<IFont>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<IFont>>::operator[];

                friend Resources;

            } fonts;

            class ModelMap :
                private std::unordered_map<std::string, std::shared_ptr<IModel>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<IModel>>::operator[];

                friend Resources;

            } models;

            Resources() = default;
            ~Resources();

            void loadResources();
            void unloadResources();

            friend void LoadResourcesFile(const std::string& path);
            friend void AddResourcesOnScene(jsnp::Token& it);

    }; // class Resources

    void LoadResourcesFile(const std::string& path);
    void AddResourcesOnScene(jsnp::Token& it);

} // namespace sw

#endif // __SHIPWRECK_RESOURCES_HPP__