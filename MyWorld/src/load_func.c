/*
** EPITECH PROJECT, 2020
** load
** File description:
** load
*/

#include "my_world.h"
#include "get_next_line.h"

int get_row(char *file)
{
    int fd;
    char *buffer = NULL;
    int y = 0;

    fd = open(file, O_RDONLY);
    if (!fd)
        return (0);
    while ((buffer = get_next_line(fd)) != NULL)
        y++;
    free(buffer);
    close(fd);
    return (y);
}

sfVector2f get_vector(int fd, data_game *data)
{
    char *tmp;
    char *tmp_2;
    static int jump = 0;
    static int count = 0;

    tmp = get_next_line(fd);
    if (tmp == NULL)
        return ((sfVector2f){-1, -1});
    jump++;
    if (jump % data->map_y == 1 && jump + (data->map_y * count) > 2)
        return ((sfVector2f){-1, -1});
    for (int i = 0; tmp[i]; i++)
        if (tmp[i] == ' ')
            tmp_2 = &tmp[i + 1];
    count++;
    return ((sfVector2f){my_getnbr(tmp) + 1, my_getnbr(tmp_2) + 1});
}
