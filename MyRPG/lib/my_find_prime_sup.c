/*
** EPITECH PROJECT, 2019
** find prime
** File description:
** afezfz
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    while (1)
    {
        if (my_is_prime(nb) == 1)
            return (nb);
        nb++;
    }
}
