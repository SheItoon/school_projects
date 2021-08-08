/*
** EPITECH PROJECT, 2021
** func
** File description:
** func
*/

#include "nm.h"
#include <elf.h>
#include "elf_func.h"
#include "print.h"
#include "utils.h"
#include "get_func.h"

char get_bits32(Elf32_Shdr *sym, char *c)
{
    *c = '?';
    if (sym->sh_type == SHT_PROGBITS
    && sym->sh_flags == SHF_ALLOC)
        *c = 'R';
    else if (sym->sh_type == SHT_PROGBITS &&
    sym->sh_flags == (SHF_ALLOC | SHF_WRITE))
        *c = 'D';
    else
        return (get_other_bits32(sym, c));
    return (0);
}

char get_bits64(Elf64_Shdr *sym, char *c)
{
    *c = '?';
    if (sym->sh_type == SHT_PROGBITS
    && sym->sh_flags == SHF_ALLOC)
        *c = 'R';
    else if (sym->sh_type == SHT_PROGBITS &&
    sym->sh_flags == (SHF_ALLOC | SHF_WRITE))
        *c = 'D';
    else
        return (get_other_bits64(sym, c));
    return (0);
}

int get_type(info_t *info)
{
    for (list_t n = info->finfo.sym_links; n != NULL; n = n->next)
        if (loop_type(info, n))
            return (84);
    return (0);
}

char *get_name32(info_t *infos, Elf32_Shdr *shead)
{
    Elf32_Shdr *rshead = elf_get_sheader32(infos);
    Elf32_Shdr *sh_strtab;
    char *sh_strtab_p;

    if (out_of_map(infos, shead, sizeof(Elf32_Shdr)) || rshead == NULL)
    return (NULL);
    sh_strtab = rshead +
    ((Elf32_Ehdr *)infos->finfo.vadress)->e_shstrndx;
    if (out_of_map(infos, sh_strtab, sizeof(Elf32_Shdr)))
        return (NULL);
    sh_strtab_p = (void *)((char *)(infos->finfo.vadress) +
    sh_strtab->sh_offset);
    if (out_of_map(infos, sh_strtab_p, sh_strtab->sh_size) &&
        sh_strtab->sh_size > shead->sh_name)
        return (NULL);
    return (sh_strtab_p + shead->sh_name);
}

char *get_name64(info_t *infos, Elf64_Shdr *shead)
{
    Elf64_Shdr *rshead = elf_get_sheader64(infos);
    Elf64_Shdr *sh_strtab;
    char *sh_strtab_p;

    if (out_of_map(infos, shead, sizeof(Elf64_Shdr)) || rshead == NULL)
        return (NULL);
    sh_strtab = rshead +
        ((Elf64_Ehdr *)infos->finfo.vadress)->e_shstrndx;
    if (out_of_map(infos, sh_strtab, sizeof(Elf64_Shdr)))
        return (NULL);
    sh_strtab_p = (void *)((char *)(infos->finfo.vadress)
    + sh_strtab->sh_offset);
    if (out_of_map(infos, sh_strtab_p, sh_strtab->sh_size) &&
        sh_strtab->sh_size > shead->sh_name)
        return (NULL);
    return (sh_strtab_p + shead->sh_name);
}
