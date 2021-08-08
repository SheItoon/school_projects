/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include "objdump.h"
#include "obj_utils.h"

static int map_stat(obj_t *obj, file_t *finfo, int *fd)
{
    struct stat s;

    if (obj == NULL || finfo == NULL || *fd <= 0)
        return (84);
    if (fstat(*fd, &s) == -1)
        return (objerror(obj, "permission denied"));
    finfo->size = (size_t)s.st_size;
    finfo->vadress = mmap(0, finfo->size, PROT_READ, MAP_PRIVATE, *fd, 0);
    if (finfo->vadress == MAP_FAILED)
        return (objerror(obj, "file format not recognized"));
    close(*fd);
    return (0);
}

static int map_check(obj_t *obj, file_t *finfo)
{
    int fd;

    if (obj == NULL || finfo == NULL)
        return (84);
    if (access(finfo->name, F_OK) == -1)
        return (objserror(obj, "No such file"));
    fd = open(finfo->name, O_RDONLY);
    if (fd == -1)
        return (objerror(obj, "permission denied"));
    return (map_stat(obj, finfo, &fd));
}

int map_file(obj_t *obj)
{
    file_t *finfo;

    if (obj == NULL)
        return (84);
    finfo = &obj->finfo;
    return (map_check(obj, finfo));
}
