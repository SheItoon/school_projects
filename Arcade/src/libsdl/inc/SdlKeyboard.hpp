/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SfmlKeyboard.hpp
*/

#ifndef __SFML_KEYBOARD_H__
#define __SFML_KEYBOARD_H__

#include <unordered_map>
#include <SDL2/SDL_keyboard.h>

#include "../../../inc/Keyboard.hpp"

namespace sdl
{

    static const std::unordered_map<arc::Keyboard, SDL_Keycode> keyboardMap =
    {

        {arc::Keyboard::Unknown,    SDLK_UNKNOWN},
        {arc::Keyboard::A,          SDLK_a},
        {arc::Keyboard::B,          SDLK_b},
        {arc::Keyboard::C,          SDLK_c},
        {arc::Keyboard::D,          SDLK_d},
        {arc::Keyboard::E,          SDLK_e},
        {arc::Keyboard::F,          SDLK_f},
        {arc::Keyboard::G,          SDLK_g},
        {arc::Keyboard::H,          SDLK_h},
        {arc::Keyboard::I,          SDLK_i},
        {arc::Keyboard::J,          SDLK_j},
        {arc::Keyboard::K,          SDLK_k},
        {arc::Keyboard::L,          SDLK_l},
        {arc::Keyboard::M,          SDLK_m},
        {arc::Keyboard::N,          SDLK_n},
        {arc::Keyboard::O,          SDLK_o},
        {arc::Keyboard::P,          SDLK_p},
        {arc::Keyboard::Q,          SDLK_q},
        {arc::Keyboard::R,          SDLK_r},
        {arc::Keyboard::S,          SDLK_s},
        {arc::Keyboard::T,          SDLK_t},
        {arc::Keyboard::U,          SDLK_u},
        {arc::Keyboard::V,          SDLK_v},
        {arc::Keyboard::W,          SDLK_w},
        {arc::Keyboard::X,          SDLK_x},
        {arc::Keyboard::Y,          SDLK_y},
        {arc::Keyboard::Z,          SDLK_z},
        {arc::Keyboard::Num0,       SDLK_0},
        {arc::Keyboard::Num1,       SDLK_1},
        {arc::Keyboard::Num2,       SDLK_2},
        {arc::Keyboard::Num3,       SDLK_3},
        {arc::Keyboard::Num4,       SDLK_4},
        {arc::Keyboard::Num5,       SDLK_5},
        {arc::Keyboard::Num6,       SDLK_6},
        {arc::Keyboard::Num7,       SDLK_7},
        {arc::Keyboard::Num8,       SDLK_8},
        {arc::Keyboard::Num9,       SDLK_9},
        {arc::Keyboard::Escape,     SDLK_ESCAPE},

        {arc::Keyboard::LControl,   SDLK_UNKNOWN},
        {arc::Keyboard::LShift,     SDLK_UNKNOWN},
        {arc::Keyboard::LAlt,       SDLK_UNKNOWN},
        {arc::Keyboard::LSystem,    SDLK_UNKNOWN},
        {arc::Keyboard::RControl,   SDLK_UNKNOWN},
        {arc::Keyboard::RShift,     SDLK_UNKNOWN},
        {arc::Keyboard::RAlt,       SDLK_UNKNOWN},
        {arc::Keyboard::RSystem,    SDLK_UNKNOWN},

        {arc::Keyboard::Menu,       SDLK_MENU},
        {arc::Keyboard::LBracket,   SDLK_LEFTBRACKET},
        {arc::Keyboard::RBracket,   SDLK_RIGHTBRACKET},
        {arc::Keyboard::Semicolon,  SDLK_SEMICOLON},
        {arc::Keyboard::Comma,      SDLK_COMMA},
        {arc::Keyboard::Period,     SDLK_PERIOD},
        {arc::Keyboard::Quote,      SDLK_QUOTE},
        {arc::Keyboard::Slash,      SDLK_SLASH},
        {arc::Keyboard::Backslash,  SDLK_BACKSLASH},
        {arc::Keyboard::Tilde,      SDLK_BACKQUOTE},
        {arc::Keyboard::Equal,      SDLK_EQUALS},
        {arc::Keyboard::Hyphen,     SDLK_MINUS},
        {arc::Keyboard::Space,      SDLK_SPACE},
        {arc::Keyboard::Enter,      SDLK_RETURN},
        {arc::Keyboard::Backspace,  SDLK_BACKSPACE},
        {arc::Keyboard::Tab,        SDLK_TAB},
        {arc::Keyboard::PageUp,     SDLK_PAGEUP},
        {arc::Keyboard::PageDown,   SDLK_PAGEDOWN},
        {arc::Keyboard::End,        SDLK_END},
        {arc::Keyboard::Home,       SDLK_HOME},
        {arc::Keyboard::Insert,     SDLK_INSERT},
        {arc::Keyboard::Delete,     SDLK_DELETE},
        {arc::Keyboard::Add,        SDLK_PLUS},
        {arc::Keyboard::Subtract,   SDLK_MINUS},
        {arc::Keyboard::Multiply,   SDLK_ASTERISK},
        {arc::Keyboard::Divide,     SDLK_COLON},
        {arc::Keyboard::Left,       SDLK_LEFT},
        {arc::Keyboard::Right,      SDLK_RIGHT},
        {arc::Keyboard::Up,         SDLK_UP},
        {arc::Keyboard::Down,       SDLK_DOWN},
        {arc::Keyboard::Numpad0,    SDLK_KP_0},
        {arc::Keyboard::Numpad1,    SDLK_KP_1},
        {arc::Keyboard::Numpad2,    SDLK_KP_2},
        {arc::Keyboard::Numpad3,    SDLK_KP_3},
        {arc::Keyboard::Numpad4,    SDLK_KP_4},
        {arc::Keyboard::Numpad5,    SDLK_KP_5},
        {arc::Keyboard::Numpad6,    SDLK_KP_6},
        {arc::Keyboard::Numpad7,    SDLK_KP_7},
        {arc::Keyboard::Numpad8,    SDLK_KP_8},
        {arc::Keyboard::Numpad9,    SDLK_KP_9},
        {arc::Keyboard::F1,         SDLK_F1},
        {arc::Keyboard::F2,         SDLK_F2},
        {arc::Keyboard::F3,         SDLK_F3},
        {arc::Keyboard::F4,         SDLK_F4},
        {arc::Keyboard::F5,         SDLK_F5},
        {arc::Keyboard::F6,         SDLK_F6},
        {arc::Keyboard::F7,         SDLK_F7},
        {arc::Keyboard::F8,         SDLK_F8},
        {arc::Keyboard::F9,         SDLK_F9},
        {arc::Keyboard::F10,        SDLK_F10},
        {arc::Keyboard::F11,        SDLK_F11},
        {arc::Keyboard::F12,        SDLK_F12},
        {arc::Keyboard::F13,        SDLK_F13},
        {arc::Keyboard::F14,        SDLK_F14},
        {arc::Keyboard::F15,        SDLK_F15},
        {arc::Keyboard::Pause,      SDLK_PAUSE}

    }; // keyboardMap

} // namespace sfml

#endif // __SFML_KEYBOARD_H__