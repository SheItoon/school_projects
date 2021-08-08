/*
** EPITECH PROJECT, 2021
** nm
** File description:
** nl
*/

#pragma once

#include <stdio.h>

typedef struct node_s {
    char *name;
    void *value;
    char type;
    struct node_s *next;
} node_t;

typedef node_t *list_t;

typedef struct file_s {
    char *name;
    void *vadress;
    size_t size;
    size_t arch;
    list_t sym_links;
} file_t;

typedef struct info_s {
    file_t finfo;
    char *name;
    int nms;
} info_t;

int nm(info_t *info);
int nms(int ac, char **av, info_t *infos);
int nm_engine(int ac, char **av);
