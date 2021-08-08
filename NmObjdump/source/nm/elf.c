/*
** EPITECH PROJECT, 2021
** elf
** File description:
** elf
*/

#include "nm.h"
#include <elf.h>
#include <string.h>
#include "utils.h"
#include "get_func.h"

Elf32_Shdr *elf_get_sheader32(info_t *infos)
{
    void *head = (void *)((char *)(infos->finfo.vadress)
    + ((Elf32_Ehdr *) infos->finfo.vadress)->e_shoff);

    if (out_of_map(infos, head, sizeof(Elf32_Shdr)))
        return (NULL);
    return (head);
}

Elf64_Shdr *elf_get_sheader64(info_t *infos)
{
    void *head = (void *)((char *)(infos->finfo.vadress)
    + ((Elf64_Ehdr *) infos->finfo.vadress)->e_shoff);

    if (out_of_map(infos, head, sizeof(Elf64_Shdr)))
        return (NULL);
    return (head);
}

size_t elfheader_size(size_t arch)
{
    switch (arch) {
    case (ELFCLASS32):
        return (sizeof(Elf32_Ehdr));
    default:
        return (sizeof(Elf64_Ehdr));
    }
}

Elf32_Shdr *elf_get_section32(info_t *info, char const *sname)
{
    Elf32_Ehdr *eheader = info->finfo.vadress;
    Elf32_Shdr *sheader = elf_get_sheader32(info);
    void *section = NULL;
    size_t sh_size;
    char *cname;

    if (sheader == NULL || (void *)sheader == (void *)eheader ||
    (!sheader->sh_size && !eheader->e_shnum) ||
    eheader->e_shstrndx == SHN_UNDEF)
        return (NULL);
    sh_size = !sheader->sh_size ? eheader->e_shnum : sheader->sh_size;
    for (size_t i = 0; i < sh_size; i++) {
        cname = get_name32(info, sheader + i);
        if (cname && !strcmp(sname, cname)) {
            section = sheader + i;
            break;
        }
    }
    return (section);
}

Elf64_Shdr *elf_get_section64(info_t *info, char const *sname)
{
    Elf64_Ehdr *eheader = info->finfo.vadress;
    Elf64_Shdr *sheader = elf_get_sheader64(info);
    void *section = NULL;
    size_t sh_size;
    char *cname;

    if (sheader == NULL || (void *)sheader == (void *)eheader ||
    (!sheader->sh_size && !eheader->e_shnum) ||
    eheader->e_shstrndx == SHN_UNDEF)
        return (NULL);
    sh_size = !sheader->sh_size ? eheader->e_shnum : sheader->sh_size;
    for (size_t i = 0; i < sh_size; i++) {
        cname = get_name64(info, sheader + i);
        if (cname && !strcmp(sname, cname)) {
            section = sheader + i;
            break;
        }
    }
    return (section);
}
