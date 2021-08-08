/*
** EPITECH PROJECT, 2021
** Player.hpp
** File description:
** Player.hpp
*/

#ifndef PLAYER
#define PLAYER

#include "SW/Components.hpp"
#include "utils/vector2.hpp"
#include "utils/vector3.hpp"

class Player : public sw::Script
{
    int m_live;
    float m_speed;
    std::string m_skin;
    int m_bomb;
    int m_max;
    int m_range;
    bool m_wallPass;
    bool m_quadDir;

    float getAngle(float x, float y);
    sw::Vector3f getAxis(float x, float y);

protected:
    void CreateIcon();

    int m_player;
    sw::Vector2f m_origin;
public:
    explicit Player(sw::Entity& entity);
    ~Player() override = default;
    void start() override;
    void update() override;

    Player& takeDamage();
    void SpawnBomb();

    Player& setPlayer(int player);
    Player& setSkin(std::string player);
    Player& setOrigin(const sw::Vector2f& vec);
    Player& addBomb(int bomb);
    Player& setMaxBomb(int max);
    Player& setLive(int live);
    Player& setSpeed(float speed);
    Player& setWallPass(bool pass);
    Player& setRange(int range);

    [[nodiscard]] int getBomb() const;
    [[nodiscard]] int getMax() const;
    [[nodiscard]] int getLive() const;
    [[nodiscard]] std::string getString() const;
    [[nodiscard]] float getSpeed() const;
    [[nodiscard]] bool getWallPass() const;
    [[nodiscard]] int getRange() const;
    [[nodiscard]] std::string getSkin() const { return (m_skin); }
}; // class Player

#endif //PLAYER
