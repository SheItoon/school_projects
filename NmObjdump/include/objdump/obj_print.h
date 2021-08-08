/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#pragma once

#include "objdump.h"

int arch_printing(obj_t *obj, int *ret);
int elf_printing(obj_t *obj, int *ret);
int print_arch(obj_t *obj);
int print_elf(obj_t *obj);
int print_header(obj_t *obj);
int print_section(obj_t *obj);
int print_section64(obj_t *obj);
int print_section32(obj_t *obj);
int print_header64(obj_t *obj);
int print_header32(obj_t *obj);
int print_hexa(unsigned char *section, size_t addr, size_t  size);
void print_flags(size_t flags);
