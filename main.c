
#include "parse.h"

/*
    1. check the access fucntion to get the path
    of te process.

*/

int main(int argc, char *argv[]) 
{
    /*
        This program will take the parsing of the minishell 
        command line. 
    1. Use the Readline funcion. 
    2. Add the command to the history.
    3. Keep looping while process the line. 
    
    */

   /*
   SIGNAL HANDLER. 
   1. There is a function that is set up at the end to 
   handle the signals.
   - I need to put a flag, because I can only interpretated the breack line, and do nothing
   if there are not commands, and I need it to handle process.
   */

   if (argc > 1)
   {
    ft_signal_manager();
    ft_parse_manager(argv);
   }
}