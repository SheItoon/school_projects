/*
** EPITECH PROJECT, 2021
** test.cpp
** File description:
** test.cpp
*/

#include "raylib.h"
#include "SW/Engine.hpp"
#include "Module.hpp"

void ray::Module::initialize()
{
    try { onInitialize(); }
    catch (std::exception& e) {
        std::cerr << "Error on your module initialization: " << e.what() << std::endl;
    }
    try {
        sw::LoadResourcesFile("resources/textures.json");
        sw::LoadResourcesFile("resources/sounds.json");
        sw::LoadResourcesFile("resources/fonts.json");
        sw::LoadResourcesFile("resources/models.json");
        SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
        #ifdef WIN32
        SetConfigFlags(FLAG_MSAA_4X_HINT);
        #endif
        InitWindow(1920, 1080, "IndieStudio");
        SetTargetFPS(60);
        m_icon = LoadImage("resources/textures/logo.png");
        m_backgroundColor = BLANK;
        SetWindowIcon(m_icon);
        SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED | FLAG_WINDOW_UNDECORATED);
        SetAudioStreamBufferSizeDefault(4096);
        InitAudioDevice();
    } catch (std::exception& e) {
        std::cerr << "Error on resource initialization: " << e.what() << std::endl;
    }
    try { sw::Engine::activeScene().load(); }
    catch (std::exception& e) {
        std::cerr << "Error on active scene loading: " << e.what() << std::endl;
    }
}

bool ray::Module::isOk()
{
    return (!WindowShouldClose() & !m_close);
}

void ray::Module::update()
{
    BeginDrawing();
    ClearBackground(m_backgroundColor);
    onUpdate();
    sw::Engine::activeScene().update();
    EndDrawing();
}

void ray::Module::terminate()
{
    onTerminate();
}

ray::Module& ray::Module::SetWindowType(int state)
{
    SetWindowState(state);
    return (*this);
}

ray::Module& ray::Module::ClearWindowType(int state)
{
    ClearWindowState(state);
    return (*this);
}

ray::Module& ray::Module::SetBackGroundColor(Color color)
{
    m_backgroundColor = color;
    return (*this);
}

float ray::Module::getDeltaTime()
{
    return (GetFrameTime());
}

void ray::Module::closeWindow()
{
    m_close = true;
}

ray::Module ray::Module::toggleFullScreen()
{
    ToggleFullscreen();
    return (*this);
}

bool ray::Module::isFullScreen() const
{
    return (IsWindowFullscreen());
}

void ray::Module::OpenUrl(std::string url)
{
    OpenURL(url.c_str());
}