/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include "nm.h"
#include "utils.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

static int map_stat(info_t *info, file_t *finfo, int *fd)
{
    struct stat s;

    if (info == NULL || finfo == NULL || *fd <= 0)
        return (84);
    if (fstat(*fd, &s) == -1)
        return (nmerror(info, "permission denied"));
    finfo->size = (size_t)s.st_size;
    finfo->vadress = mmap(0, finfo->size, PROT_READ, MAP_PRIVATE, *fd, 0);
    if (finfo->vadress == MAP_FAILED)
        return (nmerror(info, "file format not recognized"));
    close(*fd);
    return (0);
}

static int map_check(info_t *info, file_t *finfo)
{
    int fd;

    if (info == NULL || finfo == NULL)
        return (84);
    if (access(finfo->name, F_OK) == -1)
        return (nmserror(info, "No such file"));
    fd = open(finfo->name, O_RDONLY);
    if (fd == -1)
        return (nmerror(info, "permission denied"));
    return (map_stat(info, finfo, &fd));
}

int map_file(info_t *info)
{
    file_t *finfo;

    if (info == NULL)
        return (84);
    finfo = &info->finfo;
    return (map_check(info, finfo));
}
