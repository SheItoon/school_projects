/*
** EPITECH PROJECT, 2021
** list
** File description:
** list
*/

#include <zconf.h>
#include <malloc.h>
#include <memory.h>
#include "nm.h"
#include "list.h"
#include "utils.h"

void list_clear(list_t *list)
{
    list_t old_tmp = NULL;
    list_t tmp = *list;

    while (tmp) {
        old_tmp = tmp;
        tmp = tmp->next;
        free(old_tmp);
    }
    *list = NULL;
}

int list_push(list_t *head, void *elem)
{
    list_t new = malloc(sizeof(node_t));

    if (new == NULL)
        return (0);
    memset(new, 0, sizeof(node_t));
    new->next = *head;
    new->value = elem;
    *head = new;
    return (84);
}

static void try_swap(list_t lista, list_t listb, int *sorted)
{
    if (my_strcmp(lista->name, listb->name) > 0) {
        *sorted = 1;
        swap(lista, listb);
    }
}

static void swap_elem(list_t lista, list_t listb, int *sorted)
{
    while (lista && listb) {
        try_swap(lista, listb, sorted);
        lista = lista->next;
        listb = listb->next;
    }
}

void list_sort(list_t list)
{
    int sorted = 1;
    list_t tmp1;
    list_t tmp2;

    while (sorted) {
        sorted = 0;
        tmp1 = list;
        tmp2 = list;
        if (tmp2)
            tmp2 = tmp2->next;
        swap_elem(tmp1, tmp2, &sorted);
    }
}
