/*
** EPITECH PROJECT, 2019
** nbrlen
** File description:
** compt nbr carcte in int
*/

int nbrlen(int nbr)
{
    int x = 0;
    int test = nbr;

    if (nbr < 0) {
        test = test * (-1);
        x = 1;
    }
    while (test > 0) {
        test = test / 10;
        x++;
    }
    return (x);
}
