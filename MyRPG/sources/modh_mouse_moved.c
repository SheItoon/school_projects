/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** modh_mouse_moved.c
*/
#include "gcontext.h"
#include "standard_session.h"

static void mv_view(gcontext_t *ctx, sfEvent evt, sfVector2i old)
{
    sfView *nview = ctx->game_view;
    sfVector2i n = (sfVector2i){evt.mouseMove.x, evt.mouseMove.y};
    sfVector2f c1;
    sfVector2f c2;

    c1 = sfRenderWindow_mapPixelToCoords(ctx->window, n, ctx->game_view);
    c2 = sfRenderWindow_mapPixelToCoords(ctx->window, old, ctx->game_view);
    c1 = (sfVector2f){c2.x - c1.x, c2.y - c1.y};
    sfView_move(nview, c1);
}

int modh_mouse_moved(void *evt_p, gcontext_t *ctx)
{
    sfEvent evt;
    static sfVector2i old = (sfVector2i){0, 0};

    if (evt_p == NULL || ctx == NULL)
        return (-1);
    evt = *(sfEvent *)evt_p;
    if (sfMouse_isButtonPressed(sfMouseLeft))
            mv_view(ctx, evt, old);
    old = (sfVector2i){evt.mouseMove.x, evt.mouseMove.y};
    return (0);
}
