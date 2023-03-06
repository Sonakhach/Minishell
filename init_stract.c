#include "minishell.h"

void	struct_zeroed(t_data *data, char **env)
{
    init(data, env);
    data->splited_pipe = NULL;
    data->pipe= NULL;
    // data->pipe->argv = NULL;
    // vars->pipe->head_env = env;
    // vars->env = env;
    // data.pipe.fd_in = 0;
    // data->fd_out = 1; 
    

    // char			*content;
	// /* int				fd_in;  // 0
	// int				fd_out; // 1*/
	// char			**argv; // null
	// // char			*type;
	// t_redirect		*red; // null
	// t_env			*head_env;  // data->env;
	// char			**env;  // env;
	// struct s_pipe	*next;  // null

}