#include "parse.h"

/*
    List of function to implement.
    1. strcmp.
    2. strtok.
    3. strchr.
*/

void ft_parse_handle(char * token)
{
    char *close_quotes;
    if (strcmp(token, "echo") == 0)
    {
        if ((token = strtok(NULL, "")) != NULL)
        {
            if (*token == '\"')
            {
                token++;
                close_quotes = strchr(token, '\"');
                if (close_quotes != NULL)
                {
                    *close_quotes = '\0';
                }
            } // check the opening quotes.
            ft_putstr(token);
        }
        write(1, "\n", 1);
    }
}
void ft_create_tokens(char *line)
{
    char *token;
    char *delimiter;

    delimiter = " ";
    token = strtok(line, delimiter);
    ft_parse_handle(token);

    // Check for the command to exit the line.
    if (strcmp(line, "exit") == 0)
        exit(EXIT_SUCCESS);
}

void *ft_parse_manager(char *argvs[])
{
    char *line;

    while (1 && argvs)
    {
        line = readline("martinxz13/shell:$");
        // Check for Ctrl+D (EOF) to exit the loop
        if (!line)
            break;

        /*
            1. This function is usesfull to add the history of the programm,
            so I need to check if there is any memory leacks.

        */
        add_history(line);
        /*
            This function will start, to handle the input. 
            1. Recieve the line read. 
        */
        ft_process_data(line);

        free(line);
    }
    return NULL;
}