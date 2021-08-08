/*
** EPITECH PROJECT, 2021
** handler
** File description:
** handler
*/

#include "objdump.h"
#include "obj_utils.h"
#include "obj_print.h"

int arch_printing(obj_t *obj, int *ret)
{
    *ret = 0;
    if (print_arch(obj))
        return (my_munmap(obj, 84));
    return (0);
}

int elf_printing(obj_t *obj, int *ret)
{
    *ret = 0;
    if (print_elf(obj))
        return (my_munmap(obj, 84));
    return (0);
}
