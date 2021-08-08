/*
** EPITECH PROJECT, 2021
** arch
** File description:
** arch
*/

#include "nm.h"
#include <ar.h>
#include "utils.h"
#include <stdlib.h>
#include <string.h>

struct ar_hdr *next_arch(info_t *info, size_t *index)
{
    struct ar_hdr *ar = (void *)((char *)(info->finfo.vadress) + *index);

    if (*index == info->finfo.size)
        return (NULL);
    if (out_of_map(info, ar, sizeof(struct ar_hdr)))
        return (NULL);
    *index += atol(ar->ar_size) + sizeof(struct ar_hdr);
    if (out_of_map(info, (char *)info->finfo.vadress + *index, 0))
        return (NULL);
    return ((void *)((char *)info->finfo.vadress + *index));
}

int handle_arch(info_t *info, info_t *binfo,
struct ar_hdr *names, struct ar_hdr *header)
{
    int len = my_strlen(header->ar_name, '/', 16);
    void *tmp;
    void *end = (void *)((char *)binfo->finfo.vadress + binfo->finfo.size);

    if (len || names == 0)
        info->finfo.name = strndup(header->ar_name, len);
    else {
        tmp = (void *)((char *)(names + sizeof(struct ar_hdr) +
        atoll(header->ar_name + 1)));
        if (out_of_map(info, tmp, 0))
            return (84);
        len = my_strlen(tmp, '/', -1);
        info->finfo.name = strndup(tmp, len);
    }
    info->finfo.size = (size_t)atoll(header->ar_size);
    if ((void *)(info->finfo.size +
    (char *)header + sizeof(struct ar_hdr)) > end)
        info->finfo.size = (size_t)end - ((size_t) header +
        sizeof(struct ar_hdr));
    info->finfo.vadress = (void *)((char *)header + sizeof(struct ar_hdr));
    return (0);
}
