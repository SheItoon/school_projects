/*
** EPITECH PROJECT, 2021
** SkyBoxFact.hpp
** File description:
** SkyBoxFact.hpp
*/

#ifndef SKYBOXFACT_HPP
#define SKYBOXFACT_HPP

#include "SW/Factory.hpp"

namespace ray
{
    class Skybox;

    class SkyBoxFact :
        public sw::AFactory<Skybox>
    {
    public:
        using sw::AFactory<Skybox>::AFactory;

        void onLoad() override {};
        void onUpdate() override;
        void onUnload() override {};
    }; // class Skybox

} // namespace ray

#endif //SKYBOXFACT_HPP
