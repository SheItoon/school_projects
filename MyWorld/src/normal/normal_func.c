/*
** EPITECH PROJECT, 2020
** normal
** File description:
** normal
*/

#include "my_world.h"

int reset(data_game *data)
{
    data->combo.done = 0;
    for (int i = 0; i < 5; i++)
        data->combo.buffer[i] = 0;
    return (0);
}

int add_to_string(data_game *data, char var)
{
    int i = strlen(data->combo.buffer);

    if (i == 5)
        return (0);
    data->combo.buffer[i] = var;
    return (i);
}

void init_stuff(data_game *data)
{
    if (data->combo.buffer == NULL) {
        data->combo.buffer = malloc(sizeof(char) * 6);
        data->combo.buffer = memset(data->combo.buffer, 0, 6);
    }
}

int set_all(data_game *data)
{
    char const *str = "shrek";

    for (int i = 0; i < 5; i++)
        if (data->combo.buffer[i] != str[i])
            return (reset(data), 0);
    data->combo.done = 1;
}

void normal_func(data_game *data, sfEvent event)
{
    init_stuff(data);
    if (parse_shrek(data, (char)event.text.unicode))
        reset(data);
    if (my_strlen(data->combo.buffer) == 5)
        set_all(data);
    if (data->combo.done)
        my_putshrek(), reset(data);
}
