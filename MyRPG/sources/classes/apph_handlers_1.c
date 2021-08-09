/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** apph_handlers.c
*/

#include "gcontext.h"

int apph_mouse_scroll(void *evt_p, gcontext_t *ctx)
{
    sfEvent evt;
    sfRenderWindow *window = 0;
    sfVector2f vs;
    float c = 0;

    if (evt_p == NULL || ctx == NULL)
        return (84);
    evt = *(sfEvent *)evt_p;
    window = ctx->window;
    vs = sfView_getSize(ctx->game_view);
    c = (evt.mouseWheel.delta > 0) ? -120 : 120;
    vs = (sfVector2f) {vs.x + c, vs.y + c * vs.y / vs.x};
    if (vs.x > 100 && vs.x < (1920 * 6))
        sfView_setSize(ctx->game_view, vs);
    return (0);
}

int apph_key_pressed(void *evt, gcontext_t *ctx)
{
    return (0);
}

int apph_close_window(void *evt, gcontext_t *ctx)
{
    sfRenderWindow *window = 0;

    sfRenderWindow_close(ctx->window);
    app_set_session(NULL);
    return (0);
}
