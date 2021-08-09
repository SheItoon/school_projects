/*
** EPITECH PROJECT, 2019
** int_to_str.c
** File description:
** Converts an int to str
*/

#include <stdlib.h>
#include "../include/my.h"

int sign(int nbr)
{
    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
        return (nbr);
    }
    return (nbr);
}

char *int_to_str(int nbr, char *str)
{
    int p1 = 0;
    int p2 = 0;
    int inter = 0;
    int flip = 0;

    nbr = sign(nbr);
    for (int nbr_ch = 0; nbr_ch <= nbrlen(nbr); nbr_ch++) {
        p1 = nbr % my_compute_power_rec(10, nbr_ch + 1);
        if (nbr_ch != 0)
            p2 = nbr % my_compute_power_rec(10, nbr_ch);
        else
            p2 = 0;
        inter = (p1 - p2) / my_compute_power_rec(10, nbr_ch);
        str[nbr_ch] = (inter + 48);
    }
    str[nbrlen(nbr)] = '\0';
    my_revstr(str);
    return (str);
}
