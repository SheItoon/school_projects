/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** gcontext_2.c
*/
#include "private/p_gcontext.h"
#include "csfml_toolbox.h"

action_t *app_poll_event(void)
{
    sfEvent evt;
    list_t *cmds = NULL;
    action_t *command = 0;
    gcontext_t *ctx = get_app_context();
    iterator_t it;

    while (sfRenderWindow_pollEvent(ctx->window, &evt) != 0) {
        cmds = app_wrap_sfevent(evt);
        if (cmds == NULL)
            continue;
        it = list_begin(cmds);
        for (; !list_final(cmds, it); it = it_next(it))
            list_push_back(ctx->app_equeue, list_data(it));
    }
    return (list_pull(ctx->app_equeue, list_begin(ctx->app_equeue)));
}

list_t *app_wrap_sfevent(sfEvent evt)
{
    action_t *action = NULL;
    list_t *actions = app_get_handlers(evt.type);
    iterator_t it;

    if (actions == NULL)
        return (0);
    it = list_begin(actions);
    for (; !list_final(actions, it); it = it_next(it)) {
        action = list_data(it);
        if (action != NULL)
            action->strigger = evt;
    }
    return (actions);
}

int app_merge_events(list_t *queue)
{
    gcontext_t *ctx = get_app_context();

    list_merge(queue, ctx->app_equeue);
    list_free(&ctx->app_equeue);
    ctx->app_equeue = list_create(MB_ACTION);
    return (0);
}

void app_handle_events(void)
{
    sfEvent evt;
    action_t *command = 0;
    gcontext_t *ctx = get_app_context();

    command = app_poll_event();
    while (command != 0) {
        if (command->custom == TRUE)
            command->function(&command->ctrigger, ctx);
        else
            command->function(&command->strigger, ctx);
        command = app_poll_event();
    }
}
