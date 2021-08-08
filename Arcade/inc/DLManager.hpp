/*
** EPITECH PROJECT, 2021
** DLManager.hpp
** File description:
** DLManager.hpp
*/

#ifndef DLMANAGER
#define DLMANAGER

#include <string>
#include <memory>
#include <map>

#include "DLLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGame.hpp"

namespace arc
{
    class DLManager
    {
    private:
        std::unique_ptr<DLLoader> m_module;
        std::unique_ptr<DLLoader> m_game;
        IDisplayModule* m_moduleFunc;
        IGame* m_gameFunc;
        bool m_needGraphUpdate;
        bool m_needGameUpdate;
        std::string m_newGraph;
        std::string m_newGame;
        std::string m_userName;
    public:
        enum State {GAME, MENU} state;
        explicit DLManager(const std::string& path);
        ~DLManager();
        void ChangeGraphicModule(const std::string module);
        void ChangeGameModule(const std::string module);
        DLLoader& getGraphicsModule();
        DLLoader& getGameModule();
        IDisplayModule* getGraphicsInstance();
        IGame* getGameInstance();
        void updateGraphics();
        void updateGame();
    };
}

#endif //DLMANAGER
