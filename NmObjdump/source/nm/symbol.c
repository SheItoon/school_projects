/*
** EPITECH PROJECT, 2021
** symbol
** File description:
** symbol
*/

#include "nm.h"
#include <elf.h>
#include "list.h"
#include "get_func.h"
#include "utils.h"
#include "elf_func.h"
#include "symbol.h"

char bind_symbol32(Elf32_Sym *sym, char *c)
{
    *c = '?';
    if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
        *c = 'u';
    else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
        *c = 'W';
        if (sym->st_shndx == SHN_UNDEF)
            *c = 'w';
    } else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK &&
    ELF64_ST_TYPE(sym->st_info) == STT_OBJECT) {
        *c = 'V';
        if (sym->st_shndx == SHN_UNDEF)
            *c = 'v';
    }
    return (0);
}

char bind_symbol64(Elf64_Sym *sym, char *c)
{
    *c = '?';
    if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
        *c = 'u';
    else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
        *c = 'W';
        if (sym->st_shndx == SHN_UNDEF)
            *c = 'w';
    } else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK &&
    ELF64_ST_TYPE(sym->st_info) == STT_OBJECT) {
        *c = 'V';
        if (sym->st_shndx == SHN_UNDEF)
            *c = 'v';
    }
    return (0);
}

int create_symbol_list32(info_t *infos)
{
    Elf32_Shdr *symtab = elf_get_section32(infos, ".symtab");
    Elf32_Shdr *strtab;
    uint64_t size;
    Elf32_Sym *symbol;
    void *strtab_p;

    if (!symtab || symtab->sh_type != SHT_SYMTAB)
        return (nmerror(infos, "no symbols"));
    strtab = elf_get_section32(infos, ".strtab");
    if (!strtab || strtab->sh_type != SHT_STRTAB)
        return (nmerror(infos, "no symbols name"));
    size = (uint64_t) (symtab->sh_size / symtab->sh_entsize);
    symbol = (void *)((char *)(infos->finfo.vadress) + symtab->sh_offset);
    strtab_p = (void *)((char *)(infos->finfo.vadress) + strtab->sh_offset);
    if (store_symbol32(infos, (uint32_t) size, symbol, strtab_p))
        return (84);
    return (0);
}

int create_symbol_list64(info_t *infos)
{
    Elf64_Shdr *symtab = elf_get_section64(infos, ".symtab");
    Elf64_Shdr *strtab;
    uint64_t size;
    Elf64_Sym *symbol;
    void *strtab_p;

    if (!symtab || symtab->sh_type != SHT_SYMTAB)
        return (nmerror(infos, "no symbols"));
    strtab = elf_get_section64(infos, ".strtab");
    if (!strtab || strtab->sh_type != SHT_STRTAB)
        return (nmerror(infos, "no symbols name"));
    size = (uint64_t) (symtab->sh_size / symtab->sh_entsize);
    symbol = (void *)((char *)(infos->finfo.vadress) + symtab->sh_offset);
    strtab_p = (void *)((char *)(infos->finfo.vadress) + strtab->sh_offset);
    if (store_symbol64(infos, (uint32_t) size, symbol, strtab_p))
        return (84);
    return (0);
}

int get_symbol_list(info_t *infos)
{
    if (infos->finfo.arch == ELFCLASS64) {
        if (create_symbol_list64(infos) == 84)
            return (84);
    } else {
        if (create_symbol_list32(infos) == 84)
            return (84);
    }
    list_sort(infos->finfo.sym_links);
    if (get_type(infos) == 84)
        return (84);
    return (0);
}

