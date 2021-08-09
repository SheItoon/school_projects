/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** apph_handlers.c
*/

#include "gcontext.h"

int app_trigger_event(mdevent_t evt)
{
    gcontext_t *ctx = get_app_context();
    action_t *action = NULL;
    list_t *actions = NULL;
    iterator_t it;

    actions = app_get_chandlers(evt.type);
    if (actions == NULL)
        return (-1);
    it = list_begin(actions);
    it = list_begin(actions);
    for (; !list_final(actions, it); it = it_next(it)) {
        action = list_data(it);
        if (action != 0) {
            action->ctrigger = evt;
            list_push_back(ctx->app_equeue, action);
        }
    }
    return (0);
}
