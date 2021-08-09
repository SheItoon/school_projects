/*
** EPITECH PROJECT, 2020
** normal
** File description:
** normal
*/

#include <SFML/Window.h>

#pragma once

#include "combo_struct.h"
#include <stdlib.h>
#include <string.h>

void normal_func(combo_t *data, sfEvent event);
int add_to_string(combo_t *data, char var);
int reset(combo_t *data);
int parse_shrek(combo_t *data, char key);
void my_putshrek(void);
