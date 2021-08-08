/*
** EPITECH PROJECT, 2021
** elf
** File description:
** elf
*/

#pragma once

#include "nm.h"

size_t elfheader_size(size_t arch);
Elf32_Shdr *elf_get_sheader32(info_t *infos);
Elf64_Shdr *elf_get_sheader64(info_t *infos);
Elf32_Shdr *elf_get_section32(info_t *info, char const *sname);
Elf64_Shdr *elf_get_section64(info_t *info, char const *sname);
