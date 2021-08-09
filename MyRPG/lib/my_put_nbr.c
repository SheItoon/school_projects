/*
** EPITECH PROJECT, 2019
** sense
** File description:
** 
*/

#include "../include/my.h"

int sense(int nbr)
{
    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    if (nbr == 0)
          my_putchar('0');
    return (nbr);
}

void my_put_nbr(int nbr)
{
    int p1 = 0;
    int p2 = 0;
    int inter = 0;
    int flip = 0;

    nbr = sense(nbr);
    for (int nbr_ch = nbrlen(nbr); nbr_ch >= 0; nbr_ch--) {
        p1 = nbr % my_compute_power_rec(10, nbr_ch + 1);
        if (nbr_ch != 0)
            p2 = nbr % my_compute_power_rec(10, nbr_ch);
        else
            p2 = 0;
        inter = (p1 - p2) / my_compute_power_rec(10, nbr_ch);
        if (flip == 1)
            my_putchar(inter + 48);
        flip = 1;
    }
}
