/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#include "nm.h"
#include <ar.h>
#include "arch.h"
#include "utils.h"
#include <string.h>
#include "elf_func.h"
#include "check.h"

const char header[] = {
    ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3
}; 

static int other_magic(info_t *info, Elf64_Ehdr *elf)
{
    if (info->finfo.size < sizeof(elf->e_ident))
        return (nmerror(info, "file format not recognized"));
    return (0);
}

static int check_magic(info_t *info, Elf64_Ehdr *elf)
{
    if (info->finfo.size < sizeof(header))
        return (nmerror(info, "file format not recognized"));
    else if (memcmp(info->finfo.vadress, header, sizeof(header)) != 0)
        return (nmerror(info, "file format not recognized"));
    else
        return (other_magic(info, elf));
}

static int check_basic(info_t *info, Elf64_Ehdr *elf)
{
    if (elf->e_ident[EI_CLASS] == ELFCLASSNONE)
        return (nmerror(info, "file architecture not supported"));
    info->finfo.arch = elf->e_ident[EI_CLASS];
    if (elf->e_ident[EI_DATA] != ELFDATA2LSB)
        return (nmerror(info, "file byte order not supported"));
    else if (elf->e_ident[EI_VERSION] != EV_CURRENT)
        return (nmerror(info, "file ELF version not supported"));
    return (0);
}

int check_arch(info_t *info)
{
    if (info->finfo.size < SARMAG)
        return (84);
    if (memcmp(info->finfo.vadress, ARMAG, SARMAG) != 0)
        return (84);
    return (0);
}

int check_elf(info_t *info)
{
    Elf64_Ehdr *elf = info->finfo.vadress;

    if (check_magic(info, elf) == 84 ||
    check_basic(info, elf) == 84)
        return (84);
    else if (info->finfo.size < elfheader_size(info->finfo.arch))
        return (nmerror(info, "file format not recognized"));
    else
        return (check_other_elf(info, elf));
}

