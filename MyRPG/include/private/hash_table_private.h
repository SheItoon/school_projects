/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef HASH_TABLE_PRIVATE_H_INCLUDED
#define HASH_TABLE_PRIVATE_H_INCLUDED

#include "hash_table.h"

hash_value_t hash_str_data(cchar_t str, uint_t len);
void free_item_content(ht_item_t *item, destructor_ft destroy);
void *map_erase_element(list_t *, iterator_t, hash_value_t, dsize_t);

#endif
