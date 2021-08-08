/*
** EPITECH PROJECT, 2021
** objdump
** File description:
** obj
*/

#pragma once

#include <stdlib.h>

typedef struct file_s {
    char *name;
    void *vadress;
    size_t size;
    size_t arch;
} file_t;

typedef struct obj_s {
    file_t finfo;
    char *name;
} obj_t;

int objdumps(obj_t *obj, int ac, char **av);
int objdump(obj_t *obj);
int obj_engine(int ac, char **av);
