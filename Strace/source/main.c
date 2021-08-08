/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "strace.h"

int main(int ac, char **av)
{
    char *quote = "Usage : %s [-s] [-p <pid>|<command>]\n";

    if (ac < 2)
        return (fprintf(stderr, quote, av[0]) || 1);
    return (strace_engine(ac, av));
}
