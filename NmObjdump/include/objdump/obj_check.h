/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#pragma once

#include <elf.h>
#include "objdump.h"

int check_arch(obj_t *obj);
int check_elf(obj_t *obj);
int check_basic(obj_t *obj, Elf64_Ehdr *elf);
