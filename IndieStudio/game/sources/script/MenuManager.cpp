/*
** EPITECH PROJECT, 2021
** MenuManager.cpp
** File description:
** MenuManager.cpp
*/

#include "script/MenuManager.hpp"
#include "utils/Input.hpp"
#include "Module.hpp"
#include "script/Option.hpp"
#include "factory/factories.hpp"
#include "scene/Main.hpp"

MenuManager::MenuManager(sw::Entity &entity) :
sw::Script(entity),
m_play("ButtonPlay"),
m_option("ButtonOption"),
m_exit("ButtonExit"),
m_credit("ButtonCredit"),
m_load("ButtonLoad"),
m_index(0),
m_changed(false),
m_selected(false),
m_chrono()
{}

void MenuManager::start()
{
    auto& play = m_entity.m_scene.createEntity(m_play);
    auto& option = m_entity.m_scene.createEntity(m_option);
    auto& exit = m_entity.m_scene.createEntity(m_exit);
    auto& credit = m_entity.m_scene.createEntity(m_credit);
    auto& load = m_entity.m_scene.createEntity(m_load);
    auto& background = m_entity.m_scene.createEntity("MainMenuBack");
    auto& title = m_entity.m_scene.createEntity("MainMenuTitle");

    auto& trans_play = play.createComponent<ray::Transform>("TransformFact");
    trans_play.setPosition(200, 320);
    play.createComponent<ray::Sprite>("SpriteFact").setTexture("PlayButton").setColor(GRAY).loadSpriteImage();

    auto& trans_exit = exit.createComponent<ray::Transform>("TransformFact");
    trans_exit.setPosition(650, 690);
    exit.createComponent<ray::Sprite>("SpriteFact").setTexture("ExitButton").setColor(GRAY).loadSpriteImage();

    auto& trans_credit = credit.createComponent<ray::Transform>("TransformFact");
    trans_credit.setPosition(650, 350);
    credit.createComponent<ray::Sprite>("SpriteFact").setTexture("CreditButton").setColor(GRAY).loadSpriteImage();

    auto& trans_load = load.createComponent<ray::Transform>("TransformFact");
    trans_load.setPosition(200, 720);
    load.createComponent<ray::Sprite>("SpriteFact").setTexture("LoadGameButton").setColor(GRAY).loadSpriteImage();

    background.createComponent<ray::Transform>("TransformFact");
    background.createComponent<ray::Sprite>("SpriteFact").setTexture("MainBackGround");
    background.setLayer("SpriteFact", -1);

    auto& trans_title = title.createComponent<ray::Transform>("TransformFact");
    trans_title.setPosition(500, 100);
    title.createComponent<ray::Text>("TextFact").setString(std::string("IndieMerman")).setSize(120).setSpacing(5.0f);

    m_entity.createComponent<ray::MusicStream>("MusicFact").addSound("MainMenu", "MainMenu").play("MainMenu");
    m_entity.createComponent<ray::Audio>("AudioFact").addSound("Switch_1", "Switch1").addSound("Switch_2", "Switch2").addSound("Switch_3", "Switch3").addSound("ChangeMenu", "Selection");

    auto& trans_option = option.createComponent<ray::Transform>("TransformFact");
    trans_option.setPosition(650, 500);
    option.createComponent<ray::Sprite>("SpriteFact").setTexture("SettingButton").setColor(GRAY).loadSpriteImage();
    m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact").addScript<Option>(option.m_name);
}

void MenuManager::update()
{
    if (m_selected) {
        doAction();
        return;
    }

    auto& playSpr = m_entity.m_scene.getEntity(m_play).getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& optionSpr = m_entity.m_scene.getEntity(m_option).getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& exitSpr = m_entity.m_scene.getEntity(m_exit).getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& creditSpr = m_entity.m_scene.getEntity(m_credit).getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& loadSpr = m_entity.m_scene.getEntity(m_load).getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& audioCpt = m_entity.getComponent<ray::Audio>("AudioFact");
    static bool mPadAction = false;

    float axisValue = ray::Input::GetGamepadAxis(0, 1);
    std::string audioSName = "Switch" + std::to_string(std::rand() % 3 + 1);

    if ((axisValue > 0.81f && !m_changed)
    || ray::Input::IsGamePadButtonPressed(0, 3)
    || ray::Input::GetKeyPressed(ray::KEY_DOWN)) {
        m_index = (m_index >= 4) ? 0 : m_index + 1;
        audioCpt.play(audioSName);
        m_changed = true;
    }
    else if ((axisValue < -0.81f && !m_changed)
    || ray::Input::IsGamePadButtonPressed(0, 1)
    || ray::Input::GetKeyPressed(ray::KEY_UP)) {
        m_index = (m_index == 0) ? 4 : m_index - 1;
        audioCpt.play(audioSName);
        m_changed = true;
    }
    else if (axisValue < 0.8f && axisValue > -0.8f)
        m_changed = false;


    sw::Vector2f mousePos = ray::Input::GetMousePosition();

    if (playSpr.PointOnImage(mousePos)) {
        if (m_index != 0) {
            m_index = 0;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (loadSpr.PointOnImage(mousePos)) {
        if (m_index != 1) {
            m_index = 1;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (creditSpr.PointOnImage(mousePos)) {
        if (m_index != 2) {
            m_index = 2;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (optionSpr.PointOnImage(mousePos)) {
        if (m_index != 3) {
            m_index = 3;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (exitSpr.PointOnImage(mousePos)) {
        if (m_index != 4) {
            m_index = 4;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (mPadAction && !m_changed) {
        mPadAction = false;
        m_index = 5;
    }


    switch (m_index) {
        case 0:
            playSpr.setColor(WHITE);
            break;
        case 1:
            loadSpr.setColor(WHITE);
            break;
        case 2:
            creditSpr.setColor(WHITE);
            break;
        case 3:
            optionSpr.setColor(WHITE);
            break;
        case 4:
            exitSpr.setColor(WHITE);
            break;
        case 5:
            playSpr.setColor(GRAY);
            optionSpr.setColor(GRAY);
            exitSpr.setColor(GRAY);
            break;
    }

    if (ray::Input::GetKeyPressed(ray::KEY_ENTER)
    || ray::Input::IsGamePadButtonPressed(0, 7)
    || ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_LEFT))
        m_selected = true;
}

void MenuManager::doAction()
{
    if (m_index == 5) {
        m_selected = false;
        return;
    }
    if (!m_chrono.isRunning())
        m_chrono = sw::Chrono(sw::Chrono::Lauch);
    if (m_chrono.getElapsedTime() == 0)
        m_entity.getComponent<ray::Audio>("AudioFact").play("Selection");
    if (m_chrono.getElapsedTime() != 0 && m_chrono.getElapsedTime() >= 1) {
        m_selected = false;
        m_entity.getComponent<ray::MusicStream>("MusicFact").stop();
        switch (m_index) {
            case 0:
                Main::loadMode = Main::NEW_GAME;
                m_entity.getComponent<ray::MusicStream>("MusicFact").stop();
                sw::Engine::setActiveScene("MenuSelect");
                dynamic_cast<ray::Module &>(sw::Engine::activeModule()).SetBackGroundColor(BLUE).ClearWindowType(
                        FLAG_WINDOW_UNDECORATED);
                break;
            case 1:
                if (FileExists("resources/save/save.json")) {
                    Main::loadMode = Main::LOADED;
                    m_entity.getComponent<ray::MusicStream>("MusicFact").stop();
                    sw::Engine::setActiveScene("Main");
                    dynamic_cast<ray::Module &>(sw::Engine::activeModule()).SetBackGroundColor(BLUE).ClearWindowType(
                            FLAG_WINDOW_UNDECORATED);
                }
                break;
            case 2:
                sw::Engine::setActiveScene("Credit");
                dynamic_cast<ray::Module &>(sw::Engine::activeModule()).SetBackGroundColor(GRAY).ClearWindowType(
                        FLAG_WINDOW_UNDECORATED);
                break;
            case 3:
                m_entity.m_scene.getEntity("ButtonOption").getComponent<Option>("ScriptFact").show();
                break;
            case 4:
                dynamic_cast<ray::Module &>(sw::Engine::activeModule()).closeWindow();
                break;
        }
    } else
        m_entity.getComponent<ray::MusicStream>("MusicFact").setVolumeDown(1);
}

void MenuManager::resetSelection()
{
    m_selected = false;
    m_chrono.stop();
    m_entity.getComponent<ray::MusicStream>("MusicFact").setVolume(100).play("MainMenu");
}