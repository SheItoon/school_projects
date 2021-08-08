/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Entity.hpp
*/

#ifndef __SHIPWRECK_ENTITY_HPP__
#define __SHIPWRECK_ENTITY_HPP__

#include <string>
#include <optional>
#include <functional>
#include <unordered_map>

#include "IEntity.hpp"
#include "scene/AScene.hpp"
#include "factory/AFactory.hpp"

template <typename T>
using ref = std::optional<std::reference_wrapper<T>>;

namespace sw
{

    class Entity :
        public IEntity
    {

        private:
            bool m_isActive;

        public:
            const std::string m_name;
            AScene& m_scene;
            ref<Entity> m_parent;
            std::unordered_map<std::string, std::reference_wrapper<Entity>> m_childrenMap;

            Entity() = delete;
            Entity(Entity&&) = delete;
            Entity(const Entity&) = delete;
            Entity(const std::string& entityName, AScene& sceneRef);
            ~Entity() = default;

            template <typename ConcretComponent, typename... Args>
            ConcretComponent& createComponent(const std::string& factoryName, Args... values);
            template <typename ConcretComponent>
            ConcretComponent& getComponent(const std::string& factoryName);
            void deleteComponent(const std::string& factoryName);
            void setLayer(const std::string& factoryName, int layer);

            template <typename ConcretComponent, typename T, typename... Args>
            T& insertComponent(const std::string& factoryName, Args... values);

            void addChild(const std::string& entityName);

            void setActive(bool value);
            bool isActive() const;

    }; // class Entity

    #include "Entity.inl"

} // namespace sw

#endif // __SHIPWRECK_ENTITY_HPP__