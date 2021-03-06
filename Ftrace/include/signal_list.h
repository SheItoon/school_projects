/*
** EPITECH PROJECT, 2021
** SIGNAL_LIST_H
** File description:
** signal_list
*/


#ifndef SIGNAL_LIST_H
#define SIGNAL_LIST_H

#include "display_private.h"
#include <signal.h>

const signal_t SIGNAL_LIST[] =
{
    {SIGHUP, "SIGHUP"}, {SIGTERM, "SIGTERM"}, {SIGQUIT, "SIGQUIT"},
    {SIGILL, "SIGILL"}, {SIGTRAP, "SIGTRAP"}, {SIGABRT, "SIGABRT"},
    {SIGBUS, "SIGBUS"}, {SIGFPE, "SIGFPE"}, {SIGKILL, "SIGKILL"},
    {SIGUSR1, "SIGUSR1"}, {SIGSEGV, "SIGSEGV"}, {SIGUSR2, "SIGUSR2"},
    {SIGPIPE, "SIGPIPE"}, {SIGALRM, "SIGALRM"}, {SIGTERM, "SIGTERM"},
    {SIGSTKFLT, "SIGTKFLT"}, {SIGCHLD, "SIGCHLD"}, {SIGCONT, "SIGCONT"},
    {SIGSTOP, "SIGSTOP"}, {SIGTSTP, "SIGTSTP"}, {SIGTTIN, "SIGTTIN"},
    {SIGTTOU, "SIGTTOU"}, {SIGURG, "SIGURG"}, {SIGXCPU, "SIGXCPU"},
    {SIGXFSZ, "SIGXFSZ"}, {SIGVTALRM, "SIGVTALRM"}, {SIGPROF, "SIGPROF"},
    {SIGWINCH, "SIGWINCH"}, {SIGPOLL, "SIGPOLL"}, {SIGPWR, "SIGPWR"},
    {SIGSYS, "SIGSYS"}, {-1, 0x0}
};

#endif /* SIGNAL_LIST_H */
