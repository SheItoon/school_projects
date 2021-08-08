/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Scene.hpp
*/

#ifndef __SHIPWRECK_ASCENE_HPP__
#define __SHIPWRECK_ASCENE_HPP__

#include <iostream>
#include <unordered_map>
#include <forward_list>
#include <map>
#include <memory>

#include "error/Error.hpp"

#include "entity/IEntity.hpp"
#include "factory/IFactory.hpp"

#include "resources/Resources.hpp"

namespace sw
{

    class Entity;

    class AScene
    {

        protected:
            class FactoryMap :
                private std::unordered_map<std::string, std::unique_ptr<IFactory>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IFactory>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IFactory>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IFactory>>::operator[];

                friend AScene;

            } m_factoryMap;

            class EntityMap :
                private std::unordered_map<std::string, std::unique_ptr<IEntity>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::operator[];

                friend AScene;

            } m_entityMap;

            class FactoryLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AScene;

            } m_factoryLayer;

            Resources m_resources;
            std::vector<std::string> m_deleteEntity;

            virtual void onLoad() = 0;
            virtual void onUpdate() = 0;
            virtual void onUnload() = 0;

        public:
            bool m_load;
            const std::string m_name;

            AScene() = delete;
            AScene(AScene&&) = delete;
            AScene(const AScene&) = delete;
            AScene(const std::string& sceneName);
            ~AScene();

            std::unordered_map<std::string, std::unique_ptr<IFactory>>& getFactories() { return (m_factoryMap); }
            std::unordered_map<std::string, std::unique_ptr<IEntity>>& getEntities() { return (m_entityMap); }
            std::forward_list<std::pair<int, std::string>>& getFactoriesLayer() { return (m_factoryLayer); }

            void load();
            void update();
            void unload();

            Entity& createEntity(const std::string& entityName);
            Entity& getEntity(const std::string& entityName);
            bool hasEntity(const std::string& entityName);
            void deleteEntity(const std::string& entityName);
            void deleteRequestedEntity();

            template <typename ConcretFactory>
            ConcretFactory& createFactory(const std::string& factoryName);
            template <typename ConcretFactory>
            ConcretFactory& getFactory(const std::string& factoryName);
            bool hasFactory(const std::string& factoryName);
            void deleteFactory(const std::string& factoryName);
            void setLayer(const std::string& factoryName, int layer);

            sw::ITexture& getTexture(std::string textureName);
            sw::ISound& getSound(std::string soundName);
            sw::IFont& getFont(std::string fontName);
            sw::IModel& getModel(std::string modelName);
            sw::IMusic& getMusic(std::string musicName);

            friend void LoadResourcesFile(const std::string& path);
            friend void AddResourcesOnScene(jsnp::Token& token);

    }; // class Scene

    #include "Scene.inl"
    #include "entityFunction.inl"
    #include "factoryFunction.inl"

} // namespace sw

//inline auto operator<=>(const std::pair<int, std::string>& left, const std::pair<int, std::string>& right)
//{
//    return (left.first <=> right.first);
//}

#endif // __SHIPWRECK_ASCENE_HPP__