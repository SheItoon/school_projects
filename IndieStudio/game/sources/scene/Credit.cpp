/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Credit.cpp
*/

#include "component/components.hpp"
#include "factory/factories.hpp"
#include "scene/Credit.hpp"
#include "utils/Input.hpp"
#include "Module.hpp"

void CreditScene::onLoad()
{
    auto& tfmFact = createFactory<ray::TransformFact>("TransformFact");
    auto& sprFact = createFactory<ray::SpriteFact>("SpriteFact");
    auto& txtFact = createFactory<ray::TextFact>("TextFact");
    auto& musicFact = createFactory<ray::MusicFact>("MusicFact");

    createEntity("Background");
    tfmFact.createComponent("Background").setScale(1.1, 1.1, 1);
    sprFact.createComponent("Background").setTexture("Credit").setColor({80, 80, 80, 255});

    createEntity("Title");
    tfmFact.createComponent("Title").setPosition(100, 100, 0);
    auto& title = txtFact.createComponent("Title");
    title.setSize(80);
    title.setColor(GOLD);
    title.setSpacing(5);
    title.setString("Credit:");

    createEntity("Dev");
    tfmFact.createComponent("Dev").setPosition(100, 250, 0);
    auto& text1 = txtFact.createComponent("Dev");
    text1.setSize(50);
    text1.setColor(GOLD);
    text1.setSpacing(5);
    text1.setString(
        "Developer:\n"
        "\t- Guillaume Soisson\n"
        "\t- Guillaume Debard\n"
        "\t- Nicolas Peter\n"
        "\t- Pascal Betty\n"
        "\t- Maxime Payant");

    createEntity("Designer");
    tfmFact.createComponent("Designer").setPosition(1000, 250, 0);
    auto& text2 = txtFact.createComponent("Designer");
    text2.setSize(50);
    text2.setColor(GOLD);
    text2.setSpacing(5);
    text2.setString(
        "Sound Designer:\n"
        "\t- Quentin Feuillard\n\n"
        "Graphical Designer:\n"
        "\t- Guillaume Soisson\n"
        "\t- Guillaume Debard\n"
        "\t- Maxime Payant\n\n");

    createEntity("InfoText");
    auto& txt2 = txtFact.createComponent("InfoText");
    txt2.setString("Press Enter to return to the main menu ...");
    txt2.setColor(PURPLE);
    txt2.setSpacing(5);
    txt2.setSize(20);
    tfmFact.createComponent("InfoText").setPosition({60, 980, 0});

    createEntity("Music");
    musicFact.createComponent("Music").addSound("Credit", "Credit").play("Credit");
    m_url.emplace_back("https://cdn.discordapp.com/attachments/765724587404558376/783437397924904990/image0-3.gif");
    m_url.emplace_back("https://cdn.discordapp.com/attachments/333829883446951950/854749830601244702/image0-1.gif");
    m_url.emplace_back("https://www.youtube.com/watch?v=AdyYp_V9st0");
    m_url.emplace_back("https://www.youtube.com/watch?v=FoiYLQduH9M&list=PLFfUVs7JWNx-S4iZYPZnk2mc7-huhWa7e");
    m_url.emplace_back("https://www.youtube.com/watch?v=Gn9JkTKC9dU&ab_channel=ShinobuAMVsShinobuAMVs");
}

void CreditScene::onUpdate()
{
    std::string url;
    if (ray::Input::GetKeyPressed(ray::Keyboard::KEY_ENTER)
    || ray::Input::IsGamePadButtonPressed(0, 7)) {
        getEntity("Music").getComponent<ray::MusicStream>("MusicFact").stop();
        sw::Engine::setActiveScene("MainMenu");
    }
    if (ray::Input::GetKeyPressed(ray::Keyboard::KEY_S) ||
        ray::Input::IsGamePadButtonPressed(0, 5)) {
        url = m_url.at(std::rand() % m_url.size());
        ray::Module::OpenUrl(url);
    }
}

void CreditScene::onUnload()
{

}