/*
** EPITECH PROJECT, 2021
** TransformFacp.hpp
** File description:
** TransformFacp.hpp
*/

#ifndef __RAY_MOVEMENT_FACT_HPP__
#define __RAY_MOVEMENT_FACT_HPP__

#include "SW/Components.hpp"

namespace ray
{
    class Movement;

    class MovementFact :
            public sw::AFactory<Movement>
    {

    public:
        using sw::AFactory<Movement>::AFactory;
        ~MovementFact() = default;

        void onLoad() override {};
        void onUpdate() override;
        void onUnload() override {};

    }; // class MovementFact

} // namespace ray

#endif //__RAY_MOVEMENT_FACT_HPP__
