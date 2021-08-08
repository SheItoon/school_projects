/*
** EPITECH PROJECT, 2021
** symbol
** File description:
** symbol
*/

#include "nm.h"
#include "symbol.h"
#include <elf.h>
#include "list.h"
#include "utils.h"

int store_symbol32(info_t *infos, uint32_t size,
Elf32_Sym *symbols, void *strtab_p)
{
    if (out_of_map(infos, strtab_p, 0) ||
    out_of_map(infos, symbols, sizeof(Elf32_Sym) * size))
        return (nmerror(infos, "file format not recognized"));
    for (size_t i = 1; i < size; i++) {
        if (!nm_printable(symbols[i].st_info))
            continue;
        if (!list_push(&infos->finfo.sym_links, &symbols[i])) {
            list_clear(&infos->finfo.sym_links);
            return (nmerror(infos, "Not enough memory"));
        }
        infos->finfo.sym_links->name = (char *)strtab_p + symbols[i].st_name;
        if (out_of_map(infos, infos->finfo.sym_links->name, 0)) {
            list_clear(&infos->finfo.sym_links);
            return (nmerror(infos, "file format not recognized"));
        }
    }
    return (0);
}

int store_symbol64(info_t *infos, uint32_t size,
Elf64_Sym *symbols, void *strtab_p)
{
    if (out_of_map(infos, strtab_p, 0) ||
        out_of_map(infos, symbols, sizeof(Elf64_Sym) * size))
        return (nmerror(infos, "file format not recognized"));
    for (size_t i = 1; i < size; i++) {
        if (!nm_printable(symbols[i].st_info))
            continue;
        if (!list_push(&infos->finfo.sym_links, &symbols[i])) {
            list_clear(&infos->finfo.sym_links);
            return (nmerror(infos, "Not enough memory"));
        }
        infos->finfo.sym_links->name = (char *)strtab_p + symbols[i].st_name;
        if (out_of_map(infos, infos->finfo.sym_links->name, 0)) {
            list_clear(&infos->finfo.sym_links);
            return (nmerror(infos, "file format not recognized"));
        }
    }
    return (0);
}
