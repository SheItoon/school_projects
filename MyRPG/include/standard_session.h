/*
** EPITECH PROJECT, 2020
** navy
** File description:
** standart_session.h
*/
#ifndef STANDART_SESSION_H_INCLUDED
#define STANDART_SESSION_H_INCLUDED

#include <SFML/Graphics.h>
#include "my.h"
#include "istl/utility.h"
#include "istl/common_types.h"
#include "gcontext.h"

void standart_session(void);
sfRenderStates get_mod_rstates(void);

int modh_creature_hover(void *, gcontext_t *);
int modh_mouse_moved(void *, gcontext_t *);
int modh_mouse_button(void *, gcontext_t *);
int modh_btn_clicked(void *, gcontext_t *);
int modh_key_pressed(void *, gcontext_t *);

#endif
