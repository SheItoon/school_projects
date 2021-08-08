/*
** EPITECH PROJECT, 2021
** func
** File description:
** func
*/

#include "nm.h"
#include <elf.h>

int get_basic32(Elf32_Sym *sym, char *c)
{
    *c = '?';
    switch (sym->st_shndx) {
    case SHN_UNDEF:
        *c = 'U';
        break;
    case SHN_ABS:
        *c = 'A';
        break;
    case SHN_COMMON:
        *c = 'C';
        break;
    default:
        return (0);
    }
    return (0);
}

int get_basic64(Elf64_Sym *sym, char *c)
{
    *c = '?';
    switch (sym->st_shndx) {
    case SHN_UNDEF:
        *c = 'U';
        break;
    case SHN_ABS:
        *c = 'A';
        break;
    case SHN_COMMON:
        *c = 'C';
        break;
    default:
        return (0);
    }
    return (0);
}

char get_special32(Elf32_Shdr *sym, char *c)
{
    *c = '?';
    if (sym->sh_type == SHT_NOBITS &&
    sym->sh_flags == (SHF_ALLOC | SHF_WRITE))
        *c = 'B';
    else if (sym->sh_type == SHT_DYNAMIC)
        *c = 'D';
    return (0);
}

char get_special64(Elf64_Shdr *sym, char *c)
{
    *c = '?';
    if (sym->sh_type == SHT_NOBITS &&
    sym->sh_flags == (SHF_ALLOC | SHF_WRITE))
        *c = 'B';
    else if (sym->sh_type == SHT_DYNAMIC)
        *c = 'D';
    return (0);
}
