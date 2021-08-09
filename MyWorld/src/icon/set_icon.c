/*
** EPITECH PROJECT, 2020
** icon
** File description:
** icon
*/

#include "my_world.h"

void set_icon(data_game *data)
{
    data->icon.image = sfImage_createFromFile("rsc/icon.jpg");
    data->icon.pixel = (sfUint8 *)sfImage_getPixelsPtr(data->icon.image);
    sfRenderWindow_setIcon(data->window, 75, 100, data->icon.pixel);
}
