/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "nm.h"
#include <sys/mman.h>
#include <elf.h>

int my_munmap(info_t *info, int ret)
{
    if (info->finfo.vadress)
        munmap(info->finfo.vadress, info->finfo.size);
    return (ret);
}

int out_of_map(info_t *info, void *addr, size_t len)
{
    return (!(info->finfo.vadress <= addr &&
    (char *)(addr) + len <= (char *)(info->finfo.vadress) +
    info->finfo.size));
}

int nmerror(info_t *infos, char const *str)
{
    if (infos)
        fprintf(stderr, "%s: %s: ", infos->name, infos->finfo.name);
    fprintf(stderr, "%s\n", str);
    return (84);
}

int nmserror(info_t *infos, char const *str)
{
    if (infos)
        fprintf(stderr, "%s: '%s': ", infos->name, infos->finfo.name);
    fprintf(stderr, "%s\n", str);
    return (84);
}

int nm_printable(size_t x)
{
    return (x != STT_SECTION && x != STT_FILE);
}
