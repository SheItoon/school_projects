/*
** EPITECH PROJECT, 2021
** DISPLAY_H
** File description:
** display
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <bits/types/siginfo_t.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/user.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/user.h>

#include "tools.h"
#include "ftrace.h"

/*
    README:
    the display() function is really a wrapper around fprintf,
    but it expects somewhat different flags:
        - u -> unsigned number (assumes unsigned long long)
        - d -> number (assumes int)
        - p -> pointer
        - s -> string
        - a -> string array
        - t -> structure (for now, it is always displayed as an addr) //TODO
        - l -> long (assumes long long)

    The thing is, this wrapper will handle outfiles, and various output
    options so you don't have to worry about this.

    RETURN: SUCCESS (0) if succesfull, ERROR (84) if not
*/

#define NB_AUTHORIZED_FLAGS     (7)
#define AUTHORIZED_FLAGS        ("updatls")

#define UNSIGNED                ('u')
#define POINTER                 ('p')
#define NUMBER                  ('d')
#define STR_ARRAY               ('a')
#define STRUCT                  ('t')
#define LONG                    ('l')
#define STRING                  ('s')

#define SIZE                    (128)

// disp_api.c
int display(user_input_t user, char *str, ...);

#define SYSCALL_MAX_NB_ARGS     (6)

// disp_syscalls.c
int display_sys(user_input_t user, int sys_code, struct user_regs_struct regs);

// disp_signal.c
int display_sig(user_input_t user, siginfo_t *sig);

#endif /* DISPLAY_H */
