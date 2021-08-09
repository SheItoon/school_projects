/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "combat_session.h"
#include "standard_session.h"

static sfVector2f get_mvec(sfEvent evt)
{
    sfVector2f vec = (sfVector2f) {233, 233};

    switch (evt.key.code) {
        case sfKeyLeft:
            vec.x *= -1;
            vec.y *= 0;
            break;
        case sfKeyRight:
            vec.y *= 0;
            break;
        case sfKeyUp:
            vec.x *= 0;
            vec.y *= -1;
            break;
        case sfKeyDown:
            vec.x *= 0;
        default:
            break;
    }
    return (vec);
}

sfVector2f round_to_tile(sfVector2f pos)
{
    sfVector2f res;
    float tmp;

    res.x = pos.x / 233;
    res.y = pos.y / 233;
    tmp = res.x - (int)res.x;
    if (tmp >= 0.5)
        res.x = (int)res.x + 1;
    else res.x = (int)res.x;
    tmp = res.y - (int)res.y;
    if (tmp >= 0.5)
        res.y = (int)res.y + 1;
    else res.y = (int)res.y;
    res.x *= 233;
    res.y *= 233;
    return (res);
}

static void move_hero(sfEvent evt, gcontext_t *ctx)
{
    sfVector2f vec = (sfVector2f) {233, 233};
    sfVector2f pos;
    creature_t *hero = NULL;
    robject_t *ptr;

    vec = get_mvec(evt);
    hero = ((utype_t *)utility_get_var("hero"))->ptr;
    if (creature_moves(hero))
        return;
    pos = creature_get_position(hero);
    pos = (sfVector2f) { pos.x + vec.x, pos.y + vec.y };
    ptr = scene_get_at(ctx->appscene, pos);
    if (ptr == NULL || ptr->ptr == hero) {
        pos = sfSprite_getPosition(hero->sprite);
        pos = (sfVector2f) { pos.x + vec.x, pos.y + vec.y };
        creature_move_at(hero, round_to_tile(pos));
    }
}

int modh_key_pressed(void *evt_p, gcontext_t *ctx)
{
    sfEvent evt;
    sfVector2f vec = (sfVector2f) {233, 233};
    sfVector2f pos;
    creature_t *hero = NULL;
    robject_t *ptr;
    static int c = 0;

    if (evt_p == NULL || ctx == NULL)
        return (-1);
    evt = *(sfEvent *)evt_p;
    if (app_get_session() != standart_session)
        return (0);
    vec = get_mvec(evt);
    if (c == 10) {
        utility_set_var("enemy_ptr", (utype_t) {.i_num = 0});
        app_set_session(combat_session);
        c = 0;
    } else c += 1;
    move_hero(evt, ctx);
    return (0);
}
