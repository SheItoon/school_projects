/*
** EPITECH PROJECT, 2021
** objdump
** File description:
** obj
*/

#include <string.h>
#include "objdump.h"
#include "obj_arch.h"
#include "obj_elf_func.h"
#include "obj_map.h"
#include "obj_utils.h"
#include "obj_check.h"
#include "obj_print.h"

int objdumps(obj_t *obj, int ac, char **av)
{
    int ret = 0;
    int last;

    for (int i = 1; i < ac; i++) {
        obj->finfo.name = av[i];
        last = objdump(obj);
        if (last)
            ret = last;
        memset(&obj->finfo, 0, sizeof(file_t));
    }
    return (ret);
}

int objdump(obj_t *obj)
{
    int ret = 84;

    if (map_file(obj) == 84)
        return (84);
    if (!check_arch(obj)) {
        if (arch_printing(obj, &ret))
            return (my_munmap(obj, 84));
    } else if (!check_elf(obj))
        if (elf_printing(obj, &ret))
            return (my_munmap(obj, 84));
    return (ret);
}
