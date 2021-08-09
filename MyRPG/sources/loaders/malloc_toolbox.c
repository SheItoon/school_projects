/*
** EPITECH PROJECT, 2020
** malloc_toolbox
** File description:
** any function used to malloc a string
*/

#include "read_map.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"

int *copy_int_array(int *array)
{
    int size = 0;
    int *result = 0;

    for (; array[size] != -1; size++);
    result = malloc(sizeof(int) * (size + 1));
    for (int i = 0; i < size; i++)
        result[i] = array[i];
    result[size] = -1;
    return (result);
}

int *translate_char_array(char *str, const map_elems_t *elems)
{
    int size = my_strlen(str);
    int *result = size == 0 ? NULL : malloc(sizeof(int) * (size + 1));

    if (result == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        for (int j = 0; elems[j].character != 0; j++)
            if (elems[j].character == str[i]) {
                result[i] = elems[j].translation;
                break;
            } else result[i] = -1;
    }
    result[size] = -1;
    return (result);
}

static int get_tab_length(int **tab)
{
    int size = 0;

    if (tab == NULL)
        return (0);
    for (; tab[size] != NULL; size++);
    return size;
}

int **append_int_array(int **tab, char *str, const map_elems_t *elems)
{
    int tab_len = get_tab_length(tab);
    int **result = malloc(sizeof(int *) * (tab_len + 2));
    int i = 0;

    if (tab != NULL)
        for (; i < tab_len; i++)
            result[i] = copy_int_array(tab[i]);
    result[i] = translate_char_array(str, elems);
    i++;
    result[i] = NULL;
    free_tab((void **)tab);
    return (result);
}

void free_tab(void **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
