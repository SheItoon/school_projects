/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** gcontext_2.c
*/
#include "private/p_gcontext.h"
#include "csfml_toolbox.h"

sfTime get_frame_buffer(void)
{
    gcontext_t *context = get_app_context();

    return (context->frame_buffer);
}

sfTime get_frame_cap(void)
{
    gcontext_t *context = get_app_context();

    return (context->frame_cap);
}

sfRenderStates get_screen_states(void)
{
    sfVector2f factor;
    sfVideoMode smode = sfVideoMode_getDesktopMode();
    sfRenderStates def = (sfRenderStates){
        sfBlendAlpha,
        sfTransform_Identity,
        0,
        0
    };

    factor.x = smode.width / 1920.0f;
    factor.y = smode.height / 1080.0f;
    sfTransform_scale(&def.transform, factor.x, factor.y);
    return (def);
}

void app_init_window(sfVideoMode mode)
{
    sfUint32 opt = sfResize | sfClose;
    gcontext_t *ctx = get_app_context();

    mode.width = expect_uint(mode.width, 800, 1920);
    mode.height = expect_uint(mode.height,  600, 1080);
    ctx->window = sfRenderWindow_create(mode, "My RPG", opt, NULL);
    sfRenderWindow_setFramerateLimit(ctx->window, 366);
    sfRenderWindow_setKeyRepeatEnabled(ctx->window, sfTrue);
    ctx->appstates = get_screen_states();
    ctx->game_view = sfView_copy(sfRenderWindow_getDefaultView(ctx->window));
    ctx->gui_view = sfView_copy(ctx->game_view);
}
