/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.c
*/

#include "gcontext.h"

list_t *app_get_chandlers(mdevent_type_t type)
{
    gcontext_t *ctx = get_app_context();
    hash_value_t hash = hash_data(&type, sizeof(mdevent_type_t));

    if (ctx->cstm_hdata == 0)
        return (0);
    return (map_get_all(ctx->cstm_hdata, hash));
}

void init_app_handlers(void)
{
    app_register(sfEvtClosed, apph_close_window);
    app_register(sfEvtKeyPressed, apph_key_pressed);
    app_register(sfEvtMouseWheelMoved, apph_mouse_scroll);
    app_register(sfEvtResized, apph_resize_window);
}

bool_t adjust_size(sfVector2u *v)
{
    bool_t safe = TRUE;

    if (v == 0)
        return (FALSE);
    safe = (v->x < 800 || v->x > 1920) ? FALSE : safe;
    safe = (v->y < 600 || v->x > 1080) ? FALSE : safe;
    v->x = expect_uint(v->x, 800, 1920);
    v->y = expect_uint(v->y, 600, 1080);
    return (!safe);
}

int apph_resize_window(void *evt_p, gcontext_t *ctx)
{
    sfEvent evt;
    sfVector2u nsize;
    static int counter = 0;

    evt = *(sfEvent *)evt_p;
    nsize.x = evt.size.width;
    nsize.y = evt.size.height;
    if (adjust_size(&nsize))
        sfRenderWindow_setSize(ctx->window, nsize);
    sfView_setSize(ctx->game_view, (sfVector2f){nsize.x, nsize.y});
    sfView_setSize(ctx->gui_view, (sfVector2f){nsize.x, nsize.y});
    return (0);
}
