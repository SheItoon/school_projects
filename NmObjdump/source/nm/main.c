/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "nm.h"

int main(int ac, char **av)
{
    return (nm_engine(ac, av));
    info_t *infos = malloc(sizeof(info_t));

    if (infos == NULL)
        return (84);
    memset(infos, 0, sizeof(info_t));
    infos->name = av[0];
    switch (ac) {
    case 1:
        infos->finfo.name = "a.out";
        return (nm(infos));
    case 2:
        infos->finfo.name = av[1];
        return (nm(infos));
    default:
        return (nms(ac, av, infos));
    }
}
