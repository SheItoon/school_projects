/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-strace-bogdan.guillemoles
** File description:
** trace_handler
*/

#include "ftrace.h"
#include "tools.h"
#include "tracer.h"
#include <asm/unistd_64.h>
#include <bits/types/siginfo_t.h>
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
#include <errno.h>
#include "display.h"
#include <sys/reg.h>

static void set_user_options(user_input_t *usr, int *wait_status)
{
    usr->is_32_bits = !is_64_bits(usr->args[0]);
    usr->function_symbols = load_symtab(usr->args[0]);
    waitpid(usr->ppid, wait_status, 0);
    if (ptrace(PTRACE_SETOPTIONS, usr->ppid, 0,
    get_ptrace_opt(*usr)) < 0) {
        perror("setoptions");
        elf_end(usr->elf_object);
        _exit(ERROR);
    }
}

static user_input_t peek_text(pid_t pid, user_input_t usr,
struct user_regs_struct rgs)
{
    unsigned short code = ptrace(PTRACE_PEEKTEXT, pid, rgs.rip, 0);
    long long unsigned int max_scalls = MAX_NB_SYSCALLS(usr.is_32_bits);

    if (is_syscall(code) && rgs.orig_rax < max_scalls) {
        display_syscall_wrapper(&usr, rgs);
        return usr;
    } else return check_relative_functions(code, usr, rgs);
}

struct user_regs_struct get_regs(pid_t pid)
{
    struct user_regs_struct result;

    if (ptrace(PTRACE_GETREGS, pid, 0x0, &result) == -1) {
        perror("getregs");
        _exit(ERROR);
    } else return result;
}

siginfo_t *peek_signal(pid_t pid)
{
    siginfo_t *result = malloc(sizeof(siginfo_t));

    if (!result || ptrace(PTRACE_GETSIGINFO, pid, 0, result))
        return 0x0;
    else if (result->si_signo != SIGTRAP && result->si_code != SIGSTOP)
        return result;
    free(result);
    return 0x0;
}

int trace_loop(user_input_t usr)
{
    int ws = 0;
    siginfo_t *sig;
    struct user_regs_struct regs = { .orig_rax = 0 };

    set_user_options(&usr, &ws);
    while (is_stopped(ws) && !should_exit(regs.orig_rax, usr.is_32_bits)) {
        if (ptrace(PTRACE_SINGLESTEP, usr.ppid, 0, 0) == -1)
            return 84;
        waitpid(usr.ppid, &ws, 0);
        regs = get_regs(usr.ppid);
        usr = peek_text(usr.ppid, usr, regs);
        sig = peek_signal(usr.ppid);
        if (sig) {
            display_sig(usr, sig);
            free(sig);
        }
    }
    return 0;
}
