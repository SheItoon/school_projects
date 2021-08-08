/*
** EPITECH PROJECT, 2021
** mob
** File description:
** mob
*/

#pragma once

#include "SW/Components.hpp"
#include <string>
#include <vector>
#include <mutex>
#include <random>
#include "component/Collider.hpp"
#include "script/Player.hpp"
using directions = std::vector<std::pair<int, int>>;

class Mob : public Player {
public:
    //using sw::Script::Script;
    explicit Mob(sw::Entity& entity);
    explicit Mob(sw::Entity& entity, std::string& name);
    explicit Mob(sw::Entity& entity, std::string& name, int life);
    ~Mob() override = default;
    void start() override;
    void update() override;

    /*
    //getter
    [[nodiscard]] std::string getName() const { return (m_name); };
    [[nodiscard]] int getLife() const { return (m_life); };

    //setter
    void setName(std::string &name) { m_name = name; };
    void setLife(int life) { m_life = life; };
*/
    //public methods
    void walking();
    //void fleeing();
    void chasing();
    void bombing();
    void scout();

    enum m_states {
        WALK,
        RUN,
        CHASE,
        BOMB
    } m_state;
    enum m_card {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };
    std::vector<m_card> m_blacklist;

private:
    typedef void (Mob::*stateFunction)();
    std::string m_name;
    int m_life;
    float m_speed;
    float m_distance;
    stateFunction function[m_states::BOMB + 1] = { &Mob::walking, &Mob::walking, &Mob::chasing, &Mob::bombing };
    m_card m_dir;
    directions m_directions;
    std::random_device m_random;
    std::mt19937 m_gen = std::mt19937(m_random());
    std::uniform_int_distribution<> m_uniform_int_dist = std::uniform_int_distribution(1, 100);
    std::uniform_real_distribution<> m_uniform_real_dist = std::uniform_real_distribution(0.0, 1.0);

//methods
    bool in_range(int n, std::pair<int, int> range, int way);
    bool in_ranges(int path, directions dir);
    bool isBlocked(int way);
    void move();
};
