/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#include "my_world.h"
#include "menu.h"
#include "config.h"
#include "icon.h"

void my_world(data_game *data)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(data->window) && data->state == GAME) {
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_setView(data->window, data->interface_view);
        display_sprite(data);
        while (sfRenderWindow_pollEvent(data->window, &event))
            analyse_event(data, event);
        sfRenderWindow_setView(data->window, data->cam.camera);
        move_cam(data);
        input(data);
        draw_2d_map(data);
        draw_selection(data);
        draw_button(data, B_GAME);
        draw_slider(data);
        sfRenderWindow_display(data->window);
    }
}

void thread_init(void *info)
{
    data_game *data = (data_game *) info;

    sfMutex_lock(data->thread.lock);
    data->cam.factor = 1, data->loader.toload++;
    data->save.has_loaded = 0;
    data->map_x = MAP_X;
    data->map_y = MAP_Y;
    data->map = NULL;
    data->button = NULL;
    data->slider = NULL;
    data->selection = CORNER;
    data->selected_tile = NULL;
    data->sprites = malloc(sizeof(sprite_t)), data->loader.toload++;
    data->selected_tile = malloc(sizeof(sfVector2f *) * 5);
    data->loader.toload += 5;
    for (int i = 0; i < 5; i++)
        data->selected_tile[i] = NULL;
    data->interface_view = sfView_copy(
            (sfView *) sfRenderWindow_getDefaultView(data->window));
    data->loader.toload++;
    sfView_setCenter(data->interface_view, (sfVector2f) {data->winsize_f.x / 2,
                                                         data->winsize_f.y /
                                                         2});
    data->loader.toload++;
    sfView_zoom(data->interface_view, 1);
    reset_map(data);
    data->loader.ready = sfTrue;
    load_interface(data);
    create_button_how(data);
    sfMutex_unlock(data->thread.lock);
}

void init(data_game *data)
{
    sfVideoMode mode = {1920, 1080, 32};

    data->state = START;
    data->window = sfRenderWindow_create(mode, "My world", sfDefaultStyle,
                                         NULL);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    set_icon(data);
    srand(0);
    data->combo.buffer = NULL;
    data->sys.clock = sfClock_create();
    data->loader.toload = 0;
    data->loader.loaded = MAX_LOAD;
    data->loader.ready = sfFalse;
    data->window_size = sfRenderWindow_getSize(data->window);
    data->winsize_f = (sfVector2f) {(float) data->window_size.x,
                                    (float) data->window_size.y};
    init_loading(data);
    data->state = LOADING;
    data->direction = UP;
    data->thread.lock = sfMutex_create();
    data->thread.init = sfThread_create(&thread_init, data);
    sfThread_launch(data->thread.init);
}

int check_help(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (display_help(), 1);
    return (0);
}

int main(int ac, char **av)
{
    data_game *data = malloc(sizeof(data_game));

    if (ac != 2 && ac != 1)
        return (84);
    else if (ac == 2)
        if (check_help(av))
            return (0);
    init(data);
    while (data->state != ENDGAME && data->state != ENDLOAD)
        switch (data->state) {
        case LOADING: loader(data);
            break;
        case MENU: main_menu(data);
            break;
        case HELP: how_to_play(data);
            break;
        case PAUSE:
            break;
        case GAME: my_world(data);
            break;
        case OVER:unload_game(data);
            break;
        }
    return (free(data), 0);
}
