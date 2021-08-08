/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#include <ar.h>
#include <elf.h>
#include <string.h>
#include "objdump.h"
#include "obj_utils.h"
#include "obj_check.h"
#include "obj_elf.h"

const char header[] = {
    ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3
};

static int other_magic(obj_t *obj, Elf64_Ehdr *elf)
{
    if (obj->finfo.size < sizeof(elf->e_ident))
        return (objerror(obj, "file format not recognized"));
    return (0);
}

int check_arch(obj_t *obj)
{
    if (obj->finfo.size < SARMAG ||
    memcmp(obj->finfo.vadress, ARMAG, SARMAG) != 0)
        return (84);
    return (0);
}

static int check_other_elf(obj_t *obj, Elf64_Ehdr *elf)
{
    if (obj->finfo.arch == ELFCLASS32 &&
    obj->finfo.size < ((Elf32_Ehdr *)elf)->e_shoff)
        return (objerror(obj, "file format not recognized"));
    else if (obj->finfo.arch == ELFCLASS64 &&
    obj->finfo.size < elf->e_shoff)
        return (objerror(obj, "file format not recognized"));
    return (0);
}

static int check_magic(obj_t *obj, Elf64_Ehdr *elf)
{
    if (obj->finfo.size < sizeof(header))
        return (objerror(obj, "file format not recognized"));
    else if (memcmp(obj->finfo.vadress, header, sizeof(header)) != 0)
        return (objerror(obj, "file format not recognized"));
    else
        return (other_magic(obj, elf));
}

int check_elf(obj_t *obj)
{
    Elf64_Ehdr *elf = obj->finfo.vadress;

    if (check_magic(obj, elf) == 84 || check_basic(obj, elf) == 84)
        return (84);
    else if (obj->finfo.size < elfheader_size(obj->finfo.arch))
        return (objerror(obj, "file format not recognized"));
    else
        return (check_other_elf(obj, elf));
    return (0);
}
