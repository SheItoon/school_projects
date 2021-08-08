/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** Bombe
*/

#ifndef BOMBE_HPP_
#define BOMBE_HPP_

#include "SW/Components.hpp"
#include "utils/vector2.hpp"
#include "utils/Chrono.hpp"

class Bombe : public sw::Script
{
    private:
        enum {
            EXPLODING,
            EXPLODED
        } m_state;
        std::string m_name_player;
        sw::Chrono m_chrono;
        sw::Vector2i m_pos;

        void destroy();
        public:
        explicit Bombe(sw::Entity& entity, std::string name_player);
        ~Bombe() override;
        void destroyBlock(sw::Vector2i pos, std::vector<std::string>& map);
        void explosion(int size, sw::Vector2i pos);
        void start() override;
        void update() override;
};

#endif /* !BOMBE_HPP_ */
