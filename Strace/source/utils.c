/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "strace.h"
#include "strace_entry.h"

char *read_string(pid_t child, unsigned long addr)
{
    char *val;
    unsigned long long read = 0;
    unsigned long long allocated = 4096;
    unsigned long long tmp;

    if ((val = malloc(allocated)) == NULL)
        return (NULL);
    while (1) {
        if (read + sizeof(tmp) > allocated)
            val = realloc(val, allocated *= 2);
        tmp = ptrace(PTRACE_PEEKDATA, child, addr + read);
        if (errno != 0) {
            val[read] = 0;
            break;
        }
        memcpy(val + read, &tmp, sizeof(tmp));
        if (memchr(&tmp, 0, sizeof(tmp)) != NULL)
            break;
        read += sizeof(tmp);
    }
    return (val);
}

unsigned long long get_syscall_arg(pid_t child, int arg_nb)
{
    int regs[SYSCALL_MAXARGS];

    regs[0] = RDI;
    regs[1] = RSI;
    regs[2] = RDX;
    regs[3] = R10;
    regs[4] = R8;
    regs[5] = R9;
    return (get_register(child, regs[arg_nb]));
}

unsigned long long get_register(pid_t child, int pos)
{
    int offset = sizeof(unsigned long long) * pos;
    unsigned long long value = ptrace(PTRACE_PEEKUSER, child, offset);

    return (value);
}

const char *get_syscall_name(int scn)
{
    entry_t *ent;
    static char buf[FUNC_MAX_LEN];

    if (scn <= MAX_SYSCALL_NUM) {
        ent = &entries[scn];
        if (ent->name)
            return (ent->name);
    }
    snprintf(buf, sizeof(buf), "sys_%d", scn);
    return (buf);
}
