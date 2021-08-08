/*
** EPITECH PROJECT, 2021
** status
** File description:
** status
*/

#include "strace.h"

int status_handler(int wait)
{
    return ((WSTOPSIG(wait) == SIGTRAP || WSTOPSIG(wait) == SIGSTOP)
    && WIFSTOPPED(wait));
}

void process_status(pid_t *pid, int *wait,
struct user_regs_struct *r, unsigned short *code, int mode)
{
    if (ptrace(PTRACE_GETREGS, *pid, NULL, r))
        perror("ptrace");
    *code = ptrace(PTRACE_PEEKTEXT, *pid, r->rip, NULL);
    if (ptrace(PTRACE_SINGLESTEP, *pid, NULL, NULL) == -1)
        perror("ptrace");
    waitpid(*pid, wait, 0);
    if (status_handler(*wait)) {
        if (ptrace(PTRACE_GETREGS, *pid, NULL, r))
            perror("ptrace");
        if (*code == SYSCALL_CODE)
            print_syscall(*pid, r->orig_rax, r->rax, mode);
    }
}
