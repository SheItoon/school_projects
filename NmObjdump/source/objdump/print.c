/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include <ar.h>
#include <stdio.h>
#include <string.h>
#include "objdump.h"
#include "obj_utils.h"
#include "obj_arch.h"
#include "obj_check.h"
#include "obj_print.h"

int print_elf(obj_t *obj)
{
    if (!print_header(obj)) {
        if (print_section(obj) == 84)
            return (84);
    } else
        return (84);
    return (0);
}

static void print_subfile(obj_t *obj, struct ar_hdr *header,
struct ar_hdr *current)
{
    obj_t new;

    memcpy(&new, obj, sizeof(obj_t));
    if (handle_arch(&new, obj, header, current) == 84) {
        objerror(obj, "can't create subfile informations");
        return;
    }
    if (check_elf(&new) == 84)
        return;
    print_elf(&new);
    free(new.finfo.name);
}

static void print_hdr(obj_t *obj, struct ar_hdr *header,
size_t *index, struct ar_hdr *next)
{
    for (; !header && next && !out_of_map(obj, next,
    sizeof(struct ar_hdr)) && my_strlen(next->ar_name, '/', 16) == 0;
    next = next_arch(obj, index))
        if (!strncmp(next->ar_name, "//", 2))
            header = next;
}

static void print_sub(obj_t *obj, struct ar_hdr *header,
size_t *index, struct ar_hdr *next)
{
    for (; next && !out_of_map(obj, next, sizeof(struct ar_hdr));
    next = next_arch(obj, index))
        print_subfile(obj, header, next);
}

int print_arch(obj_t *obj)
{
    struct ar_hdr *header = NULL;
    size_t index = SARMAG;
    struct ar_hdr *next = (void *)((char *)obj->finfo.vadress + index);

    printf("In archive %s:\n", obj->finfo.name);
    print_hdr(obj, header, &index, next);
    print_sub(obj, header, &index, next);
    return (0);
}
