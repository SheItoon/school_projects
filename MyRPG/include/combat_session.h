/*
** EPITECH PROJECT, 2020
** inc
** File description:
** inc
*/

#pragma once

#include <SFML/Graphics.h>
#include "gcontext.h"
#include "combat_struct.h"

#define SET_POS e->player.vertices[i].position = (sfVector2f) \
{(p.x + off_p) * curr_p, p.y};\
e->mob.vertices[i].position = (sfVector2f)\
{(m.x + off_m) * actual_m, m.y};
#define SET_MENU entities->menu = sfRectangleShape_create();\
sfRectangleShape_setFillColor(entities->menu, sfWhite);\
sfRectangleShape_setPosition(entities->menu,\
(sfVector2f) {0, pos.y * .66});\
sfRectangleShape_setTexture(entities->menu,\
sfTexture_createFromFile(menu, NULL), sfFalse);\
sfRectangleShape_setSize(entities->menu,\
(sfVector2f) {pos.x , pos.y * .35});
#define SET_BACKGROUND entities->background = sfRectangleShape_create();\
sfRectangleShape_setFillColor(entities->background, sfWhite);\
sfRectangleShape_setPosition(entities->background,\
(sfVector2f) {0, 0});\
sfRectangleShape_setSize(entities->background,\
(sfVector2f) {pos.x , pos.y});
#define DRAW_START sfRenderWindow_drawRectangleShape(window,\
entities->background, &entities->state);\
sfRenderWindow_drawSprite(window, entities->player.sprite[3], NULL);\
sfRenderWindow_drawSprite(window, entities->mob.sprite[index], NULL);

void combat_session(void);
void init_button(button_t *button, sfRenderWindow *window, 
combat_t *entities);
void init_mob(mob_t *mob, sfRenderWindow *window);
void init_player(player_t *player, sfRenderWindow *window);
void init_sound(oof_t *oof, combat_t *entities);
int fight(combat_t *entities, int index, int action, sfRenderWindow *window);
void reset_hp_dmg(combat_t *entities);
void gain_exp(player_t *player, int index);
void init_bar(combat_t *entities, sfRenderWindow *window);
void draw_hp(combat_t *e,int index, sfRenderWindow *window);