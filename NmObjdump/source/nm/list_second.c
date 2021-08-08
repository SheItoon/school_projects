/*
** EPITECH PROJECT, 2021
** list
** File description:
** list
*/

#include <zconf.h>
#include <malloc.h>
#include <memory.h>
#include "list.h"

void swap(list_t a, list_t b)
{
    void *lista_value = a->value;
    void *lista_name = a->name;

    a->value = b->value;
    a->name = b->name;
    b->value = lista_value;
    b->name = lista_name;
}
