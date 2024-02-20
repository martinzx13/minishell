#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *homemade_strtok(char *str, const char *delimiters)
{
    static char *last_token = NULL;
    char *token;

    if (str != NULL)
    {
        last_token = str;
    }
    else if (last_token == NULL)
    {
        return NULL;
    }

    // Find the start of the token
    while (*last_token != '\0' && strchr(delimiters, *last_token) != NULL)
    {
        last_token++;
    }

    if (*last_token == '\0')
    {
        return NULL;
    }

    // Save the start of the token
    token = last_token;

    // Find the end of the token
    while (*last_token != '\0' && strchr(delimiters, *last_token) == NULL)
    {
        last_token++;
    }

    if (*last_token != '\0')
    {
        *last_token = '\0';
        last_token++;
    }

    return token;
}

char *ft_lexer_analysis(char *tokens)
{
    char *token;

    token = homemade_strtok(tokens, "2");
    while (token != NULL)
    {
        printf("token changed: %s\n", token);
        token = homemade_strtok(NULL, "2");
    }

    return NULL;
}

int main()
{
    char str[] = "ls22-l2|2echo222\"this is the \"2|22cat2>>2file.txt";
    const char *delimiters = "|";
    char **token_holder;
    int i = 0;
    
    token_holder = (char **)malloc(sizeof(char *) * 100); // Allocate memory for 100 pointers
    if (!token_holder)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Tokenize the string using homemade_strtok
    char *tokens = homemade_strtok(str, delimiters);
    while (tokens != NULL)
    {
        token_holder[i] = tokens;
        tokens = homemade_strtok(NULL, delimiters);
        i++;
    }

    // // Set the last element of token_holder to NULL
    token_holder[i] = NULL;

    // Print the tokens
    int j = 0;
    while (token_holder[j] != NULL)
    {
        printf("token_holder[%d] = :%s:\n", j, token_holder[j]);
        ft_lexer_analysis(token_holder[j]);
        j++;
    }

    return 0;
}
