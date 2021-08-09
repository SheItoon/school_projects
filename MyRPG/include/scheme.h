/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef SCHEME_H_INCLUDED
#define SCHEME_H_INCLUDED

#include <SFML/Graphics.h>
#include "istl/common_types.h"
#include "decoration.h"
#include "scene.h"

typedef enum TILE_TYPE {
    T_EMPTY = 0,            // 1 4
    T_LABWALLBLOOD_1,       // 0 1
    T_LABWALLBLOOD_2,       // 3 1
    T_LABWALLRIFT_1,        // 2 1
    T_LABWALLRIFT_2,        // 4 1
    T_LABWALL,              // 1 1
    T_FLOOROFFICE_1,        // 4 2
    T_FLOOROFFICE_2,        // 6 2
    T_FLOOROFFICE_3,        // 5 3
    T_FLOOROFFICE_4,        // 6 3
    T_FLOOROFFICEBLOOD_1,   // 5 2
    T_FLOOROFFICEBLOOD_2,   // 4 3
    T_OFFWALL_1,            // 5 1
    T_DARKLAB,              // 3 2
    T_IRONWALL,             // 4 0
    T_IRONWALLSCRATCH_1,    // 5 0
    T_IRONWALLSCRATCH_2,    // 6 0
    T_DARKLABWALL,          // 1 0
    T_DARKLABWALLBLOOD_1,   // 0 0
    T_DARKLABWALLBLOOD_2,   // 2 0
    T_PURPLEWALLOFFICE_1,   // 5 1
    T_PURPLEWALLOFFICE_2,   // 6 1
    T_GRAYWALLOFFICE_1,     // 0 2
    T_GRAYWALLOFFICE_2,     // 1 2
    T_LABFLOOR,             // 0 3
    T_LABFLOORRIFT,         // 1 3
    T_LABFLOORBLOOD,        // 4 3
    T_LABFLOORRIFTBLOOD,    // 2 3
    T_CONCRETE              // 2 2
} (tdata_t);

typedef struct GridScheme (scheme_t);

extern const mdata_t MB_SCHEME;

scheme_t *scheme_create(int **, uint_t w, uint_t h);
int scheme_unpack(scheme_t const *, scene_t *);
void scheme_free(scheme_t **);
void scheme_destroy(void *);
void *scheme_copy(void const *);
decor_t *scheme_translate(scheme_t const *, int);
decor_t *scheme_translate2(scheme_t const *, int);
void decor_toggle_dec(scheme_t *);

#endif
