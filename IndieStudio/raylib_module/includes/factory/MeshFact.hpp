/*
** EPITECH PROJECT, 2021
** MeshFactory.hpp
** File description:
** MeshFactory.hpp
*/

#ifndef MESHFACTORY
#define MESHFACTORY

#include "SW/Factory.hpp"

namespace ray
{
    class Mesh;

    class MeshFact :
        public sw::AFactory<Mesh>
    {
    public:
        using sw::AFactory<Mesh>::AFactory;

        void onLoad() override {};
        void onUpdate() override;
        void onUnload() override {};
    }; // class MashFact

} // namespace ray

#endif //MESHFACTORY
