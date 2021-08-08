/*
** EPITECH PROJECT, 2021
** nm
** File description:
** nm
*/

#include "nm.h"
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <zconf.h>
#include <string.h>
#include "map.h"
#include "print.h"
#include "check.h"
#include "utils.h"

int nm_engine(int ac, char **av)
{
    info_t *infos = init(av);
    int ret = 84;

    if (infos == NULL)
        return (84);
    switch (ac) {
    case 1: infos->finfo.name = "a.out";
        ret = nm(infos);
        clear(infos);
        return (ret);
    case 2: infos->finfo.name = av[1];
        ret = nm(infos);
        clear(infos);
        return (ret);
    default: ret = nms(ac, av, infos);
        clear(infos);
        return (ret);
    }
}

int nms(int ac, char **av, info_t *infos)
{
    int ret = 0;
    int last;

    infos->nms = 1;
    for (int i = 1; i < ac; i++) {
        infos->finfo.name = av[i];
        last = nm(infos);
        if (last)
            ret = last;
        memset(&infos->finfo, 0, sizeof(file_t));
    }
    return (ret);
}

int nm(info_t *info)
{
    int ret = 84;

    if (map_file(info) == 84)
        return (84);
    if (check_arch(info) == 0) {
        ret = 0;
        if (print_arch(info))
            return (my_munmap(info, 84));
    } else if (check_elf(info) == 0) {
        ret = 0;
        if (print_elf(info))
            return (my_munmap(info, 84));
    }
    return (my_munmap(info, ret));
}
