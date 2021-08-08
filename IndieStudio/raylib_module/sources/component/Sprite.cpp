/*
** EPITECH PROJECT, 2021
** Sprite.cpp
** File description:
** Sprite.cpp
*/

#include "component/Transform.hpp"
#include "component/Sprite.hpp"

ray::Sprite::Sprite(sw::Entity &entityRef) :
sw::Component(entityRef),
m_texture(dynamic_cast<RTexture &>(m_entity.m_scene.getTexture("MissingTexture"))),
m_color(),
m_image(GenImageColor(10, 10, WHITE)),
m_rectangle({0, 0, (float)GetTextureData(*m_texture).width, (float)GetTextureData(*m_texture).width})
{
    m_color.setColor(WHITE);
}

const ray::RTexture & ray::Sprite::texture() const
{
    return (m_texture);
}

ray::Sprite& ray::Sprite::setTexture(std::string name)
{
    m_texture = dynamic_cast<RTexture &>(sw::Engine::activeScene().getTexture(name));
    return (*this);
}

ray::Sprite& ray::Sprite::setTextureRect(Rectangle rect)
{
    m_rectangle = rect;
    return (*this);
}

ray::Sprite& ray::Sprite::setColor(const Color &color)
{
    m_color.setColor(color);
    return (*this);
}

ray::Sprite& ray::Sprite::setColor(const int r, const int g, const int b, const int a = 255)
{
    m_color.setColor(r, g, b, a);
    return (*this);
}

void ray::Sprite::invertX(bool invert)
{
    m_invertedX = invert;
}

void ray::Sprite::invertY(bool invert)
{
    m_invertedY = invert;
}

bool ray::Sprite::isInvertX() const
{
    return (m_invertedX);
}

bool ray::Sprite::isInvertY() const
{
    return (m_invertedY);
}

ray::RColor ray::Sprite::color() const
{
    return (m_color);
}

Rectangle ray::Sprite::getRect() const
{
    return (m_rectangle);
}

ray::Sprite ray::Sprite::update()
{
    m_rectangle = {0, 0, (float)GetTextureData(*m_texture).width, (float)GetTextureData(*m_texture).width};
    return (*this);
}

void ray::Sprite::loadSpriteImage()
{
    m_image = GetTextureData(*m_texture);
}

bool ray::Sprite::PointOnImage(const sw::Vector2f& point)
{
    auto& tfm = m_entity.getComponent<ray::Transform>("TransformFact");
    sw::Vector2f posPointInImage = point - sw::Vector2f{tfm.getPosition().x, tfm.getPosition().y};

    if (posPointInImage.x > m_image.width
    || posPointInImage.x < 0
    || posPointInImage.y > m_image.height
    || posPointInImage.y < 0)
        return (false);

    int pos = posPointInImage.x + (m_image.width * posPointInImage.y);

    if (static_cast<Color*>(m_image.data)[pos].a == 0)
        return (false);
    return (true);
}