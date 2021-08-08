/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-ftrace-bogdan.guillemoles
** File description:
** elf_parsing
*/

#include "ftrace.h"
#include <fcntl.h>
#include <libelf.h>
#include <elf.h>
#include <stdio.h>

static const char *check_elf_format(int fd, user_input_t *user)
{
    if (elf_version(EV_CURRENT) == EV_NONE)
        return "elf initialisation";
    if ((user->elf_object = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
        return "elf begin failure";
    if (elf_kind(user->elf_object) != ELF_K_ELF)
        return "is not an elf object";
    return NULL;
}

static bool elf_error_handling(char *filepath, user_input_t *user)
{
    const char *err = NULL;
    int fd = open(filepath, O_RDONLY, 0);

    if (fd == -1) {
        perror("open");
        return true;
    }
    if ((err = check_elf_format(fd, user)) != NULL)
        dprintf(2, "%s\n", err);
    close(fd);
    return (err ? true : false);
}

inline bool get_elf_object(char *filepath, user_input_t *user)
{
    return !elf_error_handling(filepath, user);
}

bool is_64_bits(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    Elf *elf = (fd == -1) ? 0x0 : elf_begin(fd, ELF_C_READ, 0x0);
    const char *e_ident = (elf) ? elf_getident(elf, 0x0) : 0x0;
    bool result = false;

    close(fd);
    if (!e_ident)
        return false;
    result = (e_ident[EI_CLASS] == ELFCLASS64) ? true : false;
    elf_end(elf);
    return result;
}
