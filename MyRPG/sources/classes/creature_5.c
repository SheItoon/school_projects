/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** creature_static_1.c
*/

#include <stdlib.h>
#include <math.h>
#include "gcontext.h"
#include "p_creature.h"
#include "csfml_toolbox.h"
#include "istl/utility.h"
#include "resource_holder.h"
#include "scene.h"

const sfVector2f UPRIGHT = (sfVector2f){1, -1};
const sfVector2f DWRIGHT = (sfVector2f){1, 1};

void creature_update_dir(creature_t *cr, sfVector2f dir)
{
    double m = 0;

    if (cr == 0)
        return;
    if (dir.x == 0) {
        if (dir.y == 0) {
            cr->velo = (sfVector2f){0, 0};
            return;
        }
        cr->velo.x = 0;
        cr->velo.y = (dir.y < 0) ? -1 * cr->speed : cr->speed;
        return;
    }
    m = dir.y / dir.x;
    cr->velo.x = cos(fabs(atan(m))) * cr->speed;
    cr->velo.y = sin(fabs(atan(m))) * cr->speed;
    cr->velo.x *= (dir.x < 0) ? -1 : 1;
    cr->velo.y *= (dir.y < 0) ? -1 : 1;
}

void creature_update_state(creature_t *cr, sfTime delta)
{
    float scalar_up = (float)V_DOT(cr->velo, UPRIGHT);
    float scalar_dw = (float)V_DOT(cr->velo, DWRIGHT);
    cm_state_t old = cr->mstate;

    T_ADD(cr->in_state, delta);
    if (scalar_up == 0 && scalar_dw == 0)
        return;
    cr->mstate = (scalar_up > 0 && scalar_dw > 0) ? CM_RIGHT : cr->mstate;
    cr->mstate = (scalar_up > 0 && scalar_dw < 0) ? CM_UP : cr->mstate;
    cr->mstate = (scalar_up < 0 && scalar_dw > 0) ? CM_DOWN : cr->mstate;
    cr->mstate = (scalar_up < 0 && scalar_dw < 0) ? CM_LEFT : cr->mstate;
    if (cr->mstate != old)
        cr->in_state = sfTime_Zero;
}

void creature_update_anim(creature_t *cr)
{
    sfIntRect *frame = 0;
    animf_t *anim = 0;

    anim = (cr->mstate == CM_RIGHT) ? rget_animation("creature_walk_r") : anim;
    anim = (cr->mstate == CM_LEFT) ? rget_animation("creature_walk_l") : anim;
    anim = (cr->mstate == CM_UP) ? rget_animation("creature_walk_u") : anim;
    anim = (cr->mstate == CM_DOWN) ? rget_animation("creature_walk_d") : anim;
    if (!creature_moves(cr) && anim == 0) {
        sfSprite_setTextureRect(cr->sprite, (sfIntRect){0, 0, 233, 466});
        return;
    }
    if (creature_moves(cr) && anim != NULL) {
        frame = animf_get_frame(anim, cr->in_state);
    } else {
        frame = animf_get_frame(anim, sfSeconds(0));
    }
    if (frame == 0 || cr->sprite == NULL)
        return;
    sfSprite_setTextureRect(cr->sprite, *frame);
}

bool_t cpoint_reached(creature_t *cr)
{
    sfVector2f *point = (cr == 0) ? 0 : it_data(list_begin(cr->path));
    sfVector2f tmp;
    double scalar;

    if (point == 0)
        return (TRUE);
    if (cr->sprite == 0)
        return (FALSE);
    tmp = sfSprite_getPosition(cr->sprite);
    tmp = (sfVector2f){point->x - tmp.x, point->y - tmp.y};
    scalar = V_DOT(tmp, cr->velo);
    if (scalar < 0)
        return (TRUE);
    return (FALSE);
}

void check_win(creature_t *cr)
{
    gcontext_t *ctx = get_app_context();

    if (cr == 0 || cr->path == 0)
        return;
    if (list_len(cr->path) == 0) {
        ctx->phealth -= 5;
        creature_deal_dmg(cr, 10000);
    }
}
