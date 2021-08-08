/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** EndGame.hpp
*/

#ifndef __ENDGAME_H__
#define __ENDGAME_H__

#include <tuple>

#include "SW/Scene.hpp"
#include "factory/factories.hpp"
#include "component/components.hpp"
#include "script/GameManager.hpp"
#include "jsnp.hpp"

class EndGameScene :
    public sw::AScene
{
    public:
        using rankInfo_t = std::tuple<GameManager::rank, std::string, GameManager::BomberColor>;
        using ranking_t = std::array<std::tuple<GameManager::rank, std::string, GameManager::BomberColor>, 4>;

    private:
        unsigned m_nbPlayer;
        ranking_t m_ranking;

    public:
        using sw::AScene::AScene;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;

        void createRanker(ray::TransformFact& tfmFact, ray::SpriteFact& sprFact, ray::TextFact& txtFact, std::string name, rankInfo_t rankInfo);

};

#endif // __ENDGAME_H__