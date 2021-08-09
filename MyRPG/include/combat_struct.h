/*
** EPITECH PROJECT, 2020
** combat
** File description:
** combat_struct
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct button_s
{
    sfSprite *sprite[3];
    sfTexture *texture[3];
    sfVector2f rect[3];
} button_t;

typedef struct mob_s
{
    sfSprite *sprite[4];
    sfTexture *texture[4];
    sfVector2f rect[4];
    int hp[2];
    int dmg[2];
    sfSound *oof;
    sfSoundBuffer *damage;
    sfVertex vertices[4];
} mob_t;

typedef struct player_s
{
    sfSprite *sprite[4];
    sfTexture *texture[4];
    sfVector2f rect[4];
    int life;
    int act;
    int damage;
    int level;
    int xp_need;
    int xp_curr;
    sfSound *oof;
    sfVertex vertices[4];
} player_t;

typedef struct oof_s
{
    sfSound *damage;
    sfSoundBuffer *damage_buffer;
} oof_t;

typedef struct combat_s
{
    button_t button;
    sfRectangleShape *background;
    mob_t mob;
    player_t player;
    sfRectangleShape *menu;
    oof_t oof;
    sfRenderStates state;
} combat_t;