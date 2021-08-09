/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** standart_session.c
*/

#include "p_standard_session.h"

void standart_session(void)
{
    gcontext_t *context = get_app_context();

    if (context->window == 0)
        return;
    app_handle_events();
    session_update(context);
    render_mode(context->window, &context->appstates);
}
