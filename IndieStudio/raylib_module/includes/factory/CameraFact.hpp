/*
** EPITECH PROJECT, 2021
** CameraFact.hpp
** File description:
** CameraFact.hpp
*/

#ifndef CAMERAFACT
#define CAMERAFACT

#include "SW/Factory.hpp"

namespace ray
{
    class RCamera;

    class CameraFact :
        public sw::AFactory<RCamera>
    {
    public:
        using sw::AFactory<RCamera>::AFactory;

        void onLoad() override {};
        void onUpdate() override;
        void onUnload() override {};
    }; // class CameraFact

} // namespace ray

#endif //CAMERAFACT
