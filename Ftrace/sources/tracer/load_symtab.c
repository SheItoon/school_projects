/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** load_symtab
*/

#include "ftrace.h"
#include "tracer.h"
#include <string.h>
#include <elf.h>
#include <fcntl.h>
#include <gelf.h>
#include <libelf.h>
#include <link.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
#include <sys/types.h>

static sym_t *append_new_function(sym_t *result, char *name,
unsigned long long addr)
{
    sym_t *new = malloc(sizeof(sym_t));
    sym_t *tmp = result;

    new->addr = addr;
    new->func_name = strdup(name);
    new->next = 0x0;
    new->prev = 0x0;
    if (!result)
        return new;
    for (; tmp->next != 0x0; tmp = tmp->next);
    new->prev = tmp;
    tmp->next = new;
    return result;
}

static sym_t *get_symtab_content(Elf *elf, GElf_Shdr *shdr, Elf_Scn *scn)
{
    Elf_Data *data = malloc(sizeof(Elf_Data));
    int nb_symbols = shdr->sh_size / shdr->sh_entsize;
    GElf_Sym *sym = malloc(sizeof(GElf_Sym));
    int st_type = 0;
    char *func_name = 0x0;
    sym_t *result = 0x0;

    data = elf_getdata(scn, 0x0);
    sym = (!data) ? 0x0 : (GElf_Sym *)data->d_buf;
    if (!data || !sym) return 0x0;
    for (int i = -1; ++i < nb_symbols; ) {
        st_type = GELF_ST_TYPE(sym[i].st_info);
        if (st_type == STT_FUNC || st_type == STT_NOTYPE) {
            func_name = elf_strptr(elf, shdr->sh_link, sym[i].st_name);
            if (func_name && func_name[0] != '_')
                result = append_new_function(result,
                func_name, sym[i].st_value);
        }
    }
    return result;
}

__attribute__ ((unused)) static void display_symtab(sym_t *s)
{
    sym_t *tmp = s;

    if (!s)
        return;
    for (size_t ctr = 0; tmp->next != 0x0; tmp = tmp->next, ctr++)
        printf("[%ld] %s@%#llx\n", ctr, tmp->func_name, tmp->addr);
}

sym_t *load_symtab(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    Elf * elf = (fd == -1) ? 0x0 : elf_begin(fd, ELF_C_READ, 0x0);
    Elf_Scn *scn = 0x0;
    GElf_Shdr *shdr = malloc(sizeof(GElf_Shdr));
    sym_t *result = 0x0;

    if (!elf)
        return 0x0;
    scn = elf_nextscn(elf, scn);
    while (scn) {
        if (gelf_getshdr(scn, shdr) == 0x0)
            break;
        if (shdr->sh_type == SHT_SYMTAB || shdr->sh_type == SHT_DYNSYM)
            result = get_symtab_content(elf, shdr, scn);
        scn = elf_nextscn(elf, scn);
    }
    return result;
}
