/*
** EPITECH PROJECT, 2021
** Player.cpp
** File description:
** Player.cpp
*/

#include <cmath>

#include "script/Player.hpp"
#include "SW/Scene.hpp"

#include "component/components.hpp"
#include "factory/factories.hpp"
#include "script/GameManager.hpp"
#include "script/MapGenerator.hpp"
#include "script/Bombe.hpp"
#include "script/PauseManager.hpp"

#include "utils/Input.hpp"
#include "Module.hpp"

Player::Player(sw::Entity &entity) :
sw::Script(entity),
m_live(1),
m_speed(3),
m_skin("PlayerRed"),
m_player(0),
m_bomb(1),
m_max(1),
m_origin({0, 0}),
m_wallPass(false),
m_quadDir(true),
m_range(1)
{}

Player& Player::setPlayer(int player)
{
    m_player = player;
    return (*this);
}

Player& Player::setSkin(std::string player)
{
    m_skin = std::move(player);
    m_entity.getComponent<ray::Mesh>("MeshFact").setModel(m_skin);
    return (*this);
}

Player& Player::setOrigin(const sw::Vector2f& vec)
{
    m_origin = vec;
    return (*this);
}

void Player::start()
{
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");

    switch (m_player) {
        case 0:
            m_origin = {30, 60};
            break;
        case 1:
            m_origin = {1500, 60};
            break;
        case 2:
            m_origin = {30, 800};
            break;
        case 3:
            m_origin = {1500, 800};
            break;
    }
    trans.setScale(6, 6, 6);
    auto& mesh = m_entity.createComponent<ray::Mesh>("MeshFact");
    m_entity.insertComponent<ray::Collider, ray::CubeCollider>("PlayerColliderFact", Vector3{-0.05, -0.05, -0.05}, Vector3{0.1, 0.2, 0.1});
    m_entity.createComponent<ray::Movement>("MovementFact");
    CreateIcon();
}

void Player::update()
{
    auto& gameManager = m_entity.m_scene.getEntity("GameManager").getComponent<GameManager>("ScriptFact");

    if (gameManager.getGameState() != GameManager::STARTING && m_player != 0 && (ray::Input::IsGamePadButtonPressed(m_player, 15) || ray::Input::GetKeyPressed(ray::Keyboard::KEY_P)))
        m_entity.m_scene.getEntity("PauseManager").getComponent<PauseManager>("ScriptFact").activation();
    if (gameManager.getGameState() != GameManager::INGAME)
        return;
    auto& trans = m_entity.getComponent<ray::Transform>("TransformFact");
    auto x = ray::Input::GetGamepadAxis(m_player, 0);
    auto y = ray::Input::GetGamepadAxis(m_player, 1);
    float time = dynamic_cast<ray::Module&>(sw::Engine::activeModule()).getDeltaTime();
    sw::Vector3f vec = (m_quadDir ? getAxis(x, y) * m_speed * time : sw::Vector3f{x * m_speed * time, 0, y * m_speed * time});
    auto& mov = m_entity.getComponent<ray::Movement>("MovementFact");

    mov.x = vec.x;
    mov.y = vec.y;
    mov.z = vec.z;
    if (ray::Input::IsGamePadButtonPressed(m_player, 7))
        SpawnBomb();
    trans.setRotation(getAngle(x, y));

    if (ray::Input::GetKeyPressed(ray::KEY_X))
        m_quadDir = !m_quadDir;
}

float Player::getAngle(float x, float y)
{
    auto& trans = m_entity.getComponent<ray::Transform>("TransformFact");
    float angle = 0;

    if (m_quadDir) {
        if (std::abs(x) < 0.2f && std::abs(y) < 0.2f)
            return (trans.getAngle());
        if (std::abs(x) > std::abs(y))
            return ((x > 0) ? 90.0f : -90.0f);
        else
            return ((y > 0) ? 0.0f : 180.0f);
    }
    else {
        if (x == 0)
            return (trans.getAngle());
        angle = (atan(y / x) * 180 / 3.1415) + 90;
        if ((int)angle == 0)
            angle = 180;
        else if ((int)angle == 180)
            angle = 0;
        if (x > 0)
            angle += 180;
        angle = -angle;
    }
    return (angle);
}

sw::Vector3f Player::getAxis(float x, float y)
{
    auto& trans = m_entity.getComponent<ray::Transform>("TransformFact");

    if (std::abs(x) < 0.2f && std::abs(y) < 0.2f)
        return (sw::Vector3f{ 0.0f, 0.0f, 0.0f });
    if (std::abs(x) > std::abs(y))
        return (sw::Vector3f{ (x > 0) ? 1.0f : -1.0f, 0.0f, 0.0f });
    else
        return (sw::Vector3f{ 0.0f, 0.0f, (y > 0) ? 1.0f : -1.0f });
}

void Player::SpawnBomb()
{

    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
    std::vector<std::string>& map = dynamic_cast<MapGenerator&>(scriptFact["Map"]).get_map();
    auto& trans = m_entity.getComponent<ray::Transform>("TransformFact");

    if (map.at(std::lround(trans.getPosition().x)*-1).at(std::lround(trans.getPosition().z)) != 'O') {
        if (m_bomb == 0)
            return;
        m_bomb -= 1;
        auto& trans = m_entity.getComponent<ray::Transform>("TransformFact");
        auto& bomb = m_entity.m_scene.createEntity("Bomb" + std::to_string(m_player) + "_" + std::to_string(trans.getPosition().x) + "_" + std::to_string(trans.getPosition().y) + "_" + std::to_string(m_bomb));
        auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
        m_entity.m_scene.getEntity(m_entity.m_name + "_NbrBomb").getComponent<ray::Text>("TextFact").setString("x" + std::to_string(m_bomb));
        dynamic_cast<MapGenerator&>(scriptFact["Map"]).addBombeMap(trans);
        scriptFact.addScript<Bombe>(bomb.m_name, m_entity.m_name);
    }
}

static std::string getIcon(std::string skin)
{
    if (skin == "Player")
        return (std::string("WhiteBomberLeft"));
    if (skin == "PlayerBlue")
        return (std::string("BlueBomberLeft"));
    if (skin == "PlayerGreen")
        return (std::string("GreenBomberLeft"));
    if (skin == "PlayerRed")
        return (std::string("PinkBomberLeft"));
    return (std::string("BlueBomberRight"));
}

void Player::CreateIcon()
{
    auto& origin = m_entity.getComponent<ray::Transform>("TransformFact").getPosition();

    auto& icon = m_entity.m_scene.createEntity(m_entity.m_name + "_Icon");
    auto& trans_icon = icon.createComponent<ray::Transform>("TransformFact");

    auto& name = m_entity.m_scene.createEntity(m_entity.m_name + "_Name");
    auto& trans_name = name.createComponent<ray::Transform>("TransformFact");


    auto& bomb = m_entity.m_scene.createEntity(m_entity.m_name + "_NbrBomb");
    auto& speed = m_entity.m_scene.createEntity(m_entity.m_name + "_Speed");
    auto& range = m_entity.m_scene.createEntity(m_entity.m_name + "_Range");
    auto& trans_bomb = bomb.createComponent<ray::Transform>("TransformFact");
    auto& trans_speed = speed.createComponent<ray::Transform>("TransformFact");
    auto& trans_range = range.createComponent<ray::Transform>("TransformFact");

    icon.createComponent<ray::Sprite>("SpriteFact").setTexture(getIcon(m_skin));
    trans_icon.setPosition(m_origin.x, m_origin.y);

    name.createComponent<ray::Text>("TextFact").setString(m_entity.m_name).setSize(50).setSpacing(5.0f);
    trans_name.setPosition(m_origin.x + 150, m_origin.y + 50);

    speed.createComponent<ray::Text>("TextFact").setString("x" + std::string(TextFormat("%.2f", m_speed))).setSize(30).setSpacing(5.0f);
    trans_speed.setPosition(m_origin.x+ 250, m_origin.y + 110);

    bomb.createComponent<ray::Text>("TextFact").setString("x" + std::to_string(m_bomb)).setSize(30).setSpacing(5.0f);
    trans_bomb.setPosition(m_origin.x + 250, m_origin.y + 190);

    range.createComponent<ray::Text>("TextFact").setString("x" + std::to_string(m_range)).setSize(30).setSpacing(5.0f);
    trans_range.setPosition(m_origin.x+ 250, m_origin.y + 150);
}

Player& Player::addBomb(int bomb)
{
    auto& bombEntity = m_entity.m_scene.createEntity(m_entity.m_name + "_NbrBomb");

    if (m_bomb + bomb > m_max)
        m_bomb = m_max;
    else
        m_bomb += bomb;
    bombEntity.getComponent<ray::Text>("TextFact").setString("x" + std::to_string(m_bomb));
    return (*this);
}

Player& Player::setMaxBomb(int max)
{
    m_max = max;
    addBomb(1);
    return (*this);
}

int Player::getBomb() const
{
    return (m_bomb);
}

int Player::getMax() const
{
    return (m_max);
}

Player& Player::setLive(int live)
{
    m_live = live;
    return (*this);
}

int Player::getLive() const
{
    return (m_live);
}

std::string Player::getString() const
{
    return (m_skin);
}

Player & Player::setSpeed(float speed)
{
    auto& speedEntity = m_entity.m_scene.createEntity(m_entity.m_name + "_Speed");

    m_speed = speed;
    speedEntity.getComponent<ray::Text>("TextFact").setString("x" + std::string(TextFormat("%.2f", m_speed)));
    return (*this);
}

float Player::getSpeed() const
{
    return (m_speed);
}

Player & Player::setWallPass(bool pass)
{
    m_wallPass = pass;
    return (*this);
}

bool Player::getWallPass() const
{
    return (m_wallPass);
}

Player & Player::setRange(int range)
{
    auto& rangeEntity = m_entity.m_scene.createEntity(m_entity.m_name + "_Range");

    m_range = range;
    rangeEntity.getComponent<ray::Text>("TextFact").setString("x" + std::to_string(m_range));
    return (*this);
}

int Player::getRange() const
{
    return (m_range);
}

Player& Player::takeDamage()
{
    m_entity.setActive(false);

    m_entity.m_scene.getEntity("GameManager").getComponent<GameManager>("ScriptFact").playerDeath(m_entity.m_name, m_skin);
    return (*this);
}