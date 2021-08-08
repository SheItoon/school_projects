/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Vector.hpp
*/

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "SW/Components.hpp"
#include "utils/vector3.hpp"

namespace ray
{

    class Movement :
        public sw::Component
    {

        public:
            Movement(sw::Entity& entity);
            Movement(sw::Entity& entity, float xVal, float yVal, float zVal);
            ~Movement() = default;

            float x;
            float y;
            float z;
            Movement& setVector(sw::Vector3f vector);
    }; // class Movement

} // namespace ray

#endif // __VECTOR_H__