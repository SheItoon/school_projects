/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef GCONTEXT_PRIVATE_H_INCLUDED
#define GCONTEXT_PRIVATE_H_INCLUDED

#include "gcontext.h"

void init_app_handlers(void);
list_t *app_wrap_sfevent(sfEvent evt);
int app_merge_events(list_t *queue);

#endif
