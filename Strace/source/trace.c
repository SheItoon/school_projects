/*
** EPITECH PROJECT, 2021
** trace
** File description:
** trace
*/

#include "strace.h"

int trace(pid_t pid, int mode)
{
    struct user_regs_struct r;
    unsigned short instr_code;
    int wait;

    waitpid(pid, &wait, 0);
    while (status_handler(wait))
        process_status(&pid, &wait, &r, &instr_code, mode);
    return (wait);
}
