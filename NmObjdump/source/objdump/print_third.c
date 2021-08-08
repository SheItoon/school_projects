/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include <elf.h>
#include <stdio.h>
#include <string.h>
#include "objdump.h"
#include "obj_print.h"
#include "obj_utils.h"
#include "obj_get.h"
#include "flags.h"

int print_section32(obj_t *obj)
{
    Elf32_Shdr *shder = get_sheader32(obj);
    Elf32_Ehdr *ehdr = obj->finfo.vadress;
    char *name;

    for (size_t i = 1; i < ehdr->e_shnum; ++i) {
        if (out_of_map(obj, shder + i, sizeof(Elf64_Shdr)))
            return (objerror(obj, "file format not recognized"));
        name = get_section_name32(obj, &shder[i]);
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

static size_t get_flags64(Elf64_Shdr *shdr, Elf64_Ehdr *ehdr,
size_t size_headers)
{
    size_t flags = 0;

    for (size_t i = 0; i < size_headers; i ++)
        if (shdr[i].sh_type & (SHT_RELA | SHT_REL)) {
            flags |= HAS_RELOC;
            break;
        }
    flags |= HAS_SYMS;
    if (ehdr->e_type == ET_EXEC) {
        flags &= ~HAS_RELOC;
        flags |= EXEC_P | D_PAGED;
    }
    if (ehdr->e_type == ET_DYN) {
        flags &= ~HAS_RELOC;
        flags |= DYNAMIC | D_PAGED;
    }
    return (flags);
}

static size_t get_flags32(Elf32_Shdr *shdr, Elf32_Ehdr *ehdr,
size_t size_headers)
{
    size_t flags = 0;

    for (size_t i = 0; i < size_headers; i ++)
        if (shdr[i].sh_type & (SHT_RELA | SHT_REL)) {
            flags |= HAS_RELOC;
            break;
        }
    flags |= HAS_SYMS;
    if (ehdr->e_type == ET_EXEC) {
        flags &= ~HAS_RELOC;
        flags |= EXEC_P | D_PAGED;
    }
    if (ehdr->e_type == ET_DYN) {
        flags &= ~HAS_RELOC;
        flags |= DYNAMIC | D_PAGED;
    }
    return (flags);
}

int print_header32(obj_t *obj)
{
    Elf32_Ehdr *ehdr = obj->finfo.vadress;
    size_t flags;

    if (out_of_map(obj, get_sheader32(obj),
    ehdr->e_shnum * sizeof(Elf32_Shdr)))
        return (objerror(obj, "file format not recognized"));
    flags = get_flags32(get_sheader32(obj), ehdr, ehdr->e_shnum);
    printf("\n");
    printf("%s:     file format %s\n", obj->finfo.name, "elf32-i386");
    printf("architecture: %s, flags 0x%08lx:\n", "i386", flags);
    print_flags(flags);
    printf("start address 0x%08x\n", ehdr->e_entry);
    printf("\n");
    return (0);
}

int print_header64(obj_t *obj)
{
    Elf64_Ehdr *ehdr = obj->finfo.vadress;
    size_t flags;

    if (out_of_map(obj, get_sheader64(obj),
    ehdr->e_shnum * sizeof(Elf64_Shdr)))
        return (objerror(obj, "file format not recognized"));
    flags = get_flags64(get_sheader64(obj), ehdr, ehdr->e_shnum);
    printf("\n");
    printf("%s:     file format %s\n", obj->finfo.name, "elf64-x86-64");
    printf("architecture: %s, flags 0x%08lx:\n", "i386:x86-64", flags);
    print_flags(flags);
    printf("start address 0x%016lx\n", ehdr->e_entry);
    printf("\n");
    return (0);
}
