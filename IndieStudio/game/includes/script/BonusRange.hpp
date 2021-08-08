/*
** EPITECH PROJECT, 2021
** BonusRange.hpp
** File description:
** BonusRange.hpp
*/

#ifndef BONUSRANGE_HPP
#define BONUSRANGE_HPP

#include "component/Script.hpp"

class BonusRange : public sw::Script
{
private:
    float m_animTime;

    void destroy();
public:
    explicit BonusRange(sw::Entity& entity);
    ~BonusRange() override;
    void start() override;
    void update() override;
    void onCollision(sw::Entity& entity) override;
    void takeIt(sw::Entity& entity);
};


#endif //BONUSRANGE_HPP
