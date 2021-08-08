/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include "strace.h"
#include "strace_entry.h"

int print_exit(int exit, int mode)
{
    if (WIFEXITED(exit)) {
        fprintf(stderr, mode ? "exit_group(%d) = ?\n"
        : "exit_group(0x%x) = ?\n", WEXITSTATUS(exit));
        fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(exit));
    }
    return (0);
}

void print_arg(pid_t child, unsigned long long arg, int mode,
enum arg_type_e type)
{
    char *str;
    int h;

    if (mode && type == INT)
        fprintf(stderr, "%lld", arg);
    else if (mode && type == STR) {
        str = read_string(child, arg);
        h = -1;
        fprintf(stderr, "\"");
        while (str[++h] && h < 32)
            fprintf(stderr, isprint(str[h]) ? "%c" : "\\%o", str[h]);
        h >= 32 ?fprintf(stderr, "\"...") : fprintf(stderr, "\"");
        free(str);
    } else
        arg ? fprintf(stderr, "0x%llx", arg)
        : fprintf(stderr, (mode ? "NULL" : "0x0"));
}

void print_syscall(pid_t child, unsigned long long sysnum,
unsigned long long retval, int mode)
{
    entry_t *ent;

    fprintf(stderr, "%s(", get_syscall_name(sysnum));
    print_syscall_args(child, sysnum, mode);
    fprintf(stderr, ") = ");
    ent = &entries[sysnum];
    if (mode)
        fprintf(stderr, ent->retval == INT ? "%lld\n" : "0x%llx\n", retval);
    else
        retval ? fprintf(stderr, "0x%llx\n", retval)
        : fprintf(stderr, "0x0\n");
}

void print_syscall_args(pid_t child,
int num, int mode)
{
    entry_t *ent = NULL;
    int nb_args = SYSCALL_MAXARGS;
    int i;
    enum arg_type_e type;
    unsigned long long arg;

    if (num <= MAX_SYSCALL_NUM && entries[num].name) {
        ent = &entries[num];
        nb_args = ent->nb_args;
    }
    i = 0;
    while (i < nb_args) {
        arg = get_syscall_arg(child, i);
        type = ent ? ent->args_value[i] : PTR;
        print_arg(child, arg, mode, type);
        if (i++ != nb_args - 1)
            fprintf(stderr, ", ");
    }
}
