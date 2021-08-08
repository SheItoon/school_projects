/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** disp_signal
*/

#include "display.h"
#include "display_private.h"
#include "signal_list.h"
#include "ftrace.h"
#include <sys/ptrace.h>
#include <ctype.h>
#include <string.h>

static char *get_signal_to_string(int signo)
{
    size_t i = -1;

    while (SIGNAL_LIST[++i].sig_code != -1)
        if (SIGNAL_LIST[i].sig_code == signo)
            return SIGNAL_LIST[i].to_string;
    return 0x0;
}

int display_sig(user_input_t user, siginfo_t *sig)
{
    if (!sig)
        return ERROR;
    fprintf(user.out, "Received signal %s\n",
    get_signal_to_string(sig->si_signo));
    return SUCCESS;
}
