/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** RayIAColliderFact.hpp
*/

#ifndef __RAY_AICOLLIDER_FACT_HPP__
#define __RAY_AICOLLIDER_FACT_HPP__

#include "SW/Factory.hpp"

namespace ray
{
    class Collider;

    class RayIAColliderFact :
        public sw::AFactory<Collider>
    {

        public:
            using sw::AFactory<Collider>::AFactory;
            ~RayIAColliderFact() = default;

            void onLoad() override {};
            void onUpdate() override;
            void onUnload() override {};

    }; // class RayIAColliderFact

} // namespace ray

#endif // __RAY_AICOLLIDER_FACT_HPP__