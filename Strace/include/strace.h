/*
** EPITECH PROJECT, 2021
** strace
** File description:
** strace
*/

#pragma once

#include <sys/ptrace.h>
#include <ctype.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "strace_define.h"
#include "strace_type.h"

int strace_engine(int ac, char **av);
int trace(pid_t pid, int mode);
void process_status(pid_t *pid, int *wait,
struct user_regs_struct *r, unsigned short *code, int mode);
int status_handler(int wait);
int attach_process(pid_t pid);
int launch_kid(int ac, char **av, int mode);
char *read_string(pid_t child, unsigned long addr);
void print_arg(pid_t child, unsigned long long arg, int mode,
enum arg_type_e type);
int print_exit(int exit, int mode);
void print_syscall(pid_t child, unsigned long long sysnum,
unsigned long long retval, int mode);
void print_syscall_args(pid_t child, int num, int mode);
const char *get_syscall_name(int scn);
unsigned long long get_syscall_arg(pid_t child, int arg_nb);
unsigned long long get_register(pid_t child, int pos);
