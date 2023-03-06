#include "minishell.h"

int check_qoutes(char *str)
{
    int i;
    int open_quote = 0;
    int  close_quote = 0;
    i = 0;

    while (str[i] != '\0') 
    {
        if (str[i] == '"') 
        {
            if (open_quote == close_quote)
                open_quote++;
            else
                close_quote++;
        }
        else if (str[i] == '\'')
        {
            if (open_quote == close_quote)
                open_quote++;
            else
                close_quote++;
        }
        i++;
    }

    if (open_quote == close_quote) 
    {
        printf("All quotes are properly closed.\n");
        return (0);
    }
    else 
    {
        printf("There are missing quotes.\n");
        return (1);
    }

    return (0);
}