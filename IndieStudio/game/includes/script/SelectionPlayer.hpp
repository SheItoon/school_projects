/*
** EPITECH PROJECT, 2021
** SelectionPlayer.hpp
** File description:
** SelectionPlayer.hpp
*/

#ifndef SELECTIONPLAYER_HPP
#define SELECTIONPLAYER_HPP

#include "SW/Components.hpp"
#include "resources/Texture.hpp"
#include "resources/Model.hpp"

class SelectionPlayer : public sw::Script
{
public:
    enum {
        PLAYER,
        AI,
        NONE
    } m_mode;
private:
    enum {
        SELECTED,
        NOTSELECTED
    } m_select;
    enum {
        UP,
        DOWN
    } m_state;
    int m_player;
    std::vector<ray::RModel> m_models;
    float m_animTime;
    std::string m_skin;
public:
    explicit SelectionPlayer(sw::Entity& entity);
    ~SelectionPlayer() override = default;
    void start() override;
    void update() override;
    SelectionPlayer& setPlayer(int player);
    SelectionPlayer& selected();
    SelectionPlayer& unselected();
    SelectionPlayer& change();

    [[nodiscard]] int getPlayerNbr() const;
    [[nodiscard]] int getPlayerType() const;
    [[nodiscard]] std::string getSkin() const;
};

#endif //SELECTIONPLAYER_HPP
