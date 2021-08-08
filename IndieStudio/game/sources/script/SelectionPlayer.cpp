/*
** EPITECH PROJECT, 2021
** SelectionPlayer.cpp
** File description:
** SelectionPlayer.cpp
*/

#include "script/SelectionPlayer.hpp"
#include "script/SelectionManager.hpp"
#include "component/components.hpp"
#include "Module.hpp"

static double easeInOutQuad( double t )
{
    return (t < 0.5 ? 2 * t * t : t * (4 - 2 * t) - 1);
}

static float make_blue(float red)
{
  if (red < 1.f)
    return red;
  return 2.f - red;
}

SelectionPlayer::SelectionPlayer(sw::Entity &entity) :
sw::Script(entity),
m_mode(PLAYER),
m_player(0),
m_models(),
m_select(NOTSELECTED),
m_state(UP),
m_animTime(0),
m_skin()
{}

std::string getModel(int player)
{
    switch (player) {
        case 1:
            return (std::string("Player"));
        case 2:
            return (std::string("PlayerBlue"));
        case 3:
            return (std::string("PlayerGreen"));
        default:
            return (std::string("PlayerRed"));
    }
}

void SelectionPlayer::start()
{
    m_mode = (m_player == 1) ? NONE : AI;
    if (m_player == 2)
        m_mode = PLAYER;
    auto& title = m_entity.m_scene.createEntity("Player_" + std::to_string(m_player) + "_title");
    auto& mode = m_entity.m_scene.createEntity("Player_" + std::to_string(m_player) + "_mode");
    auto& model = m_entity.m_scene.createEntity("Player_" + std::to_string(m_player) + "_model");
    auto& selectRight = m_entity.m_scene.createEntity("Player_" + std::to_string(m_player) + "_selectR");
    auto& selectLeft = m_entity.m_scene.createEntity("Player_" + std::to_string(m_player) + "_selectL");
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");
    sw::Vector3f pos;

    trans.setPosition(100.0f + (300.0f * (m_player - 1.0f)), 100);

    pos = trans.getPosition();
    auto& title_trans = title.createComponent<ray::Transform>("TransformFact");
    title_trans.setPosition(pos);
    title.createComponent<ray::Text>("TextFact").setString(std::string("Player" + std::to_string(m_player))).setSize(40).setSpacing(5).setColor(GRAY);

    m_skin = getModel(m_player);
    model.createComponent<ray::Mesh>("MeshFact").setModel(m_skin);
    auto& trans_model = model.createComponent<ray::Transform>("TransformFact");
    trans_model.setPosition(-42.0f + (13.0f * (m_player - 1.0f)), 9, 0);
    trans_model.setScale(30, 30, 30);

    auto& trans_mode = mode.createComponent<ray::Transform>("TransformFact");
    trans_mode.setPosition(pos.x + (m_mode == PLAYER ? 35.0f : 60.0f), pos.y + 250);
    mode.createComponent<ray::Text>("TextFact").setString(std::string((m_mode == PLAYER) ? "Player" : "AI")).setSize(30).setSpacing(5).setColor(GRAY);

    auto& trans_selectR = selectRight.createComponent<ray::Transform>("TransformFact");
    trans_selectR.setPosition(pos.x + (m_mode == PLAYER ? 10.0f : 35.0f), pos.y + 245);
    selectRight.createComponent<ray::Text>("TextFact").setString(std::string("<")).setSize(40).setSpacing(5).setColor(GRAY);
    auto& trans_selectL = selectLeft.createComponent<ray::Transform>("TransformFact");
    trans_selectL.setPosition(pos.x + (m_mode == PLAYER ? 160.0f : 105.0f), pos.y + 245);
    selectLeft.createComponent<ray::Text>("TextFact").setString(std::string(">")).setSize(40).setSpacing(5).setColor(GRAY);
    change();
    if (m_mode == PLAYER)
        selected();
}

void SelectionPlayer::update()
{
    float time = dynamic_cast<ray::Module&>(sw::Engine::activeModule()).getDeltaTime();
    auto& model = m_entity.m_scene.getEntity("Player_" + std::to_string(m_player) + "_model");
    auto& trans = model.getComponent<ray::Transform>("TransformFact");

    if (m_select == SELECTED && m_mode != NONE) {
        m_animTime += time;
        while (m_animTime > 2.0f)
            m_animTime -= 2.0f;
        auto temp_y = easeInOutQuad(make_blue(m_animTime));
        temp_y -= 0.5f;
        trans.move(0, temp_y * 0.1, 0);
        model.getComponent<ray::Transform>("TransformFact").rotate(50 * time);
    } else {
        m_animTime = 0.0f;
        trans.setRotation(0);
        trans.setPosition(-42.0f + (13.0f * (m_player - 1.0f)), 9, 0);
    }
}

SelectionPlayer & SelectionPlayer::setPlayer(int player)
{
    m_player = player;
    return (*this);
}

SelectionPlayer & SelectionPlayer::selected()
{
    auto& title = m_entity.m_scene.getEntity("Player_" + std::to_string(m_player) + "_title");

    m_select = SELECTED;
    title.getComponent<ray::Text>("TextFact").setColor(RED);
    return (*this);
}

SelectionPlayer & SelectionPlayer::unselected()
{
    auto& title = m_entity.m_scene.getEntity("Player_" + std::to_string(m_player) + "_title");

    m_select = NOTSELECTED;
    title.getComponent<ray::Text>("TextFact").setColor(GRAY);
    return (*this);
}

SelectionPlayer & SelectionPlayer::change()
{
    auto& pos = m_entity.getComponent<ray::Transform>("TransformFact").getPosition();
    auto& mode = m_entity.m_scene.getEntity("Player_" + std::to_string(m_player) + "_mode");
    auto& selectRight = m_entity.m_scene.getEntity("Player_" + std::to_string(m_player) + "_selectR");
    auto& selectLeft = m_entity.m_scene.getEntity("Player_" + std::to_string(m_player) + "_selectL");
    auto& model = m_entity.m_scene.getEntity("Player_" + std::to_string(m_player) + "_model");

    if (m_mode == PLAYER) {
        m_mode = AI;
        mode.getComponent<ray::Text>("TextFact").setString(std::string("AI"));
        mode.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 60.0f, pos.y + 250);
        selectRight.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 35.0f, pos.y + 245);
        selectRight.getComponent<ray::Text>("TextFact").setString(std::string("<")).setSize(40).setSpacing(5);
        selectLeft.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 105.0f, pos.y + 245);
        selectLeft.getComponent<ray::Text>("TextFact").setString(std::string(">")).setSize(40).setSpacing(5);
    } else if (m_mode == AI) {
        m_mode = NONE;
        m_entity.m_scene.getEntity("SelectionManager").getComponent<SelectionManager>("ScriptFact").removePlayer();
        mode.getComponent<ray::Text>("TextFact").setString(std::string("None"));
        mode.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 50.0f, pos.y + 250);
        selectRight.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 30.0f, pos.y + 245);
        selectRight.getComponent<ray::Text>("TextFact").setString(std::string("<")).setSize(40).setSpacing(5);
        selectLeft.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 135.0f, pos.y + 245);
        selectLeft.getComponent<ray::Text>("TextFact").setString(std::string(">")).setSize(40).setSpacing(5);
        model.getComponent<ray::Mesh>("MeshFact").setActive(false);
    } else {
        m_mode = PLAYER;
        m_entity.m_scene.getEntity("SelectionManager").getComponent<SelectionManager>("ScriptFact").addPlayer();
        mode.getComponent<ray::Text>("TextFact").setString(std::string("Player"));
        mode.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 35.0f, pos.y + 250);
        selectRight.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 10.0f, pos.y + 245);
        selectRight.getComponent<ray::Text>("TextFact").setString(std::string("<")).setSize(40).setSpacing(5);
        selectLeft.getComponent<ray::Transform>("TransformFact").setPosition(pos.x + 165.0f, pos.y + 245);
        selectLeft.getComponent<ray::Text>("TextFact").setString(std::string(">")).setSize(40).setSpacing(5);
        model.getComponent<ray::Mesh>("MeshFact").setActive(true);
    }
    return (*this);
}

int SelectionPlayer::getPlayerNbr() const
{
    return (m_player);
}

int SelectionPlayer::getPlayerType() const
{
    return (m_mode);
}

std::string SelectionPlayer::getSkin() const
{
    return (m_skin);
}
