/*
** EPITECH PROJECT, 2021
** Module.hpp
** File description:
** Module.hpp
*/

#ifndef MODULE
#define MODULE

#include <string>
#include "SW/Module.hpp"
#include "raylib.h"

namespace ray
{
    class Module :
        public sw::IModule
    {
        private:
            Image m_icon;
            Color m_backgroundColor;
            bool m_debug;
            bool m_close;

            void onInitialize() override;
            void onUpdate() override;
            void onTerminate() override;

        public:
            Module() = default;
            ~Module() = default;

            void initialize() override;
            bool isOk() override;
            void update() override;
            void terminate() override;
            Module& SetWindowType(int state);
            Module& ClearWindowType(int state);
            Module& SetBackGroundColor(Color color);
            float getDeltaTime();

            bool isFullScreen() const;
            Module toggleFullScreen();

            bool isDebuging() { return (m_debug); }
            void closeWindow();
            static void OpenUrl(std::string url);

    }; // class Module

} // namespace ray

#endif //MODULE
