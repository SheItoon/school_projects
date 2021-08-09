/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "my_world.h"
#include "normal.h"

void handle_event(data_game *data, sfEvent event)
{
    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(data->window);
            data->state = OVER;
        }
        if (event.type == sfEvtTextEntered)
            normal_func(data, event);
    }
}

void set_text(data_game *data)
{
    static int init = 0;
    sfVector2f play_pos = {data->winsize_f.x / 2 - 190, data->winsize_f.y / 3.5};
    sfVector2f exit_pos = {data->winsize_f.x / 2 - 190, data->winsize_f.y / 1.5};

    if (init == 0) {
        sfText_setString(data->loader.text, "My world");
        sfText_setCharacterSize(data->loader.text, 160);
        sfText_setOrigin(data->loader.text,
                         (sfVector2f) {sfText_getLocalBounds(
                                 data->loader.text).width / 2,
                                       data->winsize_f.y * 0.15f});
        sfText_setPosition(data->loader.text,
                           (sfVector2f) {data->winsize_f.x / 2,
                                         data->winsize_f.y * 0.1f});
        data->combo.text = sfText_create();
        add_button(data, play_pos, data->textures->button_l, "button_new");
        button_add_action(data, "button_new", &set_play);
        button_add_text(data, "button_new", "New Game");
        button_set_text_pos(data, "button_new", (sfVector2f) {15, 30}, 1);
        button_set_tag(data, "button_new", B_MENU);
        add_button(data, exit_pos, data->textures->button_l, "button_exit");
        button_add_action(data, "button_exit", &set_exit);
        button_add_text(data, "button_exit", "Exit");
        button_set_text_pos(data, "button_exit", (sfVector2f) {15, 30}, 1);
        button_set_tag(data, "button_exit", B_MENU);
        add_button(data, (sfVector2f) {data->winsize_f.x / 2 - 190, data->winsize_f.y / 2}, data->textures->button_l, "button_load");
        button_add_action(data, "button_load", &set_load);
        button_add_text(data, "button_load", "Load");
        button_set_text_pos(data, "button_load", (sfVector2f) {15, 30}, 1);
        button_set_tag(data, "button_load", B_MENU);
        add_button(data, (sfVector2f) {data->winsize_f.x / 2 - 190, data->winsize_f.y / 2 - 120}, data->textures->button_l, "button_how");
        button_add_action(data, "button_how", &display_how_to_play);
        button_add_text(data, "button_how", "How to play?");
        button_set_text_pos(data, "button_how", (sfVector2f) {15, 30}, 1);
        button_set_tag(data, "button_how", B_MENU);
        button_set_other_tex(data, "button_load", data->textures->button_hover_l, data->textures->button_press_l);
        button_set_other_tex(data, "button_exit", data->textures->button_hover_l, data->textures->button_press_l);
        button_set_other_tex(data, "button_new", data->textures->button_hover_l, data->textures->button_press_l);
        button_set_other_tex(data, "button_how", data->textures->button_hover_l, data->textures->button_press_l);
        init++;
    }
}

static void draw(data_game *data)
{
    sfRenderWindow_setView(data->window, data->cam.default_view);
    sfRenderWindow_drawSprite(data->window, data->loader.background, NULL);
    draw_button(data, B_MENU);
    sfRenderWindow_drawText(data->window, data->loader.text, NULL);
}

static void animate(data_game *data)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(30));
    float time = sfTime_asMilliseconds(
            sfClock_getElapsedTime(data->sys.clock));
    static float pastime = 0;
    float elapsed = time - pastime;
    static sfVector2f i = {1, 1};
    static float state = -0.025f;

    if (elapsed > interval) {
        sfText_setScale(data->loader.text, i);
        i.x += state;
        i.y += state;
        if (i.x <= 0.7)
            state = 0.025f;
        else if (i.x >= 1.2)
            state = -0.025f;
        pastime = time;
    }
}

void main_menu(data_game *data)
{
    sfEvent event;

    set_text(data);
    while (sfRenderWindow_isOpen(data->window) &&
           data->state == MENU) {
        sfRenderWindow_clear(data->window, sfBlue);
        input(data);
        handle_event(data, event);
        animate(data);
        draw(data);
        sfRenderWindow_display(data->window);
    }
}
