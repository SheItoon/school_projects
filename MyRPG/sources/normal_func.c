/*
** EPITECH PROJECT, 2020
** normal
** File description:
** normal
*/

#include <SFML/Window.h>
#include "my.h"
#include <stdlib.h>
#include "normal.h"

int reset(combo_t *data)
{
    data->done = 0;
    for (int i = 0; i < 5; i++)
        data->buffer[i] = 0;
    return (0);
}

int add_to_string(combo_t *data, char var)
{
    int i = my_strlen(data->buffer);

    if (i == 5)
        return (0);
    data->buffer[i] = var;
    return (i);
}

void init_stuff(combo_t *data)
{
    if (data->buffer == NULL) {
        data->buffer = malloc(sizeof(char) * 6);
        data->buffer = memset(data->buffer, 0, 6);
    }
}

int set_all(combo_t *data)
{
    char const *str = "shrek";

    for (int i = 0; i < 5; i++)
        if (data->buffer[i] != str[i])
            return (reset(data), 0);
    data->done = 1;
    return (0);
}

void normal_func(combo_t *data, sfEvent event)
{
    init_stuff(data);
    if (data == NULL || data->buffer == NULL)
        return;
    if (parse_shrek(data, (char)event.text.unicode))
        reset(data);
    if (my_strlen(data->buffer) == 5)
        set_all(data);
    if (data->done)
        my_putshrek(), reset(data);
}
