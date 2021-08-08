/*
** EPITECH PROJECT, 2021
** Main.cpp
** File description:
** Main.cpp
*/

#include "script/Logo.hpp"
#include "component/components.hpp"
#include "utils/Chrono.hpp"
#include "Module.hpp"

Logo::Logo(sw::Entity &entity) :
sw::Script(entity),
m_state(FADE_IN)
{}

void Logo::start()
{
    auto &sprite = m_entity.createComponent<ray::Sprite>("SpriteFact");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformFact");
    auto &audio = m_entity.createComponent<ray::Audio>("AudioFact");

    sprite.setTexture("Logo").setColor({255, 255, 255, 0});
    transform.setPosition(700, 200);
    m_state = FADE_IN;
    audio.addSound("Horn", "Horn").play("Horn");
}

void Logo::update() {
    static sw::Chrono chrono(sw::Chrono::Lauch);
    auto &sprite = m_entity.getComponent<ray::Sprite>("SpriteFact");
    int value;

    if (chrono.getElapsedTime() > 0.01) {
        if (m_state == FADE_IN) {
            value = (sprite.color().getColor().a + 2 >= 255) ? 255 : sprite.color().getColor().a + 2;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (chrono.getTotalTime() >= 3) {
                chrono.start();
                m_state = STAY;
            }
        }
        if (m_state == STAY && chrono.getTotalTime() >= 2) {
            chrono.start();
            m_state = FADE_OUT;
        }
        if (m_state == FADE_OUT) {
            value = (sprite.color().getColor().a - 2 <= 0) ? 0 : sprite.color().getColor().a - 2;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (sprite.color().getColor().a == 0) {
                chrono.stop();
                dynamic_cast<ray::Module &>(sw::Engine::activeModule()).SetBackGroundColor(BLACK).ClearWindowType(FLAG_WINDOW_UNDECORATED);
                sw::Engine::setActiveScene("MainMenu");
            }
        }
        chrono.tour();
    }
}
