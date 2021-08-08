/*
** EPITECH PROJECT, 2021
** GameManager.cpp
** File description:
** GameManager.cpp
*/

#include "script/GameManager.hpp"
#include "script/PauseManager.hpp"
#include "script/Player.hpp"
#include "script/Mob.hpp"
#include "component/components.hpp"
#include "utils/Input.hpp"
#include "jsnp.hpp"

GameManager::GameManager(sw::Entity &entity) :
sw::Script(entity),
m_gameState(LOADING),
m_chrono()
{}

void GameManager::start()
{
    m_nbPlayer = jsnp::Data("resources/save/GameSetting.json")()["NbrPlayer"].second.value<int>();

    auto& countDown = m_entity.m_scene.createEntity("CountDown");
    auto& countDownNumber = m_entity.m_scene.createEntity("CountDownNumber");
    auto& countTrans = countDown.createComponent<ray::Transform>("TransformFact");
    auto& countTransNumber = countDownNumber.createComponent<ray::Transform>("TransformFact");

    countDown.createComponent<ray::Text>("TextFact").setSize(100).setSpacing(5).setString(std::string("Game start in:")).setColor(BLACK);
    countDownNumber.createComponent<ray::Text>("TextFact").setSize(100).setSpacing(5).setString(std::string("5")).setColor(BLACK);
    countTrans.setPosition(650, 300);
    countTransNumber.setPosition(1000, 400);
    m_entity.createComponent<ray::Audio>("AudioFact")
            .addSound("StartGame1", "Start1")
            .addSound("StartGame2", "Start2")
            .addSound("StartGame3", "Start3")
            .addSound("StartGame4", "Start4")
            .addSound("StartGame", "Start");
    m_entity.createComponent<ray::MusicStream>("MusicFact").addSound("Game", "Game").setVolume(50).play("Game");
}

void GameManager::update()
{
    if (m_gameState == LOADING)
        m_gameState = STARTING;
    else if (m_gameState == STARTING)
        CountDown();
    else if (m_gameState == ENDED) {
        saveGameInfo();
        sw::Engine::setActiveScene("EndGame");
    }
    if (m_gameState != GameManager::STARTING && (ray::Input::IsGamePadButtonPressed(0, 15) || ray::Input::GetKeyPressed(ray::Keyboard::KEY_P)))
        m_entity.m_scene.getEntity("PauseManager").getComponent<PauseManager>("ScriptFact").activation();
}

GameManager::BomberColor GameManager::getColor(std::string skin)
{
    GameManager::BomberColor color;

    if (skin == "Player")
        color = GameManager::BomberColor::White;
    else if (skin == "PlayerBlue")
        color = GameManager::BomberColor::Blue;
    else if (skin == "PlayerGreen")
        color = GameManager::BomberColor::Green;
    else if (skin == "PlayerRed")
        color = GameManager::BomberColor::Pink;
    return (color);
}

void GameManager::playerDeath(const std::string& name, std::string skin)
{
    static short rank = m_nbPlayer - 1;

    m_ranking[rank] = std::make_tuple(rank + 1, name, getColor(skin));
    rank -= 1;
    if (rank == 0) {
        for (auto& [name, entity] : m_entity.m_scene.getEntities()) {
            auto& ent = static_cast<sw::Entity&>(*entity);
            GameManager::BomberColor color;

            if (name.find("Player") != std::string::npos && name.find("_") == std::string::npos && ent.isActive())
                color = getColor(ent.getComponent<Player>("ScriptFact").getSkin());
            else if (name.find("AI") != std::string::npos && name.find("_") == std::string::npos && ent.isActive())
                color = getColor("Player");
            else
                continue;
            m_ranking[rank] = std::make_tuple(rank + 1, name, color);
        }
        rank = m_nbPlayer - 1;
        m_gameState = ENDED;
    }
}

static jsnp::Object getRanker(std::tuple<GameManager::rank, std::string, GameManager::BomberColor>& ranker)
{
    jsnp::Object obj;
    GameManager::rank rank;
    std::string name;
    GameManager::BomberColor color;

    std::tie(rank, name, color) = ranker;
    obj.emplace_back("Name", name);
    obj.emplace_back("BomberColor", (int)color);
    return (obj);
}

void GameManager::saveGameInfo()
{
    jsnp::Data data;

    data().emplace_front("NbrPlayer", (int)m_nbPlayer);
    for (int ctr = 0; ctr < m_nbPlayer; ctr += 1)
        data().emplace_back("Rank" + std::to_string(ctr + 1), getRanker(m_ranking[ctr]));
    data.save("resources/save/GameInfo.json");
}

void GameManager::CountDown()
{
    auto& countDown = m_entity.m_scene.getEntity("CountDownNumber");
    auto& sound = m_entity.getComponent<ray::Audio>("AudioFact");

    if (!m_chrono.isRunning())
        m_chrono = sw::Chrono(sw::Chrono::Lauch);
    countDown.getComponent<ray::Text>("TextFact").setString(std::string(std::to_string(5 - (int)m_chrono.getTotalTime())));
    if ((int)m_chrono.getTotalTime() > 3)
        sound.playSolo("Start1");
    else if ((int)m_chrono.getTotalTime() > 2)
        sound.playSolo("Start2");
    else if ((int)m_chrono.getTotalTime() > 1)
        sound.playSolo("Start3");
    else if ((int)m_chrono.getTotalTime() > 0)
        sound.playSolo("Start4");
    m_chrono.tour();
    if (m_chrono.getTotalTime() >= 5.0f) {
        countDown.getComponent<ray::Text>("TextFact").setActive(false);
        m_entity.m_scene.getEntity("CountDown").getComponent<ray::Text>("TextFact").setActive(false);
        m_chrono.stop();
        sound.playSolo("Start");
        m_gameState = INGAME;
    }
}

GameManager& GameManager::setGameState(GameState state)
{
    m_gameState = state;
    return (*this);
}

GameManager::GameState GameManager::getGameState() const
{
    return (m_gameState);
}