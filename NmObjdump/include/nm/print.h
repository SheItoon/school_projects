/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#pragma once

#include "nm.h"

int print_file(file_t *info, int multi);
int print_arch(info_t *info);
int print_elf(info_t *info);
char print_type32(info_t *info, node_t *node);
char print_type64(info_t *info, node_t *node);
void print_syms32(file_t *info);
void print_syms64(file_t *info);
