/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** BoxCollider.hpp
*/

#ifndef __RAY_BOXCOLLIDER_HPP__
#define __RAY_BOXCOLLIDER_HPP__

#include "raylib.h"
#include "SW/Components.hpp"
#include "../lib/json_parser/jsnp.hpp"
#include <iostream>
#include <memory>

namespace ray
{

    class Collider :
        public sw::Component
    {
        public:
            enum Type
            {
                UNDEFINED,
                CUBE,
                SPHERE,
                RAY
            };

        protected:
            Type m_type;
            bool m_needUpdate;

        public:
            Collider(sw::Entity& entity);
            ~Collider() = default;

            Type type() { return (m_type); }
            virtual bool collide(Collider& collider) { (void)collider; return (false); }
            virtual void draw(Color color) {}


    }; // class Collider

    class CubeCollider :
        public Collider
    {

        protected:
            Vector3 m_origin;
            Vector3 m_size;
            BoundingBox m_cube;
            std::shared_ptr<::Mesh*> m_meshRef;

        public:
            CubeCollider(sw::Entity& entity);
            CubeCollider(sw::Entity& entity, const Vector3& size);
            CubeCollider(sw::Entity& entity, const Vector3& origin, const Vector3& size);
            ~CubeCollider() = default;

            bool collide(Collider& collider) override;
            void draw(Color color) override;

            BoundingBox cube();

            void setMeshReference(::Mesh* mesh);
            void setOrigin(const Vector3& origin);
            void setSize(const Vector3& size);

            friend Collider;

    }; // class CubeCollider

    class SphereCollider :
        public Collider
    {

        protected:
            Vector3 m_origin;
            Vector3 m_realOrigin;
            float m_radius;
            float m_realRadius;

        public:
            SphereCollider(sw::Entity& entity);
            SphereCollider(sw::Entity& entity, float radius);
            SphereCollider(sw::Entity& entity, const Vector3& origin, float radius);
            ~SphereCollider() = default;

            bool collide(Collider& collider) override;
            void draw(Color color) override;

            Vector3 origin();
            float radius();

            void setOrigin(const Vector3& origin);
            void setRadius(float radius);

            friend Collider;

    }; // class BoxCollider

    class RayCollider :
        public Collider
    {

        protected:
            Vector3 m_origin;
            Vector3 m_direction;
            Ray m_ray;

        public:

            using CollisionInfo = ::RayCollision;

            RayCollider(sw::Entity& entity);
            RayCollider(sw::Entity& entity, const Vector3& direction);
            RayCollider(sw::Entity& entity, const Vector3& origin, const Vector3& direction);
            ~RayCollider() = default;

            bool collide(Collider& collider) override;
            CollisionInfo collideWInfo(Collider& collider);
            void draw(Color color) override;

            Ray ray();

            void setOrigin(const Vector3& origin);
            void setDirection(const Vector3& direction);

            friend Collider;

    }; // class RayCollider

} // namespace ray

#endif // __RAY_BOXCOLLIDER_HPP__