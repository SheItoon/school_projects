/*
** EPITECH PROJECT, 2021
** Cube.hpp
** File description:
** Cube.hpp
*/

#ifndef CUBE_HPP
#define CUBE_HPP

#include "component/Script.hpp"

class Cube : public sw::Script
{
public:
    typedef enum {
        BREAKABLE,
        UNBREAKABLE
    } Type;
private:
    enum {
        INLIFE,
        DESTROYED
    } m_state;
    Type m_type;
    void generateBonus();
public:
    explicit Cube(sw::Entity& entity, Type type);
    ~Cube() override;

    void start() override;
    void update() override;

    Cube& destroy();
    [[nodiscard]] Type getType() const;
};

#endif //CUBE_HPP
