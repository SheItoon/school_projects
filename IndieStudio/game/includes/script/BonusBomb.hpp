/*
** EPITECH PROJECT, 2021
** BonusBomb.hpp
** File description:
** BonusBomb.hpp
*/

#ifndef BONUSBOMB_HPP
#define BONUSBOMB_HPP

#include "component/Script.hpp"

class BonusBomb : public sw::Script
{
private:
    float m_animTime;

    void destroy();
public:
    explicit BonusBomb(sw::Entity& entity);
    ~BonusBomb() override;
    void start() override;
    void update() override;
    void onCollision(sw::Entity& entity) override;
    void takeIt(sw::Entity& entity);
};


#endif //BONUSBOMB_HPP
