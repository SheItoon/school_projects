/*
** EPITECH PROJECT, 2021
** BillBoard.h
** File description:
** BillBoard.h
*/

#ifndef BILLBORD_H
#define BILLBORD_H

#include "SW/Components.hpp"
#include "resources/Texture.hpp"

namespace ray
{
    class BillBoard : public sw::Component
    {
    private:
        ray::RTexture m_texture;
    public:
        BillBoard() = delete;
        ~BillBoard() = default;
        explicit BillBoard(sw::Entity &entityRef);

        BillBoard& setTexture(std::string name);

        [[nodiscard]] ray::RTexture& getTexture();
    };

}

#endif //BILLBORD_H
