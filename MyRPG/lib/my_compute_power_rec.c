/*
** EPITECH PROJECT, 2019
** power
** File description:
** get more power
*/

int my_compute_power_rec(int nb, int p)
{
    int total = 1;

    if (p < 0)
        return (0);
    if (p == 0){
        return (total);
    }else {
        total = nb * my_compute_power_rec(nb, p - 1);
    }
    return (total);
}
