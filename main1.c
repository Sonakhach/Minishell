#include "minishell.h"

t_redirect	*redirect_test(t_pipe *pipe);

int main(int ac,  char **av,  char **env)
{
	(void)(av+ac);
	int i;
	t_data	data;
	char *ptr = NULL;
	i = 0;

	struct_zeroed(&data, env);
	// init(&data, env);
// 	// printf("%s\n", ft_get_value("PATH", &data));
// 	// char	*test = "\"$PWD\"$HOME $SFAFSF biuhbui $PWD'$HOME'  sdgsdg";
	while (1)
	{
		ptr = readline("minishell-$ ");
		if (*ptr == '\0')
			continue ;
		add_history(ptr);
		// if (syntax_error(ptr, &i) == 1 || metachar_error(ptr) == 1 ) // >a     ev ls|ls | "|ls|"
		// 	continue ;
		// if (syntax_error(ptr, &i) == 1)
		// 	continue ;
		// if (metachar_error(ptr) == 1)
		// 	continue ;							// kara chlini
		// check_qoutes(ptr); // sxala ashxatum

		// check_quot_double(ptr);
		// check_quot_one(ptr);
		// print_list_head_env(data);
		split_string(ptr, &data); // ls|ls | "|ls|"  sxala ashxatum
		print_lists(data.pipe);

		t_pipe *tmp1 = data.pipe;
		while (tmp1)//pttvum e michpaipain taracutjunerov u juraqanchjuri hamar gtnum redirektnery u faili anuner@
		{
			tmp1->red = redirect_test(tmp1); // sxal ls>a>b
			tmp1 = tmp1->next;
		}
		// split_s__to_argv(data.pipe);


		//////**************************
		// hendl_dolar(&data, ptr);
		// printf("comand : %s\n", hendl_doloar_comand(&data, ptr));
		///////////////************************

		// send_env(&data);
		// t_pipe *tmp = data.pipe;
		// int	i = 0;
		 	
		// 	while (data.pipe->argv[i])
		// 	{
		// 		printf("argv[i] = %s\n", data.pipe->argv[i++]);
		// 	}
			
		// 	data.pipe = data.pipe->next;
		// }
		
		// print_env(&data);
		// print_list(data.pipe->red);
		// print_list(type);
    	// while (head)
		// {
		// 	printf("head->content: %s\n", head->content);
		// 	head = head->next;
		// }
		// get_pipe_readline(&data, ptr);
		// printf("hello\n");
		// i++;
	}
	
//     // t_pipe *head = get_pipe_readline(&data, ptr);
	return (0);
}