#include "parse.h"

void handle_signal(int signal1)
{
    if (signal1 == SIGINT)
        ft_putstr("\nmartinxz/shell $> ");
    else if (signal1 == SIGQUIT)
       ft_putstr("");
    else if (signal1 == SIGCHLD)
        ft_putstr("Child process terminated\n");
}

void ft_signal_manager()
{
    struct sigaction sa;

    sa.sa_handler = &handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL); // Handle Ctrl+C
    signal(SIGQUIT, SIG_IGN);
    sigaction(SIGCHLD, &sa, NULL); // Handle child process termination
}
