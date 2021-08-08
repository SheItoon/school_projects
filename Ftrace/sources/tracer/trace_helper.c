/*
** EPITECH PROJECT, 2021
** strace
** File description:
** trace_helper
*/


#include "tracer.h"
#include "display.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <asm/unistd_64.h>
#include <errno.h>
#include <sys/reg.h>

void display_syscall_wrapper(user_input_t *usr, struct user_regs_struct regs)
{
    if (usr->execve_started) {
        display_sys(*usr, (int)regs.orig_rax, regs);
        return;
    } if (usr->is_32_bits && regs.orig_rax == _EXECVE_32_BITS) {
        usr->execve_started = true;
        fprintf(usr->out, "Entering function main at %#llx\n", regs.rip);
        return;
    } if (!usr->is_32_bits && regs.orig_rax == _EXECVE_64_BITS) {
        fprintf(usr->out, "Entering function main at %#llx\n", regs.rip);
        usr->execve_started = true;
        return;
    }
}

inline bool is_stopped(int wait_status)
{
    return ((WSTOPSIG(wait_status) == SIGTRAP
    || WSTOPSIG(wait_status) == SIGSTOP) && WIFSTOPPED(wait_status));
}

inline int get_ptrace_opt(user_input_t user_opt)
{
    int result = PTRACE_O_TRACESYSGOOD | PTRACE_O_TRACEEXIT;

    result |= PTRACE_O_EXITKILL;
    if (user_opt.output_options & FOLLOW_FORKS)
        result |= PTRACE_O_TRACEFORK;
    return result;
}

inline bool should_exit(unsigned long long rax, bool is_32_bits)
{
    if (is_32_bits)
        return (rax == _EXIT_32_BITS || rax == _EXIT_GRP_32_BITS);
    else return (rax == _EXIT_64_BITS || rax == _EXIT_GRP_64_BITS);
}
