/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#pragma once

#include "objdump.h"

int out_of_map(obj_t *obj, void *addr, size_t len);
int my_munmap(obj_t *obj, int ret);
int objserror(obj_t *obj, char const *str);
int objerror(obj_t *obj, char const *str);
int my_strlen(void *ptr, char c, int max);
int blacklist(char *str);
void clear(obj_t *obj);
