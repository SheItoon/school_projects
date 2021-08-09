/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "csfml_toolbox.h"
#include "p_standard_session.h"

void handle_game_update(sfTime delta)
{
    gcontext_t *ctx = get_app_context();
    utype_t var;

    scene_update(ctx->appscene, delta);
}

void render_mode(sfRenderWindow *window, sfRenderStates *st)
{
    gcontext_t *ctx = get_app_context();
    level_t *lvl = ctx->current_lvl;

    sfRenderWindow_clear(window, sfColor_fromRGB(74, 74, 74));
    sfRenderWindow_setView(window, ctx->game_view);
    scene_draw(window, ctx->bgscene, st);
    scene_draw(window, ctx->appscene, st);
    sfRenderWindow_setView(window, ctx->gui_view);
    scene_draw(window, ctx->guiscene, st);
    sfRenderWindow_display(window);
}

void session_update(gcontext_t *context)
{
    sfTime delta = sfClock_restart(context->frame_clock);
    delta = sfTime_add(delta, context->frame_buffer);
    sfTime cap = get_frame_cap();

    while (sfTime_gt(delta, cap)) {
        delta = sfTime_sub(delta, cap);
        handle_game_update(cap);
    }
    context->frame_buffer = delta;
}
