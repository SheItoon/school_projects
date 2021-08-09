/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#include "my_world.h"

int get_tile(data_game *data, sfVector2f pixel_pos)
{
    if (pixel_pos.x < 0 || pixel_pos.y < 0)
        return (-1);
    for (int y = 1; y < data->map_y; y++)
        for (int x = 1; x < data->map_x; x++)
            if (data->map[y][x].y > pixel_pos.y &&
                data->map[y][x - 1].x + 16 < pixel_pos.x &&
                data->map[y - 1][x].x - 16 > pixel_pos.x) {
                data->selected_tile[3] = &data->map[y][x];
                data->selected_tile[2] = &data->map[y][x - 1];
                data->selected_tile[1] = &data->map[y - 1][x];
                data->selected_tile[0] = &data->map[y - 1][x - 1];
                return (0);
            }
    return (-1);
}

void set_direction(data_game *data, int x, int y)
{
    if (data->direction == UP)
        data->map[x][y].y -= 1;
    else if (data->direction == DOWN)
        data->map[x][y].y += 1;
}

void get_corner(data_game *data, sfVector2f pixel_pos)
{
    slider_t *slider = get_slider(data, "slider_effect");

    for (int y = 0; y < data->map_y; y++)
        for (int x = 0; x < data->map_x; x++)
            if (pixel_pos.x <
                data->map[x][y].x + (5 + slider->value * 15 * 3) &&
                pixel_pos.x >
                data->map[x][y].x - (5 + slider->value * 15 * 3) &&
                pixel_pos.y <
                data->map[x][y].y + (5 + slider->value * 15 * 3) &&
                pixel_pos.y >
                data->map[x][y].y - (5 + slider->value * 15 * 3)) {
                set_direction(data, x, y);
            }
}

void is_tile(data_game *data, sfVector2f pixel_pos)
{
    if (data->selection == TILE) {
        if (get_tile(data, pixel_pos) == -1)
            return;
        for (int i = 0; data->selected_tile[i] != NULL; i++) {
            if (data->direction == UP) {
                data->selected_tile[i]->y -= 1;
            } else if (data->direction == DOWN) {
                data->selected_tile[i]->y += 1;
            }
        }
    } else if (data->selection == CORNER)
        get_corner(data, pixel_pos);
}

void input(data_game *data)
{
    sfVector2i mouse_pos;
    sfVector2f pixel_pos;
    button_t *button = data->button;

    while (button) {
        button->pressed = 0;
        button = button->next;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse_pos = sfMouse_getPositionRenderWindow(data->window);
        pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, mouse_pos,
                                                    data->cam.camera);
        check_button(mouse_pos, data);
        slider_press_cursor(data, mouse_pos);
        is_tile(data, pixel_pos);
    }
    shortcut(data);
}