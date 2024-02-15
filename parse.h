#include <unistd.h>
#include <signal.h> // Signal handler.
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void handle_signal(int signal1);
void *ft_parse_manager(char *argvs[]);
void ft_signal_manager();
void ft_putstr(const char *str);
