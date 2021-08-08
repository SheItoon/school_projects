/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include "nm.h"
#include "arch.h"
#include "print.h"
#include "symbol.h"
#include <elf.h>
#include "utils.h"
#include "elf_func.h"
#include "get_func.h"

int print_elf(info_t *info)
{
    if (get_symbol_list(info))
        return (84);
    print_file(&info->finfo, info->nms);
    return (0);
}

char print_type32(info_t *info, node_t *node)
{
    int sum = 0;
    Elf32_Shdr *shdr = elf_get_sheader32(info);
    Elf32_Sym *s = node->value;

    bind_symbol32(s, &node->type);
    if (node->type == '?' && get_basic32(s, &node->type) == 84)
        return (nmerror(info, "file format not recognized"));
    if (node->type == '?') {
        if (out_of_map(info, shdr + s->st_shndx, sizeof(Elf32_Shdr)))
            return (nmerror(info, "file format not recognized"));
        else if (get_bits32(&shdr[s->st_shndx], &node->type) == 84)
            return (nmerror(info, "file format not recognized"));
    }
    if (node->type == '?' &&
    get_special32(&shdr[s->st_shndx], &node->type) == 84)
        return (nmerror(info, "file format not recognized"));
    sum = (ELF64_ST_BIND(s->st_info) == STB_LOCAL && node->type != '?') * 32;
    node->type += sum;
    node->type = (node->type != '?' ? node->type : 't');
    return (0);
}

char print_type64(info_t *info, node_t *node)
{
    int sum = 0;
    Elf64_Shdr *shdr = elf_get_sheader64(info);
    Elf64_Sym *s = node->value;

    bind_symbol64(s, &node->type);
    if (node->type == '?' && get_basic64(s, &node->type) == 84)
        return (nmerror(info, "file format not recognized"));
    if (node->type == '?') {
        if (out_of_map(info, shdr + s->st_shndx, sizeof(Elf64_Shdr)))
            return (nmerror(info, "file format not recognized"));
        else if (get_bits64(&shdr[s->st_shndx], &node->type) == 84)
            return (nmerror(info, "file format not recognized"));
    }
    if (node->type == '?' &&
    get_special64(&shdr[s->st_shndx], &node->type) == 84)
        return (nmerror(info, "file format not recognized"));
    sum = (ELF64_ST_BIND(s->st_info) == STB_LOCAL && node->type != '?') * 32;
    node->type += sum;
    node->type = (node->type != '?' ? node->type : 't');
    return (0);
}

void print_syms32(file_t *info)
{
    unsigned long val;
    int pad = 8;

    for (list_t n = info->sym_links; n != NULL; n = n->next) {
        val = ((Elf32_Sym *)n->value)->st_value;
        if (((Elf32_Sym *)n->value)->st_value ||
        (n->type != 'U' && n->type != 'w'))
            printf("%0*lx ", pad, val);
        else
            printf("%*s ", pad, "");
        printf("%c ", n->type);
        printf("%s\n", n->name);
    }
}

void print_syms64(file_t *info)
{
    unsigned long val;
    int pad = 16;

    for (list_t n = info->sym_links; n != NULL; n = n->next) {
        val = ((Elf64_Sym *)n->value)->st_value;
        if (((Elf64_Sym *)n->value)->st_value ||
        (n->type != 'U' && n->type != 'w'))
            printf("%0*lx ", pad, val);
        else
            printf("%*s ", pad, "");
        printf("%c ", n->type);
        printf("%s\n", n->name);
    }
}
