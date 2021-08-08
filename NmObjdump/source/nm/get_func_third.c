/*
** EPITECH PROJECT, 2021
** get
** File description:
** get
*/

#include "nm.h"
#include <elf.h>

int get_other_bits32(Elf32_Shdr *sym, char *c)
{
    if (sym->sh_type == SHT_PROGBITS &&
    sym->sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        *c = 'T';
    return (0);
}

int get_other_bits64(Elf64_Shdr *sym, char *c)
{
    if (sym->sh_type == SHT_PROGBITS &&
    sym->sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        *c = 'T';
    return (0);
}
