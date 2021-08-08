/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include <stdio.h>
#include <elf.h>
#include <string.h>
#include "flags.h"
#include "objdump.h"
#include "obj_print.h"
#include "obj_utils.h"
#include "obj_get.h"

const size_t vflags[] = {
    HAS_RELOC,
    EXEC_P,
    HAS_SYMS,
    DYNAMIC,
    D_PAGED
};

const char *nflags[] = {
    "HAS_RELOC",
    "EXEC_P",
    "HAS_SYMS",
    "DYNAMIC",
    "D_PAGED"
};

int print_section(obj_t *obj)
{
    if (obj->finfo.arch == ELFCLASS64)
        print_section64(obj);
    else
        print_section32(obj);
    return (0);
}

int print_header(obj_t *obj)
{
    if (obj->finfo.arch == ELFCLASS64)
        print_header64(obj);
    else
        print_header32(obj);
    return (0);
}

void print_flags(size_t flags)
{
    int coma = 0;

    for (size_t i = 0; i < 5; i++) {
        if ((flags & vflags[i]) == vflags[i] && coma)
            printf(", ");
        if ((flags & vflags[i]) == vflags[i]) {
            printf("%s", nflags[i]);
            coma = 1;
        }
    }
    printf("\n");
}

int print_section64(obj_t *obj)
{
    Elf64_Shdr *shder = get_sheader64(obj);
    Elf64_Ehdr *ehdr = obj->finfo.vadress;
    char *name;

    for (size_t i = 1; i < ehdr->e_shnum; ++i) {
        if (out_of_map(obj, shder + i, sizeof(Elf64_Shdr)))
            return (objerror(obj, "file format not recognized"));
        name = get_section_name64(obj, &shder[i]);
        if (!name || shder[i].sh_size == 0 ||
        shder[i].sh_type == SHT_NULL || !blacklist(name))
            continue;
        if (out_of_map(obj, (char *)obj->finfo.vadress + shder[i].sh_offset,
        shder[i].sh_size))
            return (objerror(obj, "file format not recognized"));
        printf("Contents of section %s:\n", name);
        print_hexa((void *)((char *)obj->finfo.vadress + shder[i].sh_offset),
        shder[i].sh_addr, shder[i].sh_size);
    }
    return (0);
}
