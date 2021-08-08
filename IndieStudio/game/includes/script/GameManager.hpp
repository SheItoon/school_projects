/*
** EPITECH PROJECT, 2021
** GameManager.h
** File description:
** GameManager.h
*/

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <array>
#include "component/Script.hpp"

#include "utils/Chrono.hpp"

class GameManager : public sw::Script
{
    public:
        enum GameState {
            INGAME,
            STARTING,
            PAUSE,
            ENDED,
            LOADING
        };

        enum BomberColor {
            White,
            Pink,
            Green,
            Blue
        };

        using rank = short;

        sw::Chrono m_chrono;
        std::array<std::tuple<rank, std::string, BomberColor>, 4> m_ranking;

    private:
        GameState m_gameState;
        unsigned m_nbPlayer;

        GameManager::BomberColor getColor(std::string skin);

    public:
        explicit GameManager(sw::Entity& entity);

        void start() override;
        void update() override;

        GameManager& setGameState(GameState state);
        void CountDown();
        void playerDeath(const std::string& name, std::string bColor);
        void saveGameInfo();

        [[nodiscard]] GameState getGameState() const;
};


#endif //GAMEMANAGER_H
