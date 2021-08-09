/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return first nbr of chain
*/

#include <stdio.h>
#include "../include/my.h"

int nubr_trier(char n)
{
    if (n < 59 && n > 47)
        return (1);
    else
        return (0);
}
int signe(int memorie, char const *chain)
{
    if (memorie == 0)
        return (1);
    if (chain[memorie - 1] == 45)
        return (-1);
    return (1);
}

int my_getnbr(char const *chain)
{
    int memo = 0;
    int stock = 0;
    int memorie = 0;
    int y = 0;

    for (int x = 0; chain[x] != '\0'; x++) {
        memo = nubr_trier(chain[x]);
        if (memo == 1 && y == 1) {
            stock = stock * 10;
            stock = stock + chain[x] - 48;
        }else if (y == 1 && memo == 0)
            return (stock * signe(memorie, chain));
        if (memo == 1 && y == 0) {
            stock = stock + chain[x] - 48;
            y = 1;
            memorie = x;
        }
    }
    return (stock * signe(memorie, chain));
}
