/*
** EPITECH PROJECT, 2019
** power
** File description:
** recusive
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    for (int i; my_compute_power_rec(i, 2) <= nb; i++){
        if (my_compute_power_rec(i, 2) == nb)
            return (i);
        if (my_compute_power_rec(i, 2) > nb)
            return (0);
    }
    return (0);
}
