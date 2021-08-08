/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SfmlKeyboard.hpp
*/

#ifndef __SFML_KEYBOARD_H__
#define __SFML_KEYBOARD_H__

#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>

#include "../../../inc/Keyboard.hpp"

namespace sfml
{

    static const std::unordered_map<arc::Keyboard, sf::Keyboard::Key> keyboardMap =
    {

        {arc::Keyboard::Unknown,    sf::Keyboard::Key::Unknown},
        {arc::Keyboard::A,          sf::Keyboard::Key::A},
        {arc::Keyboard::B,          sf::Keyboard::Key::B},
        {arc::Keyboard::C,          sf::Keyboard::Key::C},
        {arc::Keyboard::D,          sf::Keyboard::Key::D},
        {arc::Keyboard::E,          sf::Keyboard::Key::E},
        {arc::Keyboard::F,          sf::Keyboard::Key::F},
        {arc::Keyboard::G,          sf::Keyboard::Key::G},
        {arc::Keyboard::H,          sf::Keyboard::Key::H},
        {arc::Keyboard::I,          sf::Keyboard::Key::I},
        {arc::Keyboard::J,          sf::Keyboard::Key::J},
        {arc::Keyboard::K,          sf::Keyboard::Key::K},
        {arc::Keyboard::L,          sf::Keyboard::Key::L},
        {arc::Keyboard::M,          sf::Keyboard::Key::M},
        {arc::Keyboard::N,          sf::Keyboard::Key::N},
        {arc::Keyboard::O,          sf::Keyboard::Key::O},
        {arc::Keyboard::P,          sf::Keyboard::Key::P},
        {arc::Keyboard::Q,          sf::Keyboard::Key::Q},
        {arc::Keyboard::R,          sf::Keyboard::Key::R},
        {arc::Keyboard::S,          sf::Keyboard::Key::S},
        {arc::Keyboard::T,          sf::Keyboard::Key::T},
        {arc::Keyboard::U,          sf::Keyboard::Key::U},
        {arc::Keyboard::V,          sf::Keyboard::Key::V},
        {arc::Keyboard::W,          sf::Keyboard::Key::W},
        {arc::Keyboard::X,          sf::Keyboard::Key::X},
        {arc::Keyboard::Y,          sf::Keyboard::Key::Y},
        {arc::Keyboard::Z,          sf::Keyboard::Key::Z},
        {arc::Keyboard::Num0,       sf::Keyboard::Key::Num0},
        {arc::Keyboard::Num1,       sf::Keyboard::Key::Num1},
        {arc::Keyboard::Num2,       sf::Keyboard::Key::Num2},
        {arc::Keyboard::Num3,       sf::Keyboard::Key::Num3},
        {arc::Keyboard::Num4,       sf::Keyboard::Key::Num4},
        {arc::Keyboard::Num5,       sf::Keyboard::Key::Num5},
        {arc::Keyboard::Num6,       sf::Keyboard::Key::Num6},
        {arc::Keyboard::Num7,       sf::Keyboard::Key::Num7},
        {arc::Keyboard::Num8,       sf::Keyboard::Key::Num8},
        {arc::Keyboard::Num9,       sf::Keyboard::Key::Num9},
        {arc::Keyboard::Escape,     sf::Keyboard::Key::Escape},
        {arc::Keyboard::LControl,   sf::Keyboard::Key::LControl},
        {arc::Keyboard::LShift,     sf::Keyboard::Key::LShift},
        {arc::Keyboard::LAlt,       sf::Keyboard::Key::LAlt},
        {arc::Keyboard::LSystem,    sf::Keyboard::Key::LSystem},
        {arc::Keyboard::RControl,   sf::Keyboard::Key::RControl},
        {arc::Keyboard::RShift,     sf::Keyboard::Key::RShift},
        {arc::Keyboard::RAlt,       sf::Keyboard::Key::RAlt},
        {arc::Keyboard::RSystem,    sf::Keyboard::Key::RSystem},
        {arc::Keyboard::Menu,       sf::Keyboard::Key::Menu},
        {arc::Keyboard::LBracket,   sf::Keyboard::Key::LBracket},
        {arc::Keyboard::RBracket,   sf::Keyboard::Key::RBracket},
        {arc::Keyboard::Semicolon,  sf::Keyboard::Key::Semicolon},
        {arc::Keyboard::Comma,      sf::Keyboard::Key::Comma},
        {arc::Keyboard::Period,     sf::Keyboard::Key::Period},
        {arc::Keyboard::Quote,      sf::Keyboard::Key::Quote},
        {arc::Keyboard::Slash,      sf::Keyboard::Key::Slash},
        {arc::Keyboard::Backslash,  sf::Keyboard::Key::Backslash},
        {arc::Keyboard::Tilde,      sf::Keyboard::Key::Tilde},
        {arc::Keyboard::Equal,      sf::Keyboard::Key::Equal},
        {arc::Keyboard::Hyphen,     sf::Keyboard::Key::Hyphen},
        {arc::Keyboard::Space,      sf::Keyboard::Key::Space},
        {arc::Keyboard::Enter,      sf::Keyboard::Key::Enter},
        {arc::Keyboard::Backspace,  sf::Keyboard::Key::Backspace},
        {arc::Keyboard::Tab,        sf::Keyboard::Key::Tab},
        {arc::Keyboard::PageUp,     sf::Keyboard::Key::PageUp},
        {arc::Keyboard::PageDown,   sf::Keyboard::Key::PageDown},
        {arc::Keyboard::End,        sf::Keyboard::Key::End},
        {arc::Keyboard::Home,       sf::Keyboard::Key::Home},
        {arc::Keyboard::Insert,     sf::Keyboard::Key::Insert},
        {arc::Keyboard::Delete,     sf::Keyboard::Key::Delete},
        {arc::Keyboard::Add,        sf::Keyboard::Key::Add},
        {arc::Keyboard::Subtract,   sf::Keyboard::Key::Subtract},
        {arc::Keyboard::Multiply,   sf::Keyboard::Key::Multiply},
        {arc::Keyboard::Divide,     sf::Keyboard::Key::Divide},
        {arc::Keyboard::Left,       sf::Keyboard::Key::Left},
        {arc::Keyboard::Right,      sf::Keyboard::Key::Right},
        {arc::Keyboard::Up,         sf::Keyboard::Key::Up},
        {arc::Keyboard::Down,       sf::Keyboard::Key::Down},
        {arc::Keyboard::Numpad0,    sf::Keyboard::Key::Numpad0},
        {arc::Keyboard::Numpad1,    sf::Keyboard::Key::Numpad1},
        {arc::Keyboard::Numpad2,    sf::Keyboard::Key::Numpad2},
        {arc::Keyboard::Numpad3,    sf::Keyboard::Key::Numpad3},
        {arc::Keyboard::Numpad4,    sf::Keyboard::Key::Numpad4},
        {arc::Keyboard::Numpad5,    sf::Keyboard::Key::Numpad5},
        {arc::Keyboard::Numpad6,    sf::Keyboard::Key::Numpad6},
        {arc::Keyboard::Numpad7,    sf::Keyboard::Key::Numpad7},
        {arc::Keyboard::Numpad8,    sf::Keyboard::Key::Numpad8},
        {arc::Keyboard::Numpad9,    sf::Keyboard::Key::Numpad9},
        {arc::Keyboard::F1,         sf::Keyboard::Key::F1},
        {arc::Keyboard::F2,         sf::Keyboard::Key::F2},
        {arc::Keyboard::F3,         sf::Keyboard::Key::F3},
        {arc::Keyboard::F4,         sf::Keyboard::Key::F4},
        {arc::Keyboard::F5,         sf::Keyboard::Key::F5},
        {arc::Keyboard::F6,         sf::Keyboard::Key::F6},
        {arc::Keyboard::F7,         sf::Keyboard::Key::F7},
        {arc::Keyboard::F8,         sf::Keyboard::Key::F8},
        {arc::Keyboard::F9,         sf::Keyboard::Key::F9},
        {arc::Keyboard::F10,        sf::Keyboard::Key::F10},
        {arc::Keyboard::F11,        sf::Keyboard::Key::F11},
        {arc::Keyboard::F12,        sf::Keyboard::Key::F12},
        {arc::Keyboard::F13,        sf::Keyboard::Key::F13},
        {arc::Keyboard::F14,        sf::Keyboard::Key::F14},
        {arc::Keyboard::F15,        sf::Keyboard::Key::F15},
        {arc::Keyboard::Pause,      sf::Keyboard::Key::Pause}

    }; // keyboardMap

} // namespace sfml

#endif // __SFML_KEYBOARD_H__