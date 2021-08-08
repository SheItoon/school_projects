/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** EndGame.cpp
*/

#include "Module.hpp"
#include "scene/EndGame.hpp"
#include "script/GameManager.hpp"
#include "component/components.hpp"
#include "utils/Input.hpp"

static EndGameScene::ranking_t getRanking(jsnp::Object obj, unsigned nbPlayer)
{
    EndGameScene::ranking_t ranking;

    for (int ctr = 0; ctr < nbPlayer; ctr += 1) {
        jsnp::Object rank = obj["Rank" + std::to_string(ctr + 1)].second.value<jsnp::Object>();
        ranking[ctr] = {(GameManager::rank)ctr + 1, rank["Name"].second.value<std::string>(), (GameManager::BomberColor)rank["BomberColor"].second.value<int>()};
    }
    return (ranking);
}

void EndGameScene::createRanker(ray::TransformFact& tfmFact, ray::SpriteFact& sprFact, ray::TextFact& txtFact, std::string name, rankInfo_t rankInfo)
{
    createEntity(name);
    createEntity(name + "_text");
    auto& tfm = tfmFact.createComponent(name);
    auto& spr = sprFact.createComponent(name);
    auto& tfmTxt = tfmFact.createComponent(name + "_text");
    auto& txt = txtFact.createComponent(name + "_text");

    txt.setString(std::get<1>(rankInfo));
    txt.setColor(BLACK);
    switch (std::get<0>(rankInfo)) {
        case 1:
            tfm.setPosition(850, 1100, 0);
            tfm.setScale(1.6, 1.6, 0);
            tfmTxt.setPosition(850, 1621.6, 0);
            txt.setSize(50);
            txt.setSpacing(5);
            break;
        case 2:
            tfm.setPosition(550, 1100, 0);
            tfm.setScale(1.4, 1.4, 0);
            tfmTxt.setPosition(550, 1556.4, 0);
            txt.setSize(40);
            txt.setSpacing(5);
            break;
        case 3:
            tfm.setPosition(1226, 1100, 0);
            tfm.setScale(1.2, 1.2, 0);
            tfmTxt.setPosition(1226, 1491.2, 0);
            txt.setSize(30);
            txt.setSpacing(5);
            break;
        case 4:
            tfm.setPosition(250, 1100, 0);
            txt.setSize(20);
            tfmTxt.setPosition(250, 1426, 0);
            txt.setSpacing(5);
            break;
    }
    switch (std::get<2>(rankInfo)) {
        case GameManager::BomberColor::White:
            spr.setTexture("WinBomberWhite");
            break;
        case GameManager::BomberColor::Pink:
            spr.setTexture("WinBomberPink");
            break;
        case GameManager::BomberColor::Green:
            spr.setTexture("WinBomberGreen");
            break;
        case GameManager::BomberColor::Blue:
            spr.setTexture("WinBomberBlue");
            break;
    }
}

void EndGameScene::onLoad()
{
    auto& tfmFact = createFactory<ray::TransformFact>("TransformFact");
    auto& sprFact = createFactory<ray::SpriteFact>("SpriteFact");
    auto& txtFact = createFactory<ray::TextFact>("TextFact");
    auto& musicFact = createFactory<ray::MusicFact>("MusicFact");

    jsnp::Data data("resources/save/GameInfo.json");

    m_nbPlayer = data()["NbrPlayer"].second.value<int>();
    m_ranking = getRanking(data(), m_nbPlayer);

    createEntity("Background");
    tfmFact.createComponent("Background");
    auto& backSpr = sprFact.createComponent("Background");
    sprFact.setLayer("Background", -1);

    for (int ctr = 0; ctr < m_nbPlayer; ctr += 1)
        createRanker(tfmFact, sprFact, txtFact, "Bomber" + std::to_string(ctr + 1), m_ranking[ctr]);

    createEntity("CongratText").setActive(false);
    auto& txt1 = txtFact.createComponent("CongratText");
    txt1.setString("Congratulations !!");
    txt1.setColor(BLACK);
    txt1.setSpacing(5);
    txt1.setSize(100);
    tfmFact.createComponent("CongratText").setPosition({100, 100, 0});

    createEntity("InfoText").setActive(false);
    auto& txt2 = txtFact.createComponent("InfoText");
    txt2.setString("Press Enter to return to the main menu ...");
    txt2.setColor(BLACK);
    txt2.setSpacing(5);
    txt2.setSize(20);
    tfmFact.createComponent("InfoText").setPosition({60, 980, 0});

    createEntity("Bestiole");
    auto& tfm = tfmFact.createComponent("Bestiole");
    tfm.setPosition(1500, 500, 0);
    sprFact.createComponent("Bestiole").setTexture("Bestiole");

    switch (std::get<2>(m_ranking[0])) {
        case GameManager::BomberColor::White:
            backSpr.setTexture("WinBackWhite");
            break;
        case GameManager::BomberColor::Pink:
            backSpr.setTexture("WinBackPink");
            break;
        case GameManager::BomberColor::Green:
            backSpr.setTexture("WinBackGreen");
            break;
        case GameManager::BomberColor::Blue:
            backSpr.setTexture("WinBackBlue");
            break;
    }

    createEntity("Music");
    musicFact.createComponent("Music").addSound("EndGame", "EndGame").play("EndGame");
}

void EndGameScene::onUpdate()
{
    static bool finish = false;
    static std::array<float, 4> txtFinalPos {721.6, 756.4, 791.2, 826};
    auto& tfmFact = getFactory<ray::TransformFact>("TransformFact");
    float deltaTime = sw::Engine::getModule<ray::Module>("RayLib").getDeltaTime();

    if (ray::Input::GetKeyPressed(ray::Keyboard::KEY_ENTER)
    || ray::Input::IsGamePadButtonPressed(0, 7)) {
        if (finish) {
            getEntity("Music").getComponent<ray::MusicStream>("MusicFact").stop();
            sw::Engine::setActiveScene("MainMenu");
        } else {
            for (int ctr = 0; ctr < m_nbPlayer; ctr += 1) {
                auto& tfm = tfmFact["Bomber" + std::to_string(ctr + 1)];
                auto& tfmTxt = tfmFact["Bomber" + std::to_string(ctr + 1) + "_text"];
                tfm.setPosition(tfm.getPosition().x, (ctr + 2) * 100, 0);
                tfmTxt.setPosition(tfm.getPosition().x, txtFinalPos[ctr], 0);
            }
            finish = true;
            getEntity("CongratText").setActive(true);
            getEntity("InfoText").setActive(true);
        }
    }

    if (!finish)
        for (int ctr = m_nbPlayer - 1; ctr >= 0; ctr -= 1) {
            auto& tfm = tfmFact["Bomber" + std::to_string(ctr + 1)];

            if (tfm.getPosition().y > (ctr + 2) * 100) {
                auto& tfmTxt = tfmFact["Bomber" + std::to_string(ctr + 1) + "_text"];
                tfm.move({0, -150 * deltaTime, 0});
                tfmTxt.move({0, -150 * deltaTime, 0});
                break;
            }
            if (ctr == 0) {
                finish = true;
                getEntity("CongratText").setActive(true);
                getEntity("InfoText").setActive(true);
            }
        }
}

void EndGameScene::onUnload()
{}