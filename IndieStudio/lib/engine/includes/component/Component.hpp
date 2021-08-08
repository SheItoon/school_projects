/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Component.hpp
*/

#ifndef __SHIPWRECK_COMPONENT_HPP__
#define __SHIPWRECK_COMPONENT_HPP__

#include <string>
#include <iostream>

#include "entity/Entity.hpp"
#include "../lib/json_parser/jsnp.hpp"

namespace sw
{

    class Component
    {

        private:
            bool m_isActive;

        public:
            Entity& m_entity;

            //Component() = delete;
            //Component(Component&&) = delete;
            //Component(const Component&) = delete;
            Component(Entity& entityRef);
            ~Component() = default;

            void setActive(bool value);
            bool isActive() const;

    }; // class Component

    std::ostream& operator<<(std::ostream& os, const Component& obj);

    #include "Component.inl"

} // namespace sw

#endif // __SHIPWRECK_COMPONENT_HPP__