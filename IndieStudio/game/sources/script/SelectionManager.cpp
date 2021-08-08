/*
** EPITECH PROJECT, 2021
** SelectionManager.cpp
** File description:
** SelectionManager.cpp
*/

#include "scene/MainMenu.hpp"
#include "component/components.hpp"
#include "factory/factories.hpp"
#include "utils/Input.hpp"
#include "jsnp.hpp"

#include "script/SelectionManager.hpp"
#include "script/SelectionPlayer.hpp"

SelectionManager::SelectionManager(sw::Entity &entity) :
sw::Script(entity),
m_selected(false),
m_changed(false),
m_index(0),
m_chrono(),
m_nbrPlayer(2)
{}

void SelectionManager::start()
{
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
    auto& playButton = m_entity.m_scene.createEntity("PlayButton");
    auto& menuButton = m_entity.m_scene.createEntity("MenuButton");
    auto& background = m_entity.m_scene.createEntity("BackGround");

    background.createComponent<ray::Transform>("TransformFact");
    background.createComponent<ray::Sprite>("BackGroundFact").setTexture("PlayerSelectBack");

    auto& transPlay = playButton.createComponent<ray::Transform>("TransformFact");
    transPlay.setPosition(1500, 850);
    playButton.createComponent<ray::Sprite>("SpriteFact").setTexture("ReadyButton").setColor(GRAY).loadSpriteImage();

    auto& tfmMenu = menuButton.createComponent<ray::Transform>("TransformFact");
    tfmMenu.setPosition(120, 850);
    menuButton.createComponent<ray::Sprite>("SpriteFact").setTexture("MenuButton").setColor(GRAY).loadSpriteImage();

    m_entity.m_scene.createEntity("Selection_Player_1");
    dynamic_cast<SelectionPlayer&>(scriptFact.addScript<SelectionPlayer>("Selection_Player_1")).setPlayer(1);

    m_entity.m_scene.createEntity("Selection_Player_2");
    dynamic_cast<SelectionPlayer&>(scriptFact.addScript<SelectionPlayer>("Selection_Player_2")).setPlayer(2);

    m_entity.m_scene.createEntity("Selection_Player_3");
    dynamic_cast<SelectionPlayer&>(scriptFact.addScript<SelectionPlayer>("Selection_Player_3")).setPlayer(3);

    m_entity.m_scene.createEntity("Selection_Player_4");
    dynamic_cast<SelectionPlayer&>(scriptFact.addScript<SelectionPlayer>("Selection_Player_4")).setPlayer(4);
    m_entity.createComponent<ray::Audio>("AudioFact").addSound("Switch_1", "Switch1").addSound("Switch_2", "Switch2").addSound("Switch_3", "Switch3").addSound("ChangeMenu", "ChangeMenu").addSound("Selection", "Selection");
    m_nbrPlayer = 2;
}

void SelectionManager::update()
{
    if (m_selected) {
        doAction();
        return;
    }

    auto& p1Select = m_entity.m_scene.getEntity("Selection_Player_1").getComponent<SelectionPlayer>("ScriptFact").unselected();
    auto& p2Select = m_entity.m_scene.getEntity("Selection_Player_2").getComponent<SelectionPlayer>("ScriptFact").unselected();
    auto& p3Select = m_entity.m_scene.getEntity("Selection_Player_3").getComponent<SelectionPlayer>("ScriptFact").unselected();
    auto& p4Select = m_entity.m_scene.getEntity("Selection_Player_4").getComponent<SelectionPlayer>("ScriptFact").unselected();
    auto& readySpr = m_entity.m_scene.getEntity("PlayButton").getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& menuSpr = m_entity.m_scene.getEntity("MenuButton").getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& audioCpt = m_entity.getComponent<ray::Audio>("AudioFact");
    static bool mPadAction = false;

    float axisValue = ray::Input::GetGamepadAxis(0, 0);
    std::string audioSName = "Switch" + std::to_string(std::rand() % 3 + 1);

    if ((axisValue > 0.81f && !m_changed) || ray::Input::IsGamePadButtonPressed(0, 2) || ray::Input::GetKeyPressed(ray::KEY_RIGHT)) {
        m_index = (m_index >= 5) ? 0 : m_index + 1;
        audioCpt.play(audioSName);
        m_changed = true;
    } else if ((axisValue < -0.81f && !m_changed) || ray::Input::IsGamePadButtonPressed(0, 4) || ray::Input::GetKeyPressed(ray::KEY_LEFT)) {
        m_index = (m_index <= 0) ? 5 : m_index - 1;
        audioCpt.play(audioSName);
        m_changed = true;
    } else if (axisValue < 0.8f && axisValue > -0.8f)
        m_changed = false;

    sw::Vector2f mousePos = ray::Input::GetMousePosition();

    if (CheckCollisionPointRec({mousePos.x, mousePos.y}, {80, 100, 200, 300})) {
        if (m_index != 0) {
            m_index = 0;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    }
    else if (CheckCollisionPointRec({mousePos.x, mousePos.y}, {380, 100, 200, 300})) {
        if (m_index != 1) {
            m_index = 1;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    }
    else if (CheckCollisionPointRec({mousePos.x, mousePos.y}, {680, 100, 200, 300})) {
        if (m_index != 2) {
            m_index = 2;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    }
    else if (CheckCollisionPointRec({mousePos.x, mousePos.y}, {980, 100, 200, 300})) {
        if (m_index != 3) {
            m_index = 3;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    }
    else if (menuSpr.PointOnImage(mousePos)) {
        if (m_index != 4) {
            m_index = 4;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (readySpr.PointOnImage(mousePos)) {
        if (m_index != 5) {
            m_index = 5;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    }
    else if (mPadAction && !m_changed) {
        mPadAction = false;
        m_index = 6;
    }

    switch (m_index) {
        case 0:
            p1Select.selected();
            break;
        case 1:
            p2Select.selected();
            break;
        case 2:
            p3Select.selected();
            break;
        case 3:
            p4Select.selected();
            break;
        case 4:
            menuSpr.setColor(WHITE);
            break;
        case 5:
            readySpr.setColor(WHITE);
            break;
        case 6:
            menuSpr.setColor(GRAY);
            readySpr.setColor(GRAY);
            break;
    }

    if (ray::Input::GetKeyPressed(ray::KEY_ENTER) || ray::Input::IsGamePadButtonPressed(0, 7)
    || ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_LEFT)) {
        if (m_index < 4) {
            m_entity.m_scene.getEntity("Selection_Player_" + std::to_string(m_index + 1)).getComponent<SelectionPlayer>("ScriptFact").change();
            audioCpt.play("Selection");
        } else
            m_selected = true;
    }

}

void SelectionManager::getInformation()
{
    jsnp::Data data;
    jsnp::Object obj;
    int nbrPlayer = 0;

    for (int i = 1; i < 5 ;i++) {
        auto& player = m_entity.m_scene.getEntity("Selection_Player_" + std::to_string(i)).getComponent<SelectionPlayer>("ScriptFact");
        obj.emplace_back("nbr", player.getPlayerNbr());
        obj.emplace_back("type", player.getPlayerType());
        obj.emplace_back("skin", player.getSkin());
        data().emplace_back("Player_" +  std::to_string(i), obj);
        if (player.getPlayerType() != SelectionPlayer::NONE)
            nbrPlayer += 1;
        obj.remove("nbr");
        obj.remove("type");
        obj.remove("skin");
    }
    data().emplace_front("NbrPlayer", nbrPlayer);
    data.save("resources/save/GameSetting.json");
}

void SelectionManager::doAction()
{
    if (m_index == 6 || m_nbrPlayer < 2) {
        m_selected = false;
        return;
    }
    if (!m_chrono.isRunning())
        m_chrono = sw::Chrono(sw::Chrono::Lauch);
    if (m_chrono.getElapsedTime() == 0)
        m_entity.getComponent<ray::Audio>("AudioFact").play("ChangeMenu");
    if (m_chrono.getElapsedTime() != 0 && m_chrono.getElapsedTime() >= 1) {
        switch (m_index)
        {
            case 4:
                m_entity.m_scene.getEntity("Music").getComponent<ray::MusicStream>("MusicFact").stop();
                sw::Engine::setActiveScene("MainMenu");
                break;
            case 5:
                startGame();
                break;
            default:
                break;
        }
        m_selected = false;
        m_chrono.stop();
    } else {
        m_entity.m_scene.getEntity("Music").getComponent<ray::MusicStream>("MusicFact").setVolumeDown(1);
    }
}

void SelectionManager::startGame()
{
    getInformation();
    sw::Engine::setActiveScene("Main");
}

void SelectionManager::resetSelection()
{
    m_selected = false;
    m_chrono.stop();
    m_entity.m_scene.getEntity("Music").getComponent<ray::MusicStream>("MusicFact").setVolume(100).play("Music");
}

void SelectionManager::addPlayer()
{
    m_nbrPlayer += 1;
}

void SelectionManager::removePlayer()
{
    m_nbrPlayer -= 1;
}