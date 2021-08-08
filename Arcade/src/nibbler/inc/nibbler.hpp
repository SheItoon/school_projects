/*
** EPITECH PROJECT, 2021
** pacMan.hpp.h
** File description:
** pacMan.hpp.h
*/

#ifndef NIBBLER
#define NIBBLER

#include <memory>
#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IGame.hpp"
#include <vector>

class Nibbler : public arc::IGame {
public:
    Nibbler();
    ~Nibbler() override;
    void start(arc::IDisplayModule*) override;
    void update(arc::IDisplayModule*) override;
    void terminate(arc::IDisplayModule*) override;
    void drawing(arc::IDisplayModule *module);
    void checkDirection(arc::IDisplayModule *module);
    int chooseDirection(arc::IDisplayModule *module);
    void makeDirection();
    void checkAround();
    void gameOver(arc::IDisplayModule *module);
    void spawnFruit();
private:
    enum direction_e { None = -1, Up, Down, Left, Right };
    direction_e direction;
    direction_e wantedDirection;

    float x;
    float y;
    std::array<std::string, 22> m_map;
    //std::vector<std::pair<int, int>> snake;
    //std::pair<int, int> food;
    int score;
    bool over;
    bool spawned;
    float speed_mult;
};



extern "C" void *entryPoint();

#endif //NIBBLER
