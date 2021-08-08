/*
** EPITECH PROJECT, 2021
** FTRACE_H
** File description:
** ftrace
*/


#ifndef FTRACE_H
#define FTRACE_H

#include <bits/types/siginfo_t.h>
#include <libelf.h>
#include <sys/types.h>
#include <sys/user.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/reg.h>
#include <stdio.h>

#define FOLLOW_FORKS            (8)
#define DISPLAY_WITHOUT_HEX     (FOLLOW_FORKS << 1)
#define OUTPUT_TO_FILE          (FOLLOW_FORKS << 2)

#define ERROR                   (84)
#define SUCCESS                 (0)

#include "tools.h"

typedef struct symtab_s sym_t;
typedef struct symtab_s {
    sym_t *next;
    sym_t *prev;

    char *func_name;
    unsigned long long addr;
} sym_t;

typedef struct user_input
{
    unsigned int output_options;
    char **args;
    char *output_filename;
    FILE *out;
    pid_t ppid;
    pid_t *children;
    func_stack_t *stack;
    Elf *elf_object;
    bool is_32_bits;
    bool execve_started;
    sym_t *function_symbols;
} user_input_t;

#define MAX_NB_SYSCALLS(is_32_bits) (is_32_bits == true ? 440 : 332)
#define MIGHT_CALL(code)            ((0xFF & code) == 0xE8)
#define IS_CALLING_RELATIVE(code)   (((0xFF00 & code) >> 8) == 0x48)
#define CALLING_SYSCALL(code)       ((code & 0x050F) != 0)

typedef struct syscall_s
{
    char const *name;
    char const *display_flags;
} syscall_t;

extern char **environ;

// input_handling.c
user_input_t load_default_settings(void);
int retrieve_user_options(int ac, char **av, user_input_t *options);

// file_handler.c
void open_outfile_if_needed(user_input_t *usr);
void close_outfile_if_needed(user_input_t *bin);

// elf_parsing.c
bool get_elf_object(char *filepath, user_input_t *);
bool is_64_bits(char *);

#endif /* FTRACE_H */
