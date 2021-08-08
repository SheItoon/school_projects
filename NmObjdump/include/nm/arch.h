/*
** EPITECH PROJECT, 2021
** archi
** File description:
** archi
*/

#pragma once

#include "nm.h"
#include <elf.h>

struct ar_hdr *next_arch(info_t *info, size_t *index);
int handle_arch(info_t *info, info_t *binfo,
struct ar_hdr *names, struct ar_hdr *header);
