/*
** EPITECH PROJECT, 2021
** Mesh.hpp
** File description:
** Mesh.hpp
*/

#ifndef MESH
#define MESH

#include "SW/Components.hpp"
#include "resources/Model.hpp"
#include "resources/Texture.hpp"
#include "utils/Color.hpp"

namespace ray
{
    class Mesh :
            public sw::Component
    {
    private:
        Model m_model;
        Texture m_texture;
        RColor m_color;
        ModelAnimation *m_anim;
        int m_animCount;

    public:
        explicit Mesh(sw::Entity &entityRef);
        ~Mesh() = default;

        Mesh& setModel(std::string modelName);
        Mesh& setColor(Color color);
        Mesh& setColor(int r, int g, int b, int a);
        Mesh& setTexture(std::string textureName);
        Mesh& setAnimation(std::string path);
        Mesh& setAnimCount(int count);
        Mesh& increaseAnimCount();

        [[nodiscard]] Model getModel() const;
        [[nodiscard]] RColor getColor() const;
        [[nodiscard]] Texture getTexture() const;
        [[nodiscard]] ModelAnimation *getAnimator() const;
        [[nodiscard]] int getAnimCount() const;

        [[nodiscard]] bool hasAnimation() const;
    }; // class Mesh

}

#endif //MESH
