/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#pragma once

#include "nm.h"

int my_munmap(info_t *info, int ret);
int out_of_map(info_t *info, void *addr, size_t len);
int nmerror(info_t *infos, char const *str);
int nmserror(info_t *infos, char const *str);
int nm_printable(size_t x);
int my_strlen(void *ptr, char c, int max);
int my_strcmp(char *a, char *b);
void clear(info_t *info);
int loop_type(info_t *info, list_t n);
info_t *init(char **av);
