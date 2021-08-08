/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libsdl.cpp
*/

#include <iostream>
#include <set>
#include "../inc/SdlModule.hpp"

sdl::SdlModule::SdlModule() :
    m_name("libSdl"),
    m_isOk(true),
    m_window(nullptr),
    m_keystate(nullptr)
{
    std::cout << getName() << " initializing..." << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << this->getName() << SDL_GetError() << std::endl;
    TTF_Init();
    m_window = SDL_CreateWindow("arcade_sdl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_font = TTF_OpenFont("rsc/8bitPix.ttf", 50);
}

sdl::SdlModule::~SdlModule()
{
    std::cout << getName() << " stopping..." << std::endl;
    SDL_DestroyRenderer(m_renderer);
    TTF_CloseFont(m_font);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    TTF_Quit();
}

std::string sdl::SdlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

bool sdl::SdlModule::isOk()
{
    return (m_isOk);
}

void sdl::SdlModule::clearWindow()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
}

void sdl::SdlModule::displayWindow()
{
    SDL_RenderPresent(m_renderer);
}

void sdl::SdlModule::checkEvent()
{
    m_keystate = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));
    while (SDL_PollEvent(&m_event))
        if (m_event.type == SDL_QUIT)
            m_isOk = false;
}

void sdl::SdlModule::drawText(const std::string& text, int characterSize, arc::Color color, arc::Vector<float> position)
{
    SDL_Color realColor = sdl::sdlColorMap.find(color)->second;
    SDL_Surface *surface = TTF_RenderText_Blended(m_font, text.c_str(), realColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_FRect rect = {position.x * 10, position.y * 10, (surface->w * (float)characterSize) / surface->h, (float)characterSize};

    SDL_RenderCopyF(m_renderer, texture, nullptr, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void sdl::SdlModule::drawSquare(int size, arc::Color color, arc::Vector<float> position)
{
    SDL_FRect rect = {position.x * 10, position.y * 10, (float)size * 10, (float)size * 10};
    SDL_Color realColor = sdl::sdlColorMap.find(color)->second;

    SDL_SetRenderDrawColor(m_renderer, realColor.r, realColor.g, realColor.b, realColor.a);
    SDL_RenderFillRectF(m_renderer, &rect);
}

bool sdl::SdlModule::getKeyDown(arc::Keyboard key)
{
    static std::set<arc::Keyboard> list;
    auto value = sdl::keyboardMap.find(key)->second;

    if (!m_keystate)
        return (false);
    if (list.find(key) == list.end() && m_keystate[SDL_GetScancodeFromKey(value)]) {
        list.insert(key);
        return (true);
    }
    else if (!m_keystate[SDL_GetScancodeFromKey(value)]) {
        auto it = list.find(key);
        if (it != list.end())
            list.erase(it);
    }
    return (false);
}