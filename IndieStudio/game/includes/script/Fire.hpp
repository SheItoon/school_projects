/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** Fire
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

#include "SW/Components.hpp"
#include "utils/vector2.hpp"
#include "utils/Chrono.hpp"

class Fire : public sw::Script
{
    private:
        sw::Vector2i m_pos;
        sw::Chrono m_chrono;

        void destroy();
    public:
        explicit Fire(sw::Entity& entity, sw::Vector2i pos_fire);
        ~Fire() override;
        void start() override;
        void update() override;
};

#endif /* !FIRE_HPP_ */
