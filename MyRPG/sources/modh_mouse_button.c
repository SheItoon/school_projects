/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** modh_mouse_button.c
*/
#include "standard_session.h"

static sfVector2f get_mpos_world(sfVector2i m)
{
    gcontext_t *ctx = get_app_context();
    sfView const *view = ctx->game_view;
    sfTransform trs = ctx->appstates.transform;
    sfVector2f res;

    trs = sfTransform_getInverse(&trs);
    res = sfRenderWindow_mapPixelToCoords(ctx->window, m, view);
    res = sfTransform_transformPoint(&trs, res);
    return (res);
}

static void mb_button_pressed(sfEvent evt, sfClock *dt)
{
    if (dt == 0)
        return;
    sfClock_restart(dt);
}

static int set_tower_type(sfEvent evt)
{
    sfFloatRect r[] = {
        (sfFloatRect){240, 20, 48, 48},
        (sfFloatRect){298, 20, 48, 48},
        (sfFloatRect){356, 20, 48, 48},
        (sfFloatRect){414, 20, 48, 48}
    };
    gcontext_t *ctx = get_app_context();
    sfVector2f pos = (sfVector2f){evt.mouseButton.x, evt.mouseButton.y};
    utype_t var;

    pos = sfRenderWindow_mapPixelToCoords
        (ctx->window, (sfVector2i){pos.x, pos.y}, ctx->gui_view);
    for (int i = 0; i < 4; i++) {
        if (sfFloatRect_contains(&r[i], pos.x, pos.y)) {
            var.i_num = i;
            utility_set_var("ttype", var);
            return (1);
        }
    }
    return (0);
}

static void mb_button_released(sfEvent evt, sfClock *dt)
{
    sfTime delta;
    mdevent_t ievt;
    gcontext_t *ctx = get_app_context();
    sfVector2f m;
    utype_t *var;

    if (dt == 0)
        return;
    delta = sfClock_restart(dt);
    if (sfTime_asMilliseconds(delta) > 75 || set_tower_type(evt) != 0)
        return;
}

int modh_mouse_button(void *evt_p, gcontext_t *ctx)
{
    sfEvent evt;
    static sfClock *cdt = 0;

    if (evt_p == NULL || ctx == NULL)
        return (-1);
    cdt = (cdt == 0) ? sfClock_create() : cdt;
    evt = *(sfEvent *)evt_p;
    if (evt.type == sfEvtMouseButtonPressed)
        mb_button_pressed(evt, cdt);
    else if (evt.type == sfEvtMouseButtonReleased)
        mb_button_released(evt, cdt);
    else
        return (-1);
    return (0);
}
