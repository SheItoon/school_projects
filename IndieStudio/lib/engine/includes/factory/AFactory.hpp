/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AFactory.hpp
*/

#ifndef __SHIPWRECK_AFACTORY_HPP__
#define __SHIPWRECK_AFACTORY_HPP__

#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>
#include <memory>

#include "IFactory.hpp"
#include "engine/Engine.hpp"
#include "scene/AScene.hpp"
#include "error/Error.hpp"
#include "../json_parser/jsnp.hpp"

namespace sw
{

    template <typename ConcretComponent>
    class AFactory :
        public IFactory
    {

        protected:
            AScene& m_scene;
            bool m_isActive;
            int m_layer;

            class ComponentMap :
                private std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::operator[];

                friend AFactory;

            } m_componentMap;

            class ComponentLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AFactory;

            } m_componentLayer;

            std::vector<std::string> m_removeList;
            bool m_needDelete;

            virtual void onLoad() = 0;
            virtual void onUpdate() = 0;
            virtual void onUnload() = 0;

        public:
            const std::string m_name;

            AFactory(const std::string& factoryName, AScene& sceneRef);
            ~AFactory() = default;

            template <typename... Args>
            ConcretComponent& createComponent(const std::string& entityName, Args... values);
            typename std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator begin();
            typename std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator end();
            ConcretComponent& operator[](const std::string& entityName);
            void deleteComponent(const std::string& entityName);
            void setLayer(const std::string& entityName, int layer);
            void deleteRequestedComponent();

            template <typename T, typename... Args>
            ConcretComponent& addScript(const std::string& entity, Args... values);

            template <typename T, typename... Args>
            T& insertComponent(const std::string& entity, Args... values);

            void load() override;
            void update() override;
            void unload() override;
            void endUpdate() override;

            void setActive(bool value);
            bool isActive() const;

        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, AFactory<T>& sys);

    }; // class AFactory

    #include "AFactory.inl"

} // namespace sw

#endif // __SHIPWRECK_AFACTORY_HPP__