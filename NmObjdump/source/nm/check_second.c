/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#include "nm.h"
#include "check.h"
#include "utils.h"

int check_other_elf(info_t *info, Elf64_Ehdr *elf)
{
    if (info == NULL)
        return (84);
    if (info->finfo.arch == ELFCLASS32 &&
    info->finfo.size < ((Elf32_Ehdr *)elf)->e_shoff)
        return (nmerror(info, "file format not recognized"));
    else if (info->finfo.arch == ELFCLASS64 &&
    info->finfo.size < elf->e_shoff)
        return (nmerror(info, "file format not recognized"));
    return (0);
}
