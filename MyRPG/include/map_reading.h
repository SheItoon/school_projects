/*
** EPITECH PROJECT, 2020
** defender
** File description:
** .h for the function read map with a file
*/

#ifndef MAP_READING_H
#define MAP_READING_H
char *reading_map(char const *path);
int count_col(char *buf);
int count_lign(char *buf);
char *aloc_nbr_select(char *buf);
int **map_nbr_create(char *buf);
int **creat_int_map(char *buf);



#endif
