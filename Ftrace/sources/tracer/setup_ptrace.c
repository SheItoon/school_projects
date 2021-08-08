/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-strace-bogdan.guillemoles
** File description:
** setup_ptrace
*/

#include "tracer.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int setup_ptrace(user_input_t mdata)
{
    pid_t pid = fork();

    mdata.ppid = pid;
    if (pid == 0) {
        if (ptrace(PTRACE_TRACEME) == -1) {
            perror("ptrace_traceme");
            _exit(84);
        }
        raise(SIGSTOP);
        if (execve(mdata.args[0], mdata.args, environ) == -1) {
            perror("execve");
            _exit(ERROR);
        } else return 0;
    } else {
        open_outfile_if_needed(&mdata);
        return trace_loop(mdata);
    }
}
