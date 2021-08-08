/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** Bombe
*/

#include "script/Bombe.hpp"
#include "component/components.hpp"
#include "script/MapGenerator.hpp"
#include "script/Fire.hpp"
#include "script/Mob.hpp"
#include "script/Cube.hpp"

#include "factory/factories.hpp"


Bombe::Bombe(sw::Entity &entity, std::string player_name) :
sw::Script(entity),
m_name_player(player_name),
m_chrono(),
m_pos(),
m_state(EXPLODING)
{}

Bombe::~Bombe() noexcept
{
    m_entity.m_scene.deleteEntity(m_entity.m_name);
}

void Bombe::start()
{
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");
    auto& entity_player = m_entity.m_scene.getEntity(m_name_player);
    auto& trans_player = entity_player.getComponent<ray::Transform>("TransformFact");

    m_pos.x = std::lround(trans_player.getPosition().x * -1);
    m_pos.y = std::lround(trans_player.getPosition().z);

    m_entity.createComponent<ray::Mesh>("MeshFact").setModel("Bomb");
    trans.setPosition(std::lround(trans_player.getPosition().x), trans_player.getPosition().y, std::lround(trans_player.getPosition().z));
    trans.setScale(10, 10, 10);
    m_entity.createComponent<ray::Audio>("AudioFact")
            .addSound("BombExplosion1", "Explosion1")
            .addSound("BombExplosion2", "Explosion2")
            .addSound("BombExplosion3", "Explosion3")
            .addSound("BombExplosion4", "Explosion4")
            .addSound("BombTime1", "Time1")
            .addSound("BombTime2", "Time2")
            .addSound("BombTime3", "Time3")
            .addSound("BombTime4", "Time4");

}

void Bombe::destroyBlock(sw::Vector2i pos, std::vector<std::string>& map)
{
        std::cout<< "block = "  << map.at(pos.x).at(pos.y) << std::endl;

        sw::Entity& new_entity = m_entity.m_scene.getEntity("Cube-" + std::to_string(pos.x) + "-" + std::to_string(pos.y));
        new_entity.getComponent<Cube>("ScriptFact").destroy();
        map.at(pos.x).replace(pos.y, 1, " ");
        map.at(pos.x).at(pos.y) = ' ';
}

void Bombe::explosion(int size, sw::Vector2i pos)
{
    sw::Vector2i tmp_pos = pos;
    sw::Entity& player_entity = m_entity.m_scene.getEntity(m_name_player);
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");

    int tmp = 0;
    int cmp = 0;
    std::vector<std::string>& map = dynamic_cast<MapGenerator&>(scriptFact["Map"]).get_map();
    std::vector<sw::Vector3i> player_pos = dynamic_cast<MapGenerator&>(scriptFact["Map"]).get_player_pos();
    std::vector<std::string> player_name = dynamic_cast<MapGenerator&>(scriptFact["Map"]).get_player_name();

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map.at(i).length(); j++) {
            std::cout << map.at(i).at(j);
        }
    }

    for (auto& i : player_name) {
        std::cout << player_name[cmp] << std::endl;
        cmp++;
    }

    cmp=0;
    
    for (auto& i : player_pos) {
        if (tmp_pos.x == i.x*-1 && tmp_pos.y == i.z) {
            if (i.y == 0)
                dynamic_cast<Player&>(scriptFact[player_name[cmp]]).takeDamage();
            if (i.y == 1)
                dynamic_cast<Mob&>(scriptFact[player_name[cmp]]).takeDamage();
        }
        cmp++;
    }
    while(map.at(tmp_pos.x).at(tmp_pos.y) != 'b' && tmp != size) {
        map.at(tmp_pos.x).replace(tmp_pos.y, 1, " ");
        tmp_pos.y++;
        if (map.at(tmp_pos.x).at(tmp_pos.y) == '*')
            break;
        else {
            std::cout << "Fire-n-" + std::to_string(tmp_pos.y) << std::endl;
            m_entity.m_scene.createEntity("Fire-n-" + std::to_string(tmp_pos.y) + m_entity.m_name);
            scriptFact.addScript<Fire>("Fire-n-" + std::to_string(tmp_pos.y) + m_entity.m_name, tmp_pos);
            if (map.at(tmp_pos.x).at(tmp_pos.y) == 'b') {
                std::cout << map.at(tmp_pos.x).at(tmp_pos.y) << std::endl;
                destroyBlock(tmp_pos, map);
                break;
            }
        }
        cmp = 0;
        for (auto& i : player_pos) {
            if (tmp_pos.x == i.x*-1 && tmp_pos.y == i.z) {
                if (i.y == 0)
                    dynamic_cast<Player&>(scriptFact[player_name[cmp]]).takeDamage();
                if (i.y == 1)
                    dynamic_cast<Mob&>(scriptFact[player_name[cmp]]).takeDamage();
            }
            cmp++;
        }
        tmp++;
    }
    tmp_pos = pos;
    tmp = 0;
    while(map.at(tmp_pos.x).at(tmp_pos.y) != 'b' && tmp != size) {
        map.at(tmp_pos.x).replace(tmp_pos.y, 1, " ");
        tmp_pos.y --;
        if (map.at(tmp_pos.x).at(tmp_pos.y) == '*')
            break;
        else {
            std::cout << "Fire-s-" + std::to_string(tmp_pos.y) << std::endl;

            m_entity.m_scene.createEntity("Fire-s-" + std::to_string(tmp_pos.y) + m_entity.m_name);
            scriptFact.addScript<Fire>("Fire-s-" + std::to_string(tmp_pos.y) + m_entity.m_name, tmp_pos);
            if (map.at(tmp_pos.x).at(tmp_pos.y) == 'b') {
                std::cout << map.at(tmp_pos.x).at(tmp_pos.y) << std::endl;
                destroyBlock(tmp_pos, map);
                break;
            }
        }
        cmp = 0;
        for (auto& i : player_pos) {
            if (tmp_pos.x == i.x*-1 && tmp_pos.y == i.z) {
                if (i.y == 0)
                    dynamic_cast<Player&>(scriptFact[player_name[cmp]]).takeDamage();
                if (i.y == 1)
                    dynamic_cast<Mob&>(scriptFact[player_name[cmp]]).takeDamage();
            }
            cmp++;
        }
        tmp++;
    }
    tmp_pos = pos;
    tmp = 0;
    while(map.at(tmp_pos.x).at(tmp_pos.y) != 'b' && tmp != size) {
        map.at(tmp_pos.x).replace(tmp_pos.y, 1, " ");
        tmp_pos.x ++;
        if (map.at(tmp_pos.x).at(tmp_pos.y) == '*')
            break;
        else {
            std::cout << "Fire-e-" + std::to_string(tmp_pos.y) << std::endl;

            m_entity.m_scene.createEntity("Fire-e-" + std::to_string(tmp_pos.x) + m_entity.m_name);
            scriptFact.addScript<Fire>("Fire-e-" + std::to_string(tmp_pos.x) + m_entity.m_name, tmp_pos);
            if (map.at(tmp_pos.x).at(tmp_pos.y) == 'b') {
                std::cout << map.at(tmp_pos.x).at(tmp_pos.y) << std::endl;
                destroyBlock(tmp_pos, map);
                break;
            }
        }
        cmp = 0;
        for (auto& i : player_pos) {
            if (tmp_pos.x == i.x*-1 && tmp_pos.y == i.z) {
                if (i.y == 0)
                    dynamic_cast<Player&>(scriptFact[player_name[cmp]]).takeDamage();
                if (i.y == 1)
                    dynamic_cast<Mob&>(scriptFact[player_name[cmp]]).takeDamage();
            }
            cmp++;
        }
        tmp++;
    }
    tmp_pos = pos;
    tmp = 0;
    while(map.at(tmp_pos.x).at(tmp_pos.y) != 'b' && tmp != size) {
        map.at(tmp_pos.x).replace(tmp_pos.y, 1, " ");
        tmp_pos.x --;
        if (map.at(tmp_pos.x).at(tmp_pos.y) == '*')
            break;
        else {
            std::cout << "Fire-w-" + std::to_string(tmp_pos.y) << std::endl;

            m_entity.m_scene.createEntity("Fire-w-" + std::to_string(tmp_pos.x) + m_entity.m_name);
            scriptFact.addScript<Fire>("Fire-w-" + std::to_string(tmp_pos.x) + m_entity.m_name, tmp_pos);
            if (map.at(tmp_pos.x).at(tmp_pos.y) == 'b') {
                std::cout << map.at(tmp_pos.x).at(tmp_pos.y) << std::endl;
                destroyBlock(tmp_pos, map);
                break;
            }
        }
        cmp = 0;
        for (auto& i : player_pos) {
            if (tmp_pos.x == i.x*-1 && tmp_pos.y == i.z) {
                if (i.y == 0)
                    dynamic_cast<Player&>(scriptFact[player_name[cmp]]).takeDamage();
                if (i.y == 1)
                    dynamic_cast<Mob&>(scriptFact[player_name[cmp]]).takeDamage();
            }
            cmp++;
        }
        tmp++;
    }
    tmp_pos = pos;
    player_entity.getComponent<Player>("ScriptFact").addBomb(1);
    destroy();
    m_entity.getComponent<ray::Audio>("AudioFact").play("Explosion" + std::to_string((std::rand() % 3) + 1));
}

void Bombe::update()
{
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
    sw::Entity& player_entity = m_entity.m_scene.getEntity(m_name_player);
    int range = dynamic_cast<Player&>(scriptFact[player_entity.m_name]).getRange();

    if (!m_chrono.isRunning())
        m_chrono = sw::Chrono(sw::Chrono::Lauch);
    if (m_chrono.getTotalTime() >= 3 && m_state == EXPLODING) {
        explosion(range, m_pos);
        m_state = EXPLODED;
    }
    if (m_chrono.getElapsedTime() >= 1.0f) {
        m_entity.getComponent<ray::Audio>("AudioFact").play("Time" + std::to_string((std::rand() % 3) + 1));
        m_chrono.tour();
    }
    if (m_state != EXPLODED)
        m_entity.getComponent<ray::Transform>("TransformFact").scale(1.005f, 1.005f, 1.005f);
}

void Bombe::destroy()
{
    auto& transFact = m_entity.m_scene.getFactory<ray::TransformFact>("TransformFact");
    auto& meshFact = m_entity.m_scene.getFactory<ray::MeshFact>("MeshFact");
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");

    m_chrono.stop();
    transFact.deleteComponent(m_entity.m_name);
    meshFact.deleteComponent(m_entity.m_name);
    scriptFact.deleteComponent(m_entity.m_name);
}