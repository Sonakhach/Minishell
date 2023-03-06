#ifndef MINISHELL_H
# define MINISHELL_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include "./libft/libft.h"
# include "readline/readline.h"
# include "readline/history.h"
# define HEREDOC 5

# define METACHARACTER "|&;()<> \n\t"
# define METACHARACTER_ERROR "|&;)(<>"

/* typedef struct s_pipe
{
	// char			**argv;
	char			*content;
	struct s_pipe	*next;
}	t_pipe; */

typedef struct s_redirect
{
	// int	flag;  // O_APPEND || O_TRUNC || O_RDONLY || HEREDOC
	char *f_name;
	char *flag;
	// char *type;  // petq chi
	struct s_redirect *next;
} t_redirect;

typedef struct s_env
{
	char 			*key;
	char 			*val;
	struct s_env	*next;
}t_env;

typedef struct s_pipe
{
	char			*s;
	char			*content;
	int				fd_in;  // 0
	int				fd_out; // 1
	char			**argv; // null
	t_redirect		*red; // null
	t_env			*head_env;  // data->env;
	char			**env;  // env;
	struct s_pipe	*next;  // null
	int 	len_key_sum;
	int 	len_val_sum;
}	t_pipe;


typedef struct s_data
{
	t_env	*head_env;
	char	**env;
	char	**splited_pipe;
	t_pipe 	*pipe;
	int 	len_key_sum;
	int 	len_val_sum;
} t_data;

//***********************Tatev


char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char const	*s, unsigned int start, size_t len);
char 		*ft_get_value(char *key, t_data *ptr);
// int  herdoc(int c, char **v);
t_redirect	*redirect(t_pipe *pipe);
//***************** Tatev

bool		is_space(char c);
bool    	is_pipe(char c);
bool    	is_redirect_in(char c);
bool    	is_redirect_out(char c);
bool    	is_append_in(char c, char d);
bool    	is_append_out(char c, char d);
char		*valid_ls(char *str);
// t_pipe *get_pipe_readline(t_data *data);
void		split_string(char *input, t_data *data);
// void print_list(t_redirect *red);
void 		print_list_head_env(t_data data);
void 		print_lists(t_pipe *red);
int 		get_readline(t_data *data);
int 		init(t_data	*data, char **envp);
void		ft_lstadd_back(t_pipe **lst, t_pipe *new);
void		ft_lstadd_front(t_pipe **lst, t_pipe *new);
t_pipe		*ft_lstnew(void *content, t_env *env);
t_pipe		*ft_lstlast(t_pipe *lst);
int 		check_quot_double(char *ptr);
char 		*check_quot_one(char *ptr);
void		struct_zeroed(t_data *data, char **env);
int  		for_space(char *ptr, char c, int i);
int  		for_space_quot(char *ptr, char c, int *i);
void 		send_env(t_data *data);
void 		print_env(t_data *data);
void 		print_list(t_redirect *red);

//
char			*split_quote(char *top, int *i, char c);
void			ft_t_redirect_add_back(t_redirect **lst, t_redirect *new);
t_redirect		*ft_t_redirect_last(t_redirect *lst);
t_redirect 		*new_t_redirect(char *f_name, char *flag);

int		redirect_f_name_flag(t_pipe *top,t_redirect **head, int *i);
int		redirect_to_command(t_pipe *top, int *i) ;
void	redirect_to_quote(t_pipe *top, int *i, char c);

void	ft_t_pipe_add_back(t_pipe **lst, t_pipe *new);
t_pipe *new_t_pipe(char *tmp);
t_pipe	*ft_t_pipe_last(t_pipe *lst);

void hendl_dolar(t_pipe *data, char *str, int *i);
char *hendl_doloar_comand(t_pipe *data, char *test);
char 		*get_dolar_val(t_pipe *data, char *str1);


//lkejfnlwjflka

int	syntax_error(char *ptr, int *i);
int	metachar_error(char *ptr);
// void split_s__to_argv(t_pipe *pipe);

//Added by Amalia 
int check_qoutes(char *str);

///sevagrutyun

// char *hendl_doloar_comand(t_data *data, char *test);
// void hendl_dolar(t_data *data, char *str);
// char *get_dolar_val(t_data *data, char *str1);

#endif
