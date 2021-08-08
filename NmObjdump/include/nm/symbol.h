/*
** EPITECH PROJECT, 2021
** symbol
** File description:
** symbol
*/

#pragma once

#include "nm.h"
#include <elf.h>

int get_symbol_list(info_t *infos);
char bind_symbol32(Elf32_Sym *sym, char *c);
char bind_symbol64(Elf64_Sym *sym, char *c);
int store_symbol32(info_t *infos, uint32_t size,
Elf32_Sym *symbols, void *strtab_p);
int store_symbol64(info_t *infos, uint32_t size,
Elf64_Sym *symbols, void *strtab_p);
