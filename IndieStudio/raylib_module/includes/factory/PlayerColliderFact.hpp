/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ColliderFact.hpp
*/

#ifndef __RAY_PLAYER_COLLIDER_FACT_HPP__
#define __RAY_PLAYER_COLLIDER_FACT_HPP__

#include "SW/Factory.hpp"

namespace ray
{
    class Collider;

    class PlayerColliderFact :
        public sw::AFactory<Collider>
    {

        public:
            using sw::AFactory<Collider>::AFactory;
            ~PlayerColliderFact() = default;

            void onLoad() override {};
            void onUpdate() override;
            void onUnload() override {};

    }; // class ColliderFact

} // namespace ray

#endif // __RAY_PLAYER_COLLIDER_FACT_HPP__