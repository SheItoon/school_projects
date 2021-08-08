/*
** EPITECH PROJECT, 2021
** arch
** File description:
** arch
*/

#include <ar.h>
#include <string.h>
#include "objdump.h"
#include "obj_utils.h"

struct ar_hdr *next_arch(obj_t *obj, size_t *index)
{
    struct ar_hdr *ar = (void *)((char *)(obj->finfo.vadress) + *index);

    if (*index == obj->finfo.size)
        return (NULL);
    if (out_of_map(obj, ar, sizeof(struct ar_hdr)))
        return (NULL);
    *index += atol(ar->ar_size) + sizeof(struct ar_hdr);
    if (out_of_map(obj, (char *)obj->finfo.vadress + *index, 0))
        return (NULL);
    return ((void *)((char *)obj->finfo.vadress + *index));
}

int handle_arch(obj_t *obj, obj_t *bobj,
struct ar_hdr *names, struct ar_hdr *header)
{
    int len = my_strlen(header->ar_name, '/', 16);
    void *tmp;
    void *end = (void *)((char *)bobj->finfo.vadress + bobj->finfo.size);

    if (len || names == 0)
        obj->finfo.name = strndup(header->ar_name, len);
    else {
        tmp = (void *)((char *)(names + sizeof(struct ar_hdr) +
        atoll(header->ar_name + 1)));
        if (out_of_map(obj, tmp, 0))
            return (84);
        len = my_strlen(tmp, '/', -1);
        obj->finfo.name = strndup(tmp, len);
    }
    obj->finfo.size = (size_t)atoll(header->ar_size);
    if ((void *)(obj->finfo.size +
    (char *)header + sizeof(struct ar_hdr)) > end)
        obj->finfo.size = (size_t)end - ((size_t)header +
        sizeof(struct ar_hdr));
    obj->finfo.vadress = (void *)((char *)header + sizeof(struct ar_hdr));
    return (0);
}
