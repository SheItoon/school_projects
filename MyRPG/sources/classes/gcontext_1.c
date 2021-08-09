/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** gcontext.c
*/

#include "private/p_gcontext.h"

const meta_bundle_t MB_TILE = {0, 0, sizeof(int)};
const sfVector2f S_SIZE = (sfVector2f) {20000, 20000};

static void init_app_context(gcontext_t *ctx)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    if (ctx == 0)
        return;
    ctx->frame_clock = sfClock_create();
    ctx->texture_data = map_create(10, MB_TEXTURE);
    ctx->animation_data = map_create(10, MB_ANIMATION);
    ctx->font_data = map_create(10, MB_FONT);
    ctx->app_equeue = list_create(MB_ACTION);
    ctx->frame_buffer = sfMilliseconds(0);
    ctx->frame_cap = sfMilliseconds(17);
    ctx->sfml_hdata = map_create(10, MB_ACTION);
    ctx->cstm_hdata = map_create(10, MB_ACTION);
    ctx->session_p = NULL;
    ctx->appscene = scene_create(S_SIZE, (sfVector2i){1, 1});
    ctx->guiscene = scene_create((sfVector2f){1920, 1080}, (sfVector2i){1, 1});
    ctx->bgscene = scene_create(S_SIZE, (sfVector2i){1, 1});
    ctx->game_view = 0;
    ctx->gui_view = 0;
}

gcontext_t *get_app_context(void)
{
    static gcontext_t global_context = {0};
    static bool_t init = FALSE;

    if (!init) {
        init = TRUE;
        global_context.phealth = 100;
        global_context.pmoney = 150;
        init_app_context(&global_context);
        init_app_handlers();
    }
    return (&global_context);
}

void free_app_context(bool_t reset)
{
    gcontext_t *ctx = get_app_context();

    if (ctx->frame_clock != 0)
        sfClock_destroy(ctx->frame_clock);
    map_free(&ctx->texture_data);
    map_free(&ctx->animation_data);
    map_free(&ctx->font_data);
    list_free(&ctx->app_equeue);
    ctx->frame_buffer = sfMilliseconds(0);
    map_free(&ctx->sfml_hdata);
    map_free(&ctx->cstm_hdata);
    scene_free(&ctx->appscene);
    scene_free(&ctx->guiscene);
    scene_free(&ctx->bgscene);
    if (reset) {
        init_app_context(ctx);
        init_app_handlers();
    }
}

int app_set_session(session_t session_p)
{
    gcontext_t *ctx = get_app_context();

    ctx->session_p = session_p;
    return (0);
}

session_t app_get_session(void)
{
    gcontext_t *ctx = get_app_context();

    return (ctx->session_p);
}
