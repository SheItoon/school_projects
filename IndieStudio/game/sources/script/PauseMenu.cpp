/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** PauseManager.cpp
*/

#include "component/Sprite.hpp"
#include "component/Text.hpp"
#include "component/Audio.hpp"
#include "component/Music.hpp"
#include "component/Transform.hpp"
#include "factory/SpriteFact.hpp"
#include "script/PauseManager.hpp"
#include "script/GameManager.hpp"
#include "script/MenuManager.hpp"
#include "script/Option.hpp"
#include "utils/Input.hpp"
#include "scene/MainMenu.hpp"
#include "save_load/SaveManager.hpp"

PauseManager::PauseManager(sw::Entity& entity)
    :   sw::Script{entity},
        m_index{0},
        m_changed{false},
        m_selected{false},
        m_isShow{true},
        m_state(NOTOPTION)
{}

void PauseManager::start()
{
    auto& scene = m_entity.m_scene;

    auto& bgEnt = scene.createEntity("BackGround");
    auto& resumeBt = scene.createEntity("ResumeButton");
    auto& optionBt = scene.createEntity("OptionButton");
    auto& menuBt = scene.createEntity("MenuButton");
    auto& title = scene.createEntity("PauseTitle");

    auto& sprFact = scene.getFactory<ray::SpriteFact>("SpriteFact");

    auto& bgSpr = sprFact.createComponent(bgEnt.m_name);
    auto& bgTfm = bgEnt.createComponent<ray::Transform>("TransformFact");
    bgSpr.setTexture("DialogBox").setColor(GRAY).loadSpriteImage();
    bgTfm.setPosition({556.8, 380, 0});
    bgTfm.setScale({1.22, 1, 1});
    sprFact.setLayer(bgEnt.m_name, 50);

    auto& resumeSpr = sprFact.createComponent(resumeBt.m_name);
    auto& resumeTfm = resumeBt.createComponent<ray::Transform>("TransformFact");
    resumeSpr.setTexture("ResumeButton").setColor(GRAY).loadSpriteImage();
    resumeTfm.setPosition({600, 650, 0});
    sprFact.setLayer(resumeBt.m_name, 51);

    auto& optionSpr = sprFact.createComponent(optionBt.m_name);
    auto& optionTfm = optionBt.createComponent<ray::Transform>("TransformFact");
    optionSpr.setTexture("SettingsButton").setColor(GRAY).loadSpriteImage();
    optionTfm.setPosition({850, 650, 0});
    sprFact.setLayer(optionBt.m_name, 51);

    auto& menuSpr = sprFact.createComponent(menuBt.m_name);
    auto& menuTfm = menuBt.createComponent<ray::Transform>("TransformFact");
    menuSpr.setTexture("MenuButton").setColor(GRAY).loadSpriteImage();
    menuTfm.setPosition({1100, 650, 0});
    sprFact.setLayer(menuBt.m_name, 51);

    auto& titleText = title.createComponent<ray::Text>("TextFact");
    auto& titleTfm = title.createComponent<ray::Transform>("TransformFact");
    titleText.setColor(WHITE);
    titleText.setSize(50);
    titleText.setString("PAUSE");
    titleTfm.setPosition({890, 470, 0});

    m_entity.createComponent<ray::Audio>("AudioFact").addSound("Switch_1", "Switch1").addSound("Switch_2", "Switch2").addSound("Switch_3", "Switch3").addSound("Selection", "Select");
    activation();
    m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact").addScript<Option>(optionBt.m_name);
}

void PauseManager::update()
{
    if (m_selected) {
        doAction();
        return;
    }

    auto& resumeSpr = m_entity.m_scene.getEntity("ResumeButton").getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& optionSpr = m_entity.m_scene.getEntity("OptionButton").getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& menuSpr = m_entity.m_scene.getEntity("MenuButton").getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& audioCpt = m_entity.getComponent<ray::Audio>("AudioFact");
    static bool mPadAction = false;

    float axisValue = ray::Input::GetGamepadAxis(0, 1);
    std::string audioSName = "Switch" + std::to_string(std::rand() % 3 + 1);

    if ((axisValue > 0.81f && !m_changed)
    || ray::Input::IsGamePadButtonPressed(0, 3)
    || ray::Input::GetKeyPressed(ray::KEY_LEFT)) {
        m_index = (m_index >= 2) ? 0 : m_index + 1;
        audioCpt.play(audioSName);
        m_changed = true;
    }
    else if ((axisValue < -0.81f && !m_changed)
    || ray::Input::IsGamePadButtonPressed(0, 1)
    || ray::Input::GetKeyPressed(ray::KEY_RIGHT)) {
        m_index = (m_index == 0) ? 2 : m_index - 1;
        audioCpt.play(audioSName);
        m_changed = true;
    }
    else if (axisValue < 0.8f && axisValue > -0.8f)
        m_changed = false;


    sw::Vector2f mousePos = ray::Input::GetMousePosition();

    if (resumeSpr.PointOnImage(mousePos)) {
        if (m_index != 0) {
            m_index = 0;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (optionSpr.PointOnImage(mousePos)) {
        if (m_index != 1) {
            m_index = 1;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (menuSpr.PointOnImage(mousePos)) {
        if (m_index != 2) {
            m_index = 2;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (mPadAction && !m_changed) {
        mPadAction = false;
        m_index = 3;
    }


    switch (m_index) {
        case 0:
            resumeSpr.setColor(WHITE);
            break;
        case 1:
            optionSpr.setColor(WHITE);
            break;
        case 2:
            menuSpr.setColor(WHITE);
            break;
        case 3:
            menuSpr.setColor(GRAY);
            menuSpr.setColor(GRAY);
            menuSpr.setColor(GRAY);
            break;
    }

    if (ray::Input::GetKeyPressed(ray::KEY_ENTER)
    || ray::Input::IsGamePadButtonPressed(0, 7)
    || ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_LEFT))
        m_selected = true;
}

void PauseManager::activation()
{
    auto& scene = m_entity.m_scene;
    auto& gameManager = m_entity.m_scene.getEntity("GameManager").getComponent<GameManager>("ScriptFact");

    m_isShow = !m_isShow;
    m_entity.setActive(m_isShow);
    scene.getEntity("BackGround").setActive(m_isShow);
    scene.getEntity("ResumeButton").setActive(m_isShow);
    scene.getEntity("OptionButton").setActive(m_isShow);
    scene.getEntity("MenuButton").setActive(m_isShow);
    scene.getEntity("PauseTitle").setActive(m_isShow);
    if (gameManager.getGameState() != GameManager::LOADING)
        gameManager.setGameState((gameManager.getGameState() == GameManager::INGAME) ? GameManager::PAUSE : GameManager::INGAME);
}

void PauseManager::doAction()
{
    if (m_state == OPTION)
        return;
    m_entity.getComponent<ray::Audio>("AudioFact").play("Select");
    switch (m_index) {
        case 0:
            activation();
            break;
        case 1:
            m_entity.m_scene.getEntity("BackGround").setActive(false);
            m_entity.m_scene.getEntity("ResumeButton").setActive(false);
            m_entity.m_scene.getEntity("OptionButton").getComponent<ray::Sprite>("SpriteFact").setActive(false);
            //m_entity.m_scene.getEntity("OptionButton").setActive(false);
            m_entity.m_scene.getEntity("MenuButton").setActive(false);
            m_entity.m_scene.getEntity("PauseTitle").setActive(false);
            m_entity.m_scene.getEntity("OptionButton").getComponent<Option>("ScriptFact").show();
            m_state = OPTION;
            break;
        case 2:
            SaveManager save(sw::Engine::activeScene());
            m_entity.m_scene.getEntity("GameManager").getComponent<ray::MusicStream>("MusicFact").stop();
            sw::Engine::setActiveScene("MainMenu");
            sw::Engine::getScene<MainMenu>("MainMenu").getEntity("MenuManager").getComponent<MenuManager>("ScriptFact").resetSelection();

            break;
    }
    m_selected = false;
}

void PauseManager::reset()
{
    if (m_state != OPTION)
        return;
    m_entity.m_scene.getEntity("ResumeButton").setActive(true);
    m_entity.m_scene.getEntity("OptionButton").setActive(true);
    m_entity.m_scene.getEntity("MenuButton").setActive(true);
    m_entity.m_scene.getEntity("BackGround").setActive(true);
    m_entity.m_scene.getEntity("PauseTitle").setActive(true);
    m_entity.m_scene.getEntity("OptionButton").getComponent<ray::Sprite>("SpriteFact").setActive(true);
    m_state = NOTOPTION;
}