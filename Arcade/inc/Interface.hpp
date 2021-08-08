/*
** EPITECH PROJECT, 2021
** Interface.hpp
** File description:
** Interface.hpp
*/

#ifndef INTERFACE
#define INTERFACE

#include "IDisplayModule.hpp"
#include "DLLoader.hpp"
#include "DLManager.hpp"
#include "IGame.hpp"
#include <vector>

namespace arc
{
    class Interface
    {
        int m_gameIndex;
        int m_libIndex;
        std::vector<std::string> m_lib;
        std::vector<std::string> m_game;
        std::map<std::string, std::string> m_score;

        void getList();
        void drawText(arc::IDisplayModule* graph, int index, const std::string &name, bool game) const;
        void checkInput(arc::IDisplayModule* graph, arc::DLManager& manager);
        void getData();
    public:
        Interface() = default;
        ~Interface() = default;

        void start(arc::IDisplayModule* graph);
        void update(arc::IDisplayModule* graph, arc::DLManager& manager);

        friend void GameLoop(arc::DLManager& manager, arc::Interface& interface);
    };
    void GameLoop(arc::DLManager& manager, arc::Interface& interface);
}

extern "C" void *entryPoint();


#endif //INTERFACE
