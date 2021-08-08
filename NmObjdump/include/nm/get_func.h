/*
** EPITECH PROJECT, 2021
** fun
** File description:
** fun
*/

#pragma once

#include <elf.h>

int get_basic32(Elf32_Sym *sym, char *c);
int get_basic64(Elf64_Sym *sym, char *c);
char get_special32(Elf32_Shdr *sym, char *c);
char get_special64(Elf64_Shdr *sym, char *c);
char get_bits32(Elf32_Shdr *sym, char *c);
char get_bits64(Elf64_Shdr *sym, char *c);
int get_type(info_t *info);
char *get_name32(info_t *infos, Elf32_Shdr *shead);
char *get_name64(info_t *infos, Elf64_Shdr *shead);
int get_other_bits32(Elf32_Shdr *sym, char *c);
int get_other_bits64(Elf64_Shdr *sym, char *c);
