/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** main_menu_session
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "standard_session.h"
#include "istl/utility.h"
#include "init_functions.h"
#include "menu_sessions.h"

static wrapper_menu_t load_game_menu(void)
{
    wrapper_menu_t res;

    res.play = sfSprite_create();
    res.quit = sfSprite_create();
    res.play_t = sfTexture_createFromFile("./resources/textures/play.png",
    NULL);
    res.quit_t = sfTexture_createFromFile("./resources/textures/quit.png",
    NULL);
    sfSprite_setTexture(res.quit, res.quit_t, sfTrue);
    sfSprite_setTexture(res.play, res.play_t, sfTrue);
    sfSprite_setPosition(res.play, (sfVector2f){500, 500});
    sfSprite_setPosition(res.quit, (sfVector2f){1200, 500});
    sfSprite_setScale(res.play, (sfVector2f){4, 4});
    sfSprite_setScale(res.quit, (sfVector2f){4, 4});
    res.song = sfMusic_createFromFile(menumusic_path);
    sfMusic_setVolume(res.song, 60);
    return (res);
}

static int check_if_start_game(sfEvent event, wrapper_menu_t start)
{
    sfFloatRect quit_button = sfSprite_getGlobalBounds(start.quit);
    sfFloatRect play_button = sfSprite_getGlobalBounds(start.play);

    if (sfFloatRect_contains(&quit_button, event.mouseButton.x,
    event.mouseButton.y))
        return 2;
    else if (sfFloatRect_contains(&play_button, event.mouseButton.x,
    event.mouseButton.y)) {
        return 1;
    }
    return 0;
}

static int handle_menu_event(sfRenderWindow *win, wrapper_menu_t s)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtMouseButtonReleased)
            return check_if_start_game(event, s);
        else if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win);
            return 2;
        }
    }
    return 0;
}

static void destroy_menu_session(wrapper_menu_t menu, sfSprite *spr, sfTexture *tex)
{
    sfSprite_destroy(spr);
    sfTexture_destroy(tex);
    sfSprite_destroy(menu.play);
    sfSprite_destroy(menu.quit);
    sfMusic_destroy(menu.song);
    sfTexture_destroy(menu.play_t);
    sfTexture_destroy(menu.quit_t);
}

state_t menu_session(void)
{
    gcontext_t *ctx = get_app_context();
    wrapper_menu_t menu = load_game_menu();
    sfSprite *bck = sfSprite_create();
    sfTexture *tx = sfTexture_createFromFile(backgroundtx_path, NULL);
    state_t event;

    sfSprite_setTexture(bck, tx, sfTrue);
    sfMusic_play(menu.song);
    for (; sfRenderWindow_isOpen(ctx->window);) {
        event = handle_menu_event(ctx->window, menu);
        if (event != 0)
            break;
        sfRenderWindow_drawSprite(ctx->window, bck, &ctx->appstates);
        sfRenderWindow_drawSprite(ctx->window, menu.play, &ctx->appstates);
        sfRenderWindow_drawSprite(ctx->window, menu.quit, &ctx->appstates);
        sfRenderWindow_display(ctx->window);
    }
    sfMusic_stop(menu.song);
    destroy_menu_session(menu, bck, tx);
    return (event == 1 ? PLAY : QUIT);
}