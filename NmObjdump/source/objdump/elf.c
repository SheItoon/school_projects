/*
** EPITECH PROJECT, 2021
** elf
** File description:
** elf
*/

#include <elf.h>
#include "objdump.h"

size_t elfheader_size(size_t arch)
{
    if (arch == ELFCLASS32)
        return (sizeof(Elf32_Ehdr));
    else
        return (sizeof(Elf64_Ehdr));
}
