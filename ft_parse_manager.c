#include "parse.h"

/*
    List of function to implement.
    1. strcmp.
    2. strtok.
    3. strchr.
*/

typedef enum S_TOKEN_TYPE
{
    WORD,
    PARSE_FRONT,
    PARSE_BACK,
    PIPE
}   T_TOKEN_TYPE;

typedef struct WORD
{
    T_TOKEN_TYPE type;
    char *value;
} T_WORD;

typedef struct S_WORD_LIST
{
    T_WORD *word;
    struct T_WORD_LIST *left;
    struct T_WORD_LIST *right;
} T_WORD_LIST;

T_WORD *tokenize(char* input) {

    T_WORD *tokens = malloc(3 * sizeof(T_WORD));
    tokens[0].type = WORD;
    tokens[0].value = strtok(input, "|");

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
        ft_create_tokens(line);

        free(line);
    }
    return NULL;
}