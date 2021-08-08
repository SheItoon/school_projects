/*
** EPITECH PROJECT, 2021
** Cube.cpp
** File description:
** Cube.cpp
*/

#include <sstream>

#include "script/Cube.hpp"
#include "component/components.hpp"
#include "indie.hpp"
#include "utils/Input.hpp"
#include "factory/factories.hpp"
#include "script/BonusBomb.hpp"
#include "script/BonusRange.hpp"
#include "script/BonusSpeed.hpp"

Cube::Cube(sw::Entity &entity, Type type) :
sw::Script(entity),
m_state(INLIFE),
m_type(type)
{}

Cube::~Cube() noexcept
{
    m_entity.m_scene.deleteEntity(m_entity.m_name);
}

void Cube::start()
{
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");
    std::string numbers = m_entity.m_name.substr(m_entity.m_name.find('-'));
    std::string i = numbers.substr(1, numbers.find('-', 1) - 1);
    std::string j = numbers.substr(numbers.find('-', 1) + 1);
    std::stringstream ss;
    int tmp = 0;
    int tmp1 = 0;

    ss << i;
    ss >> tmp;
    ss.clear();
    ss << j;
    ss >> tmp1;
    trans.setPosition(-tmp * 1, 0, tmp1 * 1);
    trans.setScale(6.2, 6.2, 6.2);
    auto& mesh = m_entity.createComponent<ray::Mesh>("MeshFact").setModel(m_type == Type::BREAKABLE ? "Cube" : "Block").setTexture(m_type == Type::BREAKABLE ? "Cube" : "Block");

    m_entity.insertComponent<ray::Collider, ray::CubeCollider>("ColliderFact", Vector3{0, 0, 0}, Vector3{1, 1, 1}).setMeshReference(mesh.getModel().meshes);
}

void Cube::update()
{
}

void Cube::generateBonus()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> appear(1, 100);
    if (m_state == DESTROYED || appear(gen) < 70)
        return;
    std::uniform_int_distribution<> bonus(1, 3);
    auto& newBonus = m_entity.m_scene.createEntity("BonusBomb" + m_entity.m_name);
    switch (bonus(gen)) {
        case 1:
            m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact").addScript<BonusBomb>("BonusBomb" + m_entity.m_name);
            break;
        case 2:
            m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact").addScript<BonusRange>("BonusBomb" + m_entity.m_name);
            break;
        case 3:
            m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact").addScript<BonusSpeed>("BonusBomb" + m_entity.m_name);
            break;
    }
    newBonus.getComponent<ray::Transform>("TransformFact").setPosition(m_entity.getComponent<ray::Transform>("TransformFact").getPosition());
}

Cube & Cube::destroy()
{
    auto& transFact = m_entity.m_scene.getFactory<ray::TransformFact>("TransformFact");
    auto& meshFact = m_entity.m_scene.getFactory<ray::MeshFact>("MeshFact");
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
    auto& colliderFact = m_entity.m_scene.getFactory<ray::ColliderFact>("ColliderFact");

    generateBonus();
    m_state = DESTROYED;
    transFact.deleteComponent(m_entity.m_name);
    meshFact.deleteComponent(m_entity.m_name);
    scriptFact.deleteComponent(m_entity.m_name);
    colliderFact.deleteComponent(m_entity.m_name);
    return (*this);
}

Cube::Type Cube::getType() const
{
    return (m_type);
}