
#include "parse.h"

/*
    1. check the access fucntion to get the path
    of te process.

*/

int main(int argc, char *argv[]) 
{
   if (argc > 1)
   {
    ft_signal_manager();
    ft_parse_manager(argv);
   }
}