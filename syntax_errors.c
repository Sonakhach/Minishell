// Harcer !!!
// 2 hat || error !!!!
// "echo 14| ba" == 'echo 14| ba' => echo 14| ba: command not found
// echo   &&>  abc &x     >>    amalia   < 121 ??????
#include "minishell.h"

// void	check_error(char *ptr, int *i)
// {
// 	while (ptr && ((ptr[*i] >= 9 && ptr[*i] <= 13) || ptr[*i] == 32))
//         (*i)++;
// 	if (syntax_error(ptr) == 1);
// }

int	check_quot_double(char *ptr)
{
	int	i;
	int	count;
	int	single_quote;
	int	double_quote;

	i = 0;
	count = 0;
	single_quote = 0;
	double_quote = 0;

	if (!ptr)
		printf ("no readline\n");
	while (ptr && ptr[i])
	{
		while (ptr && ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] <= 32))
			(i)++;
		if (ptr && ptr[i] == '"' )
		{
			count++;
			printf("count_if_2  = %d\n", count);
			printf("count_if_ i ==== %d\n", i);
			if (count == 1)
			{
				printf("if _ 3 && i = %d\n", i);
				for_space_quot(ptr, '"', &i);
				printf("durs ekav i = %d\n", i);
			}
		}
		if(ptr[i] == '\'')
		{
			single_quote++;
			printf("if _ 4 && i = %d\n", i);
			printf("single_quote = %d\n", single_quote);
		}
		else if (ptr[i] == '"')
		{
			double_quote++;
			printf("if _ 4 && i = %d\n", i);
			printf("double_quote = %d\n", double_quote);
		}
		(i)++;
	}
	if (count % 2 != 0 ||( count % 2 == 0 && (single_quote %2 != 0  || double_quote % 2 != 0)))
	{
		printf("Syntax error1\n");
		return (1);
	}

	return (0);
}

// echo 'hello \'| > "cat" lol.c'
char *check_quot_one(char *ptr)
{
	int i;
	int count;

	i = 0;
	count = 0;	
	while (ptr && ptr[i])
	{
		if(ptr[i]== '\\' && ptr[i + 1] == '\'' )
			i++;
		else
		{
			if (ptr[i] == '\'')
				count++;
		}
		i++;
	}
	if (count % 2 != 0)
	{
		printf("Syntax error\n");
		exit(1);
	}
	return (ptr);
}

int	syntax_error(char *ptr, int *i)
{
    
    while (ptr && ((ptr[*i] >= 9 && ptr[*i] <= 13) || ptr[*i] == 32))
        (*i)++;
    if (ptr && (ptr[*i] == '&' || ptr[*i] == '|' || ptr[*i] == ')' || ptr[*i] == '(' || ptr[*i] == ';'
        || ptr[*i] == '>' || ptr[*i] == '<'))
	{
        printf("minishell: syntax error near unexpected token `%c'\n", ptr[*i]);
		printf(" i = %d\n", *i);
		return (1);
	}
	return (0);
}

int	metachar_error(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] && ptr[i] != '\0')
	{
		while (ptr && (ptr[i] >= 9 && ptr[i] <= 13) && ptr[i] == 32)
			i++;
		while (!ft_strchr(METACHARACTER_ERROR, ptr[i]))
			i++;
		if ((ptr[i] && ptr[i] == '<' && ptr[i + 1] && ptr[i + 1] == '<') || (ptr[i] && ptr[i] == '>'
			&& ptr[i + 1] && ptr[i + 1] == '>'))
		{
			i += 2;
			if (syntax_error(ptr, &i) == 1)
				return (1);
		}
		else if (ptr[i] && (ptr[i] == '>' || ptr[i] == '<'))
		{
			i++;
			if (syntax_error(ptr, &i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

//  command not found !!!
// syntax error near unexpected token `newline' ???
 
//  int	shlash_quote(char *ptr, int *i)
//  {
// 	while(ptr && ptr[*i])
// 	{
		
// 	}
//  }