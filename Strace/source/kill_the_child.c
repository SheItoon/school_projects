/*
** EPITECH PROJECT, 2021
** child
** File description:
** child
*/

#include "strace.h"

int attach_process(pid_t pid)
{
    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
        return (perror("Ptrace attach: "), 1);
    return (0);
}

int launch_kid(int ac, char **av, int mode)
{
    char *array[ac + 1];
    int i;

    for (i = 0; i < ac; i++)
        array[i] = av[i + 1 + mode];
    array[i] = NULL;
    ptrace(PTRACE_TRACEME);
    kill(getpid(), SIGSTOP);
    if (execvp(av[1 + mode], array) == -1)
        return (1);
    return (0);
}
