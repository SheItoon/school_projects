/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Entity.hpp
*/

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>
#include <array>
#include <iostream>

#include "dependencies.hpp"
#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/Chrono.hpp"
#include "../../../inc/Vector.hpp"

class Entity
{
    public:
        enum direction_e { None = -1, Up, Down, Left, Right };
        direction_e direction;
        direction_e wantedDirection;
        arc::Vector<float> pos;

        Entity(float xVal, float yVal);
        ~Entity() = default;
};

class Player :
    public Entity
{
    public:
        arc::Chrono powerUpChrono;
        bool powerUp;
        bool grailled;
        int score;
        int grailleCombo;

        Player();
        ~Player() = default;

        void draw(arc::IDisplayModule *module);
        void checkDirection(arc::IDisplayModule *module);
        void chooseDirection(const std::array<std::string, heightMap>& map);
        void makeDirection(const std::array<std::string, heightMap>& map);
        void checkAround(std::array<std::string, heightMap>& map, int& pacGumNb);
};

class Ghost :
    public Entity
{
    public:
        enum mode_e { PowerLess, Grailled, Hunting, Random };

    private:
        arc::Vector<float> determineTarget(bool houseKeeping, mode_e mode, const arc::Vector<float> playerPos);
        std::array<bool, 4> checkPossibleDirection(const std::array<std::string, heightMap>& map);
        void settleDirection(std::array<bool, 4> possibleDirection, const arc::Vector<float> target);
        void settleRandomDirection(std::array<bool, 4> possibleDirection);

    public:
        arc::Chrono dirChoiceChrono;
        arc::Color color;
        mode_e mode;
        bool needMoveChoice;
        bool houseKeeping;

        Ghost(arc::Vector<float> pos, arc::Color colorVal);
        ~Ghost() = default;

        void draw(arc::IDisplayModule *module);
        void chooseDirection(const std::array<std::string, heightMap>& map, const arc::Vector<float> playerPos);
        void makeDirection(const std::array<std::string, heightMap>& map);
        void checkAround();
};

inline std::ostream& operator<<(std::ostream& os, const Entity::direction_e& dir)
{
    switch (dir)
    {
        case Entity::direction_e::None:
            os << "None";
            break;
        case Entity::direction_e::Up:
            os << "Up";
            break;
        case Entity::direction_e::Down:
            os << "Down";
            break;
        case Entity::direction_e::Left:
            os << "Left";
            break;
        case Entity::direction_e::Right:
            os << "Right";
            break;
    }
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, const Ghost::mode_e& mode)
{
    switch (mode)
    {
        case Ghost::mode_e::PowerLess:
            os << "PowerLess";
            break;
        case Ghost::mode_e::Grailled:
            os << "Grailled";
            break;
        case Ghost::mode_e::Hunting:
            os << "Hunting";
            break;
        case Ghost::mode_e::Random:
            os << "Random";
            break;
    }
    return (os);
}

#endif // __ENTITY_H__