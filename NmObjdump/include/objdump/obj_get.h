/*
** EPITECH PROJECT, 2021
** get
** File description:
** get
*/

#pragma once

#include <elf.h>
#include "objdump.h"

char *get_section_name64(obj_t *obj, Elf64_Shdr *shead);
char *get_section_name32(obj_t *obj, Elf32_Shdr *shead);
Elf32_Shdr *get_sheader32(obj_t *obj);
Elf64_Shdr *get_sheader64(obj_t *obj);
