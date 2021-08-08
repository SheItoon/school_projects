/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#pragma once

#include "nm.h"
#include <elf.h>

int check_arch(info_t *info);
int check_elf(info_t *info);
int check_other_elf(info_t *info, Elf64_Ehdr *elf);
