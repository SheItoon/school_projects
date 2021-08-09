/*
** EPITECH PROJECT, 2019
** another one
** File description:
** aaaaaaaaaaa
*/

#include "my_world.h"

int number_digits(int nbr)
{
    int n = 1;
    int pow = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= pow) {
        n++;
        if (pow > 214748364)
            break;
        pow *= 10;
    }
    return (n);
}

char *get_score(int nbr)
{
    int len = number_digits(nbr);
    char *result;

    result = malloc(sizeof(char) * len + 1); 
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}
