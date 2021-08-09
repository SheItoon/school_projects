/*
** EPITECH PROJECT, 2020
** read_map.h
** File description:
** handles map reading
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#ifndef SOKOBAN_LEVEL
#define SOKOBAN_LEVEL

#ifndef READ_SIZE
#define READ_SIZE (60)
#endif

#ifndef O_RDONLY
#define O_RDONLY (00)
#endif

#include "creature.h"
typedef struct map_elems
{
    char character;
    int translation;
} map_elems_t;

// EXAMPLE
/*map_elems_t MAP_ELEMS[] = {
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7},
    {'i', 8},
    {'j', 9},
    {'k', 10},
    {'l', 11},
    {0, -1},
};*/

// read_map.c
int **read_map(char const *filepath, const map_elems_t *elems);

// malloc_toolbox.c
void free_tab(void **whatevertab);
int **append_int_array(int **, char *, const map_elems_t *);
int *copy_int_array(int *array);
int *translate_char_array(char *, const map_elems_t *);

// get_next_line.c
char *get_next_line(int);

#endif
