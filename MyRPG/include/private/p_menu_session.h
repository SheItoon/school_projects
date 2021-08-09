/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef MENU_SESSION_PRIVATE_INCLUDED
#define MENU_SESSION_PRIVATE_INCLUDED

#include "menu_session.h"

void m_handle_game_update(sfTime delta);
sfRectangleShape *start_rect(sfFloatRect rect);
sfRectangleShape *quit_rect(sfFloatRect rect);
sfText *gen_text(cchar_t name, sfVector2f pos);
void m_render_mode(sfRenderWindow *window, sfRenderStates *st);
void m_handle_window_events(sfRenderWindow *window, list_t *queue);
void m_session_update(gcontext_t *context);

#endif
