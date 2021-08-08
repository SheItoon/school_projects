/*
** EPITECH PROJECT, 2021
** engine
** File description:
** engine
*/

#include "strace.h"

int strace_engine(int ac, char **av)
{
    char *quote = "Invalid option for -s\n";
    int mode = 0;
    pid_t pid;

    if (!strcmp(av[1], "-s"))
        mode = 1;
    if (av[1 + mode] && !strcmp(av[1 + mode], "-p") && av[2 + mode]) {
        if (attach_process((pid = (pid_t)atoi(av[2 + mode]))))
            return (1);
    } else {
        if (!av[1 + mode])
            return (fprintf(stderr, quote) || 1);
        pid = fork();
        if (pid == 0)
            return (launch_kid(ac, av, mode));
    }
    return (print_exit(trace(pid, mode), mode));
}
