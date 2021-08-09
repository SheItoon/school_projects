/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef STANDART_SESSION_PRIVATE_H_INCLUDED
#define STANDART_SESSION_PRIVATE_H_INCLUDED

#include "standard_session.h"

void gen_creature(scene_t *scene, sfTime delta);
void handle_game_update(sfTime delta);
void render_mode(sfRenderWindow *window, sfRenderStates *st);
void handle_app_events(gcontext_t *);
void session_update(gcontext_t *context);
action_t *get_mode_response(sfEvent evt);

#endif
