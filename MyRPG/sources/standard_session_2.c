/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** standard_session_2.c
*/
#include "csfml_toolbox.h"
#include "p_standard_session.h"

action_t *get_mode_response(sfEvent evt)
{
    action_t *action = app_get_handler(evt.type);

    if (action == 0)
        return (0);
    action->strigger = evt;
    return (action);
}

sfRenderStates get_mod_rstates(void)
{
    sfRenderStates states = get_default_rstates();

    return (states);
}
