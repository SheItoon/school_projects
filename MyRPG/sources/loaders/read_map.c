/*
** EPITECH PROJECT, 2020
** sokoban_level.h
** File description:
** standalone level in the game, anything needed to run this mini game is here.
*/

#include <unistd.h>
#include "my.h"
#include "read_map.h"

int **read_map(char const *filepath, const map_elems_t *elems)
{
    int fd = open(filepath, O_RDONLY);
    int **res = NULL;
    char *buffer = get_next_line(fd);

    if (fd == -1) {
        write(2, "Couldn't open file descriptor for:", 35);
        write(2, filepath, my_strlen(filepath));
        write(2, "\n", 1);
        return NULL;
    }
    while (buffer != NULL) {
        res = append_int_array(res, buffer, elems);
        free(buffer);
        buffer = get_next_line(fd);
    }
    close(fd);
    return (res);
}
