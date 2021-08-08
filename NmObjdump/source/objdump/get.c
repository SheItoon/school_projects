/*
** EPITECH PROJECT, 2021
** get
** File description:
** get
*/

#include <elf.h>
#include "obj_get.h"
#include "objdump.h"
#include "obj_utils.h"

char *get_section_name32(obj_t *obj, Elf32_Shdr *shead)
{
    Elf32_Shdr *rshead = get_sheader32(obj);
    Elf32_Shdr *sh_strtab;
    char *sh_strtab_p;

    if (out_of_map(obj, shead, sizeof(Elf32_Shdr)) || rshead == NULL)
        return (NULL);
    sh_strtab = rshead +
    ((Elf32_Ehdr *)obj->finfo.vadress)->e_shstrndx;
    if (out_of_map(obj, sh_strtab, sizeof(Elf32_Shdr)))
        return (NULL);
    sh_strtab_p = (char *)obj->finfo.vadress + sh_strtab->sh_offset;
    if (out_of_map(obj, sh_strtab_p, sh_strtab->sh_size) &&
    sh_strtab->sh_size > shead->sh_name)
        return (NULL);
    return (sh_strtab_p + shead->sh_name);
}

char *get_section_name64(obj_t *obj, Elf64_Shdr *shead)
{
    Elf64_Shdr *rshead = get_sheader64(obj);
    Elf64_Shdr *sh_strtab;
    char *sh_strtab_p;

    if (out_of_map(obj, shead, sizeof(Elf64_Shdr)) || rshead == NULL)
        return (NULL);
    sh_strtab = rshead +
    ((Elf64_Ehdr *)obj->finfo.vadress)->e_shstrndx;
    if (out_of_map(obj, sh_strtab, sizeof(Elf64_Shdr)))
        return (NULL);
    sh_strtab_p = (char *)obj->finfo.vadress + sh_strtab->sh_offset;
    if (out_of_map(obj, sh_strtab_p, sh_strtab->sh_size) &&
    sh_strtab->sh_size > shead->sh_name)
        return (NULL);
    return (sh_strtab_p + shead->sh_name);
}

Elf32_Shdr *get_sheader32(obj_t *obj)
{
    void *head = (void *)((char *)(obj->finfo.vadress)
    + ((Elf32_Ehdr *)obj->finfo.vadress)->e_shoff);

    if (out_of_map(obj, head, sizeof(Elf32_Shdr)))
        return (NULL);
    return (head);
}

Elf64_Shdr *get_sheader64(obj_t *obj)
{
    void *head = (void *)((char *)(obj->finfo.vadress)
    + ((Elf64_Ehdr *)obj->finfo.vadress)->e_shoff);

    if (out_of_map(obj, head, sizeof(Elf64_Shdr)))
        return (NULL);
    return (head);
}
