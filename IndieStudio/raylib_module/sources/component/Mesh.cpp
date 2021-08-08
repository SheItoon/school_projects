/*
** EPITECH PROJECT, 2021
** Mesh.cpp
** File description:
** Mesh.cpp
*/

#include "component/Mesh.hpp"

ray::Mesh::Mesh(sw::Entity &entityRef) :
sw::Component(entityRef),
m_model(),
m_color(),
m_texture(*dynamic_cast<RTexture&>(sw::Engine::activeScene().getTexture("MissingTexture"))),
m_anim(nullptr),
m_animCount(0)
{
    m_color.setColor(WHITE);
}

ray::Mesh& ray::Mesh::setModel(std::string modelName)
{
    m_model = *dynamic_cast<RModel&>(sw::Engine::activeScene().getModel(std::move(modelName)));
    return (*this);
}

ray::Mesh & ray::Mesh::setColor(Color color)
{
    m_color.setColor(color);
    return (*this);
}

ray::Mesh& ray::Mesh::setColor(int r, int g, int b, int a)
{
    m_color.setColor(r, g, b, a);
    return (*this);
}

ray::Mesh & ray::Mesh::setTexture(std::string textureName)
{
    m_texture = *dynamic_cast<RTexture&>(m_entity.m_scene.getTexture(std::move(textureName)));
    m_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = m_texture;
    return (*this);
}

Model ray::Mesh::getModel() const
{
    return (m_model);
}

ray::RColor ray::Mesh::getColor() const
{
    return (m_color);
}

Texture ray::Mesh::getTexture() const
{
    return (m_texture);
}

ray::Mesh & ray::Mesh::setAnimation(std::string path)
{
    m_anim = LoadModelAnimations("resources/models/PersoAnim.iqm", &m_animCount);
    return (*this);
}

bool ray::Mesh::hasAnimation() const
{
    return (m_anim);
}

ModelAnimation* ray::Mesh::getAnimator() const
{
    return (m_anim);
}

ray::Mesh & ray::Mesh::setAnimCount(int count)
{
    m_animCount = count;
    return (*this);
}

ray::Mesh & ray::Mesh::increaseAnimCount()
{
    m_animCount += 1;
    return (*this);
}

int ray::Mesh::getAnimCount() const
{
    return (m_animCount);
}