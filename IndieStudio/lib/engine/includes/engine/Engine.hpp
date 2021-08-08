/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Engine.hpp
*/

#ifndef __SHIPWRECK_ENGINE_HPP__
#define __SHIPWRECK_ENGINE_HPP__

#include <unordered_map>
#include <string>

#include "scene/AScene.hpp"
#include "module/IModule.hpp"
#include "resources/Resources.hpp"

int main();

namespace sw
{

    class Engine
    {

        private:
            static std::unordered_map<std::string, std::unique_ptr<AScene>> m_sceneMap;
            static std::string m_activeScene;
            static std::unordered_map<std::string, std::unique_ptr<IModule>> m_moduleMap;
            static std::string m_activeModule;
            static std::vector<std::string> m_deleteScene;

            static void initialize();
            static void update();
            static void terminate();
            static void onInitialize();
            static void onUpdate();
            static void onTerminate();

        public:
            Engine() = delete;
            Engine(Engine&&) = delete;
            Engine(const Engine&) = delete;
            ~Engine() = default;

            template <class ConcretScene>
            static ConcretScene& createScene(const std::string& name);
            template <class ConcretScene>
            static ConcretScene& getScene(const std::string& name);
            static AScene& getScene(const std::string& name);
            template <class ConcretScene>
            static ConcretScene& activeScene();
            static AScene& activeScene();
            static void deleteScene(const std::string& name);
            static void setActiveScene(const std::string& name);
            static void deleteRequestedScene();

            template <class ConcretModule>
            static ConcretModule& createModule(const std::string& name);
            template <class ConcretModule>
            static ConcretModule& getModule(const std::string& name);
            static IModule& getModule(const std::string& name);
            template <class ConcretModule>
            static ConcretModule& activeModule();
            static IModule& activeModule();
            static void deleteModule(const std::string& name);

        friend int ::main();

    }; // class Engine

    #include "moduleFunction.inl"
    #include "sceneFunction.inl"

} // namespace sw

#endif // __SHIPWRECK_ENGINE_HPP__