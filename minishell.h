#ifndef MINISHELL_H
# define MINISHELL_H
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "readline/readline.h"
#include "readline/history.h"
#include <stdlib.h>


typedef struct s_env
{
	char 			*key;
	char 			*val;
	struct s_env	*next;
}t_env;

typedef struct s_data
{
	t_env	*env;
	char **command;
} t_data;

typedef enum
{
	SEP = 1,
	WORD,
	REDIR_OUT,//>
	REDIR_IN,// <
	REDIR_APPEND,//>>
	REDIR_INSOURCE,//<<
	PIPE,//|
	EXP_FIELD,//
	FIELD,//'
} defines;

char **ft_split(char const *s, char c);
int	ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char *ft_get_value(char *key, t_data *ptr);

#endif
