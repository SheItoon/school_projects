/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

int my_is_prime(int nb)
{
    int x = 2;

    while (x < nb) {
        if (nb % x == 0)
            return (0);
        x++;
    }
    return (1);
}
