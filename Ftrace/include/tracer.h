/*
** EPITECH PROJECT, 2021
** TRACER_H
** File description:
** tracer
*/

#ifndef TRACER_H
#define TRACER_H

#include "ftrace.h"
#include <bits/types/siginfo_t.h>
#include <sys/types.h>
#include <sys/user.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/reg.h>
#include <stdio.h>

/*
    Found in /usr/include/asm/unistd_(32/64).h
*/

#define _EXECVE_64_BITS     (59)
#define _EXECVE_32_BITS     (11)

#define _EXIT_64_BITS       (60)
#define _EXIT_GRP_64_BITS   (231)

#define _EXIT_32_BITS       (1)
#define _EXIT_GRP_32_BITS   (252)

// setup_ptrace.c
int setup_ptrace(user_input_t);

// trace_loop.c
siginfo_t *peek_signal(pid_t);
struct user_regs_struct get_regs(pid_t);
int trace_loop(user_input_t);

// trace_helper.c
void display_syscall_wrapper(user_input_t *, struct user_regs_struct);
bool should_exit(unsigned long long, bool);
int get_ptrace_opt(user_input_t);
bool is_stopped(int);

// relative_functions.c
user_input_t handle_func_entering(struct user_regs_struct, user_input_t);
user_input_t handle_func_exit(user_input_t usr);
user_input_t check_relative_functions(unsigned short code, user_input_t usr,
struct user_regs_struct regs);

//load_symtab.c
sym_t *load_symtab(char const *);

#endif /* TRACER_H */
