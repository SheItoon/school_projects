/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef CREATURE_PRIVATE_H_INCLUDED
#define CREATURE_PRIVATE_H_INCLUDED

#include "creature.h"

void notify_subs(list_t *subs);
void creature_update_dir(creature_t *cr, sfVector2f dir);
void creature_update_state(creature_t *cr, sfTime delta);
void creature_update_anim(creature_t *cr);
bool_t cpoint_reached(creature_t *cr);
void check_win(creature_t *cr);
void creature_update_pos(creature_t *cr, sfTime delta);

#endif
