/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** relative_functions
*/

#include "ftrace.h"
#include "tracer.h"
#include <fcntl.h>
#include <gelf.h>
#include <elf.h>
#include <libelf.h>
#include <libelf.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <wait.h>

static char *get_function_name(unsigned long long rip, user_input_t user)
{
    sym_t *ptr = user.function_symbols;
    unsigned mask = 0xFFF;

    rip = mask & rip;
    if (!ptr)
        return 0x0;
    for (; ptr != 0x0; ptr = ptr->next) {
        if (rip == (mask & ptr->addr))
            return ptr->func_name;
    }
    return 0x0;
}

user_input_t handle_func_entering(struct user_regs_struct rgs, user_input_t u)
{
    size_t default_size = 64;
    char *name = get_function_name(rgs.rip, u);

    if (name == 0x0) {
        name = malloc(sizeof(char) * default_size);
        snprintf(name, default_size, "func_%#llx@%s", rgs.rip,
        get_last(u.args[0], '/'));
    }
    fprintf(u.out, "Entering function %s at %#llx\n", name, rgs.rip);
    u.stack = append_func(u.stack, name);
    return u;
}

user_input_t handle_func_exit(user_input_t usr)
{
    fprintf(usr.out, "Leaving function %s\n", usr.stack->function_name);
    usr.stack = pop_first(usr.stack);
    return usr;
}

user_input_t check_relative_functions(unsigned short code, user_input_t usr,
struct user_regs_struct regs)
{
    static bool might_call = false;

    if (!usr.execve_started)
        return usr;
    if (is_exiting_function(code) && usr.stack)
        return handle_func_exit(usr);
    if (might_call && IS_CALLING_RELATIVE(code)) {
        might_call = false;
        return handle_func_entering(regs, usr);
    }
    might_call = false;
    if (MIGHT_CALL(code)) {
        might_call = true;
    }
    return usr;
}
