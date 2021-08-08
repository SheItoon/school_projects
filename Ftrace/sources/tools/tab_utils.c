/*
** EPITECH PROJECT, 2021
** strace
** File description:
** tab_utils
*/

#include "ftrace.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int get_nb_lines(char **tab)
{
    int i = 0;

    if (!tab || !(*tab))
        return 0;
    for (; tab[i] != 0x0; i++);
    return i;
}

char **add_slashes(char **tab)
{
    if (!tab)
        return 0x0;
    for (int i = 0; tab[i] != 0x0; i++) {
        if (tab[i][strlen(tab[i])] != '/')
            tab[i] = append(tab[i], "/");
    }
    return tab;
}

void free_tab(char **v)
{
    if (!v) return;
    for (int i = 0; v[i] != 0x0; i++)
        free(v[i]);
    free(v);
}

char *extract_string(char **tab, char *string)
{
    if (!tab || !(*tab) || !string)
        return 0x0;
    for (int i = 0; tab[i] != 0x0; i++) {
        if (strncasecmp(tab[i], string, strlen(string)) == 0)
            return strdup(&tab[i][strlen(string)]);
    }
    return 0x0;
}
