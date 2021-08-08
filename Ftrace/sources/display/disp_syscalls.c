/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** disp_syscalls
*/

#include "ftrace.h"
#include "display_private.h"
#include "syscall_list.h"
#include "display.h"
#include "tools.h"
#include "stdarg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/user.h>

static unsigned long long load_reg(struct user_regs_struct regs, size_t ctr)
{
    switch (ctr) {
        case 0: return regs.rdi;
        case 1: return regs.rsi;
        case 2: return regs.rdx;
        case 3: return regs.r10;
        case 4: return regs.r9;
        case 5: return regs.r8;
        default: break;
    }
    return 0;
}

static int scase_display(user_input_t usr, char *fmt,
unsigned long long var, char flag)
{
    switch (flag) {
        case STRING:
            if (usr.output_options & DISPLAY_WITHOUT_HEX)
                return display(usr, fmt, read_str(usr, var));
            else return display(usr, fmt, var);
        case STR_ARRAY:
            if (usr.output_options & DISPLAY_WITHOUT_HEX)
                return display(usr, fmt, read_str_array(usr, var));
            else return display(usr, fmt, var);
        case STRUCT:  case UNSIGNED: case NUMBER: case POINTER: case LONG:
            return display(usr, fmt, var);
        default: break;
    }
    return 0;
}

int display_sys(user_input_t user, int sys_code, struct user_regs_struct regs)
{
    syscall_t scall = user.is_32_bits ? LIST_32BITS[sys_code]
    : SCALL_LIST[sys_code];
    size_t nb_args = !scall.display_flags ? 0 : strlen(scall.display_flags);
    register unsigned long long reg_value = 0;
    register size_t ctr = -1;
    char *format = strdup("%");

    fprintf(user.out, "Syscall %s(", scall.name);
    while (++ctr < nb_args) {
        reg_value = load_reg(regs, ctr);
        format = append_c(format, scall.display_flags[ctr]);
        if (ctr + 1 < nb_args)
            format = append(format, ", ");
        scase_display(user, format, reg_value, scall.display_flags[ctr]);
        free(format);
        format = strdup("%");
    }
    return (display(user, ") = %d\n", regs.rax) ? ERROR : SUCCESS);
}
