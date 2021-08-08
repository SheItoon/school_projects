/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include <elf.h>
#include "nm.h"
#include <ar.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "arch.h"
#include "print.h"
#include "list.h"
#include "symbol.h"
#include <memory.h>
#include <sys/mman.h>
#include "check.h"

int print_file(file_t *info, int multi)
{
    if (multi)
        printf("\n%s:\n", info->name);
    if (info->arch == ELFCLASS32)
        print_syms32(info);
    else
        print_syms64(info);
    list_clear(&info->sym_links);
    return (0);
}

static void print_subfile(info_t *info, struct ar_hdr *header,
struct ar_hdr *current)
{
    info_t new;

    memcpy(&new, info, sizeof(info_t));
    if (handle_arch(&new, info, header, current) == 84) {
        nmerror(info, "can't create subfile informations");
        return;
    }
    if (check_elf(&new) == 84)
        return;
    printf("\n%s:\n", new.finfo.name);
    if (get_symbol_list(&new) == 84)
        return;
    print_file(&new.finfo, 0);
    free(new.finfo.name);
}

static void print_hdr(info_t *info, struct ar_hdr *header,
size_t *index, struct ar_hdr *next)
{
    for (; !header && next && !out_of_map(info, next,
    sizeof(struct ar_hdr)) && my_strlen(next->ar_name, '/', 16) == 0;
    next = next_arch(info, index))
        if (!strncmp(next->ar_name, "//", 2))
            header = next;
}

static void print_sub(info_t *info, struct ar_hdr *header,
size_t *index, struct ar_hdr *next)
{
    for (; next && !out_of_map(info, next, sizeof(struct ar_hdr));
    next = next_arch(info, index))
        print_subfile(info, header, next);
}

int print_arch(info_t *info)
{
    struct ar_hdr *header = NULL;
    size_t index = SARMAG;
    struct ar_hdr *next = (void *)((char *)info->finfo.vadress + index);

    if (info->nms)
        printf("\n%s:\n", info->finfo.name);
    print_hdr(info, header, &index, next);
    print_sub(info, header, &index, next);
    return (0);
}
