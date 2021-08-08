/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#include <elf.h>
#include "objdump.h"
#include "obj_utils.h"

int check_basic(obj_t *obj, Elf64_Ehdr *elf)
{
    if (elf->e_ident[EI_CLASS] == ELFCLASSNONE)
        return (objerror(obj, "file architecture not supported"));
    obj->finfo.arch = elf->e_ident[EI_CLASS];
    if (elf->e_ident[EI_DATA] != ELFDATA2LSB)
        return (objerror(obj, "file byte order not supported"));
    else if (elf->e_ident[EI_VERSION] != EV_CURRENT)
        return (objerror(obj, "file ELF version not supported"));
    return (0);
}
