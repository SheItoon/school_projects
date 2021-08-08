/*
** EPITECH PROJECT, 2021
** BonusSpeed.hpp
** File description:
** BonusSpeed.hpp
*/

#ifndef BONUSSPEED_HPP
#define BONUSSPEED_HPP

#include "component/Script.hpp"

class BonusSpeed : public sw::Script
{
private:
    float m_animTime;

    void destroy();
public:
    explicit BonusSpeed(sw::Entity& entity);
    ~BonusSpeed() override;
    void start() override;
    void update() override;
    void onCollision(sw::Entity& entity) override;
    void takeIt(sw::Entity& entity);
};


#endif //BONUSSPEED_HPP
