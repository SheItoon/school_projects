/*
** EPITECH PROJECT, 2021
** Skybox.hpp
** File description:
** Skybox.hpp
*/

#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include "SW/Components.hpp"
#include "raylib.h"
#include "rlgl.h"

namespace ray
{
    class Skybox:
        public sw::Component
    {
    private:
        Mesh m_mesh;
        Model m_box;
        Shader m_cubeMap;
        Texture2D m_texture;

        TextureCubemap GenCubeMap(Shader shader, Texture2D panorama, int size, int format);

    public:
        explicit Skybox(sw::Entity& entityRef);
        ~Skybox() = default;
        [[nodiscard]] Model getModel() const;
    };
} // namespace ray

#endif //SKYBOX_HPP
