/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#include "my_world.h"

void move_cam(void *info)
{
    data_game *data = (data_game *) info;
    sfVector2i mouse_pos;
    float x = 0;
    float y = 0;

    mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    if (!sfRenderWindow_hasFocus(data->window))
        return;
    if ((float) mouse_pos.x >= data->winsize_f.x - 20)
        x = 10;
    else if (mouse_pos.x <= 20)
        x = -10;
    if ((float) mouse_pos.y >= data->winsize_f.y - 20)
        y = 10;
    else if (mouse_pos.y <= 20)
        y = -10;
    sfView_move(data->cam.camera, (sfVector2f) {x, y});
}

void key_move(data_game *data, sfKeyCode key)
{
    float x = 0;
    float y = 0;

    switch (key) {
        case sfKeyRight:
            x = -10;
            break;
        case sfKeyLeft:
            x = 10;
            break;
        case sfKeyUp:
            y = 10;
            break;
        case sfKeyDown:
            y = -10;
            break;
        default:
            break;
    }
    sfView_move(data->cam.camera, (sfVector2f) {x, y});
}

void zoom_cam(data_game *data, sfKeyCode key, float delta)
{
    float foo = 0;
    float jaj = 1;

    if ((data->cam.factor <= 0.5 && (key == sfKeyPageDown || delta < 0))
        || ((key == sfKeyPageUp || delta > 0) && data->cam.factor >= 2))
        return;
    if (key)
        switch (key) {
            case sfKeyPageUp:
                foo = 1.1f, jaj = 0.9f;
                break;
            case sfKeyPageDown:
                foo = 0.9f, jaj = 1.1f;
                break;
            default:
                break;
        }
    else if (delta > 0)
        foo = 1.1f, jaj = 0.9f;
    else if (delta < 0)
        foo = 0.9f, jaj = 1.1f;
    data->cam.factor *= foo, sfView_zoom(data->cam.camera, jaj);
}

void analyse_event(data_game *data, sfEvent event)
{
    switch (event.type) {
        case sfEvtClosed:
            data->state = OVER, sfRenderWindow_close(data->window);
            break;
        case sfEvtMouseWheelScrolled:
            zoom_cam(data, 0, event.mouseWheelScroll.delta);
            break;
        case sfEvtKeyPressed:
            switch (event.key.code) {
                case sfKeyPageUp:
                case sfKeyPageDown:
                    zoom_cam(data, event.key.code, 0);
                    break;
                case sfKeyRight:
                case sfKeyLeft:
                case sfKeyUp:
                case sfKeyDown:
                    key_move(data, event.key.code);
                    break;
            }
    }
}
