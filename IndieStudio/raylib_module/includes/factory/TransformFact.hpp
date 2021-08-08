/*
** EPITECH PROJECT, 2021
** TransformFacp.hpp
** File description:
** TransformFacp.hpp
*/

#ifndef TRANSFORMFACP_HPP
#define TRANSFORMFACP_HPP

#include "SW/Components.hpp"

namespace ray
{
    class Transform;

    class TransformFact :
            public sw::AFactory<Transform>
    {

    public:
        using sw::AFactory<Transform>::AFactory;
        ~TransformFact() = default;

        void onLoad() override {};
        void onUpdate() override {};
        void onUnload() override {};

    }; // class TransformFact

} // namespace ray

#endif //TRANSFORMFACP_HPP
