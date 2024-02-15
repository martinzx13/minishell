#include "parse.h"

void ft_putstr(const char *str)
{
    int i = -1;

    while (str[++i])
        write(1, &str[i], 1);
}