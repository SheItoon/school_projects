/*
** EPITECH PROJECT, 2021
** tu
** File description:
** ti
*/

#include <string.h>
#include <stdlib.h>
#include "objdump.h"

int blacklist(char *tmp)
{
    if (!strcmp(tmp, "")
    || !strcmp(tmp, ".bss")
    || !strcmp(tmp, ".symtab")
    || !strcmp(tmp, ".strtab")
    || !strcmp(tmp, ".shstrtab")
    || (!strncmp(tmp, ".rela", 5) && strcmp(tmp, ".rela.dyn")
    && strcmp(tmp, ".rela.plt"))
    || !strcmp(tmp, ".note.GNU-stack"))
        return (0);
    return (1);
}

void clear(obj_t *obj)
{
    if (obj)
        free(obj);
}
