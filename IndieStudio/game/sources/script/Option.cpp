/*
** EPITECH PROJECT, 2021
** Option.cpp
** File description:
** Option.cpp
*/

#include "script/Option.hpp"
#include "component/components.hpp"
#include "factory/factories.hpp"
#include "Module.hpp"
#include "utils/Input.hpp"
#include "script/MenuManager.hpp"
#include "script/PauseManager.hpp"

Option::Option(sw::Entity &entity) :
sw::Script(entity),
m_index(0),
m_state(HIDE),
m_changed(false)
{}

void Option::start()
{
    auto& background = m_entity.m_scene.createEntity("BackGroundOption");
    auto& fullTitle = m_entity.m_scene.createEntity("FullScreenTitle");
    auto& fullValue = m_entity.m_scene.createEntity("FullScreenValue");
    auto& returnButton = m_entity.m_scene.createEntity("OptionReturnButton");
    bool fullscreen = sw::Engine::getModule<ray::Module>("RayLib").isFullScreen();

    auto& trans_background = background.createComponent<ray::Transform>("TransformFact");
    background.createComponent<ray::Sprite>("SpriteFact").setTexture("PlayerSelectBack");
    m_entity.m_scene.getFactory<ray::SpriteFact>("SpriteFact").setLayer(background.m_name, 1);

    auto& trans_fullTitle = fullTitle.createComponent<ray::Transform>("TransformFact");
    trans_fullTitle.setPosition(300, 400);
    fullTitle.createComponent<ray::Text>("TextFact").setString(std::string("FullScreen:")).setSize(50).setSpacing(5);

    auto& trans_fullValue = fullValue.createComponent<ray::Transform>("TransformFact");
    trans_fullValue.setPosition(600, 400);
    fullValue.createComponent<ray::Text>("TextFact").setString(std::string(fullscreen ? "On" : "Off")).setSize(50).setSpacing(5).setColor(RED);

    auto& trans_retButton = returnButton.createComponent<ray::Transform>("TransformFact");
    trans_retButton.setPosition(1600, 900);
    returnButton.createComponent<ray::Sprite>("SpriteFact").setTexture("ReturnButton").setColor(GRAY).loadSpriteImage();
    m_entity.m_scene.getFactory<ray::SpriteFact>("SpriteFact").setLayer(returnButton.m_name, 2);

    m_entity.createComponent<ray::MusicStream>("MusicFact").addSound("OptionMusic", "OptionMusic");

    m_entity.createComponent<ray::Audio>("AudioFact").addSound("Switch_1", "Switch1").addSound("Switch_2", "Switch2").addSound("Switch_3", "Switch3").addSound("Selection", "Select");
    hide();
}

void Option::update()
{
    if (m_state != SHOW)
        return;
    if (m_selected == true) {
        doAction();
        return;
    }

    auto& fullBtn = m_entity.m_scene.getEntity("FullScreenValue").getComponent<ray::Text>("TextFact").setColor(GRAY);
    auto& retBtn = m_entity.m_scene.getEntity("OptionReturnButton").getComponent<ray::Sprite>("SpriteFact").setColor(GRAY);
    auto& audioCpt = m_entity.getComponent<ray::Audio>("AudioFact");
    static bool mPadAction = false;

    float axisValue = ray::Input::GetGamepadAxis(0, 1);
    std::string audioSName = "Switch" + std::to_string(std::rand() % 3 + 1);

    if ((axisValue > 0.81f && !m_changed)
        || ray::Input::IsGamePadButtonPressed(0, 3)
        || ray::Input::GetKeyPressed(ray::KEY_DOWN)) {
        m_index = (m_index >= 1) ? 0 : m_index + 1;
        m_changed = true;
    }
    else if ((axisValue < -0.81f && !m_changed)
             || ray::Input::IsGamePadButtonPressed(0, 1)
             || ray::Input::GetKeyPressed(ray::KEY_UP)) {
        m_index = (m_index == 0) ? 1 : m_index - 1;
        m_changed = true;
    }
    else if (axisValue < 0.8f && axisValue > -0.8f)
        m_changed = false;


    sw::Vector2f mousePos = ray::Input::GetMousePosition();

    if (retBtn.PointOnImage(mousePos)) {
        if (m_index != 1) {
            m_index = 1;
            audioCpt.play(audioSName);
        }
        mPadAction = true;
    } else if (mPadAction && !m_changed) {
        mPadAction = false;
        m_index = 2;
    }

    switch (m_index) {
        case 0:
            fullBtn.setColor(RED);
            break;
        case 1:
            retBtn.setColor(WHITE);
            break;
        case 2:
            retBtn.setColor(GRAY);
            retBtn.setColor(GRAY);
            break;
    }
    if (ray::Input::IsGamePadButtonPressed(0, 7)
    || ray::Input::IsMouseButtonPressed(ray::Mouse::MOUSE_BUTTON_LEFT)
    || ray::Input::GetKeyPressed(ray::Keyboard::KEY_ENTER))
        m_selected = true;
}

void Option::doAction()
{
    if (m_index == 2) {
        m_selected = false;
        return;
    }
    m_entity.getComponent<ray::Audio>("AudioFact").play("Select");
    switch (m_index) {
        case 0:
            sw::Engine::getModule<ray::Module>("RayLib").toggleFullScreen();
            m_entity.m_scene.getEntity("FullScreenValue").getComponent<ray::Text>("TextFact").setString(std::string(sw::Engine::getModule<ray::Module>("RayLib").isFullScreen() ? "On" : "Off"));
            break;
        case 1:
            hide();
            break;
        case 2:
            break;
    }
    m_selected = false;
}

void Option::show()
{
    m_entity.m_scene.getEntity("BackGroundOption").setActive(true);
    m_entity.m_scene.getEntity("FullScreenTitle").setActive(true);
    m_entity.m_scene.getEntity("FullScreenValue").setActive(true);
    m_entity.m_scene.getEntity("OptionReturnButton").setActive(true);
    if (m_entity.m_scene.m_name == "MainMenu")
        m_entity.m_scene.getEntity("MenuManager").setActive(false);
    m_state = SHOW;
    m_entity.getComponent<ray::MusicStream>("MusicFact").play("OptionMusic");
}

void Option::hide()
{
    m_entity.m_scene.getEntity("BackGroundOption").setActive(false);
    m_entity.m_scene.getEntity("FullScreenTitle").setActive(false);
    m_entity.m_scene.getEntity("FullScreenValue").setActive(false);
    m_entity.m_scene.getEntity("OptionReturnButton").setActive(false);
    if (m_entity.m_scene.m_name == "MainMenu") {
        m_entity.m_scene.getEntity("MenuManager").setActive(true);
        m_entity.m_scene.getEntity("MenuManager").getComponent<MenuManager>("ScriptFact").resetSelection();
    } else if (m_entity.m_scene.m_name == "Main") {
        m_entity.m_scene.getEntity("PauseManager").getComponent<PauseManager>("ScriptFact").reset();
    }
    m_state = HIDE;
    m_entity.getComponent<ray::MusicStream>("MusicFact").stop();
}