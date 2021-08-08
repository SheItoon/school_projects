/*
** EPITECH PROJECT, 2021
** arch
** File description:
** arch
*/

#pragma once

#include <ar.h>
#include "objdump.h"

struct ar_hdr *next_arch(obj_t *obj, size_t *index);
int handle_arch(obj_t *obj, obj_t *bobj,
struct ar_hdr *names, struct ar_hdr *header);
