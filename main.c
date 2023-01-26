// echo "xg''fch'gcj'hv" | cat | "ls" -la | echo "hctfyuu | ijiuhouhuh |||||" | cat  
// ls -la "$PWD"$HOME $SFAFSF biuhbui $PWD'$HOME'  sdgsdg -> ls -la /Users/sokhacha/Users/sokhacha biuhbui /Users/sokhacha/Users/sokhacha
#include "minishell.h"
#include <fcntl.h> 

// char	*raplace_vars(char	*src)
// {
// 	char *res;


// 	return (res);
// }


int init(t_data	*data, char **envp)
{
	int i;
	t_env *tmp_first_node;
	char **split_env;
	i = 0;
	(*data).env =  (t_env *)malloc(sizeof(t_env));

	
	tmp_first_node = data->env;
	while (envp[i])
	{
	//printf("%s\n", envp[i]);
		split_env = ft_split(envp[i], '=');
		data->env->key = split_env[0];
		data->env->val = split_env[1];		
		//printf("value = %s\n", data->env->val = split_env[1]);
		if (!envp[i + 1])
			break;
		data->env->next = (t_env *)malloc(sizeof(t_env));
		data->env = data->env->next;	
		i++;
	}
	data->env = tmp_first_node;
	return (0);
}

char *ft_get_value(char *key, t_data *ptr)
{
	while (ptr->env)
	{
		if (ft_strcmp(key, ptr->env->key)==0)
			return (ptr->env->val);
		ptr->env = ptr->env->next;
	}
	return ("chka tenc ban");
}

char *get_readline()
{
	int i;
	char *ptr;
	int first;
	int second;
	int count;
	int len;
	char *glob_str = NULL;

	first = 0;
	second = 0;
	i = 0;
	count = 0;
	while (1)
	{
		ptr = readline("minishell-$ ");
		len = ft_strlen(ptr);
		// while (ptr && ptr[i])
		// {
			while (ptr[i] != '$')
			{
				// ft_substr(ptr,i,1);
				glob_str = ft_strjoin(glob_str,ft_substr(ptr,i,1));
				i++;
			}

			//second = len-count;
			// i++;
		// }
	return(printf("%s\n", glob_str));
	}

}

// t_env *env_fun(t_data *data, char **env, char *tmp)
// {
// 	char **split;
// 	char **split_env;
// 	int		i;
// 	int j;
// 	t_env *tmp_struct_node;

// 	i = 0;
// 	j = 0;
// 	(*data).env =  (t_env *)malloc(sizeof(t_env));
// 	tmp_struct_node = data->env;
// 		split=ft_split(tmp,'$');
// 		while (split[i])
// 		{
// 				while (env[j])
// 				{
// 					//printf("%s\n", env[j]);
// 					split_env = ft_split(env[j], '=');
// 					if (ft_strcmp(split[i], split_env[0]) == 0)
// 					{
// 						data->env->key = split_env[0];
// 						data->env->val = split_env[1];
// 						//printf("%s\n", data->env->key = split_env[0]);
// 						//printf("%s\n", data.env->val = split_env[1]);
// 						data->env->next = (t_env *)malloc(sizeof(t_env));
// 						data->env = data->env->next;	
// 						j = 0;
// 						break;
// 					}
// 					j++;
// 				}

// 				i++;
// 		}
// 		data->env = tmp_struct_node;
// 		printf("%s\n", data->env->val = split_env[1]);
// 		return (data->env);
// }

// t_data *env_fun_for_chakert(t_data *data,char **env, char *tmp, int count)
// {
// 	int first;
// 	int second;
// 	int k;
// 	int len;
// 	char *str;

// 	first = 0;
// 	second = 0;
// 	k = 0;
// 	len = 0;

// 	while (tmp[k])
// 	{
// 		if (tmp[k] == '"')
// 		{
// 			if (count <= 0)
// 			{
// 				first = k;
// 				// printf("Hello 1st %d\n", first);
// 			}
// 			else if(count == 1)
// 			{
// 				second = k;
// 				// printf("hELLO 2ND: %d\n", second);
// 			}
// 			count++;
// 		}
// 		if (count == 2)
// 		{
// 			len = second - first;
// 			str = ft_substr(tmp, first+1, len - 1);
// 			// printf("str: %s\n", str);
// 			env_fun( &data, env, str);
// 			count = 0;
// 		}
// 		k++;
// 	}
// return (data->env);
// }

// t_data *env_fun_for(t_data *data,char **env, char *tmp, int count)
// {
// 	int first;
// 	int second;
// 	int k;
// 	int len;
// 	char *str = 0;

// 	first = 0;
// 	second = 0;
// 	k = 0;
// 	len = 0;
// 	int tmp_len = ft_strlen(tmp);
// 	while (k < tmp_len)
// 	{
// 		if (count == 0 && tmp[k] == '$')
// 		{
// 			first = k;
// 			// printf("hello 1st nn: %d\n", first);			
// 		}
// 		else if(count == 0 && (tmp[k + 1] == '$' || tmp[k + 1] == '\0') )
// 		{			
// 			second = k + 1;		
// 			// printf("Hello 2nd nn: %d\n", second);
// 			len = second - first;
// 			str = ft_substr(tmp, first, len);
// 			env_fun(&data, env, str);
// 				// printf("first: %d\n", first);
// 				// 	printf("len: %d\n", len);
// 			// printf("tmp[%s]\n", str);	
// 			first = 0;
// 			second = 0;
// 		}
// 		k++;
// 	}
// 	return (data->env);
// }

int main(int ac,  char **av,  char **env)
{
	(void)(av+ac);
	t_data	data;
	t_env *ptr;
	init(&data, env);
	// ptr = data.env;
	// while(ptr)
	// {
	// 	printf("key = %s\n", ptr->key);
	// 	ptr = ptr->next;
	// }

	
	//printf("%s\n", ft_get_value("PATHk", &data));
	get_readline();
// 	char *tmp;
// 	char *str;
// 	int count;
// 	int k;
// 	char *ptr;
	
	
// 	while (1)
// 	{
// 		k = 0;
// 		count = 0;
// 		tmp = readline("minishell-$ ");
// 		env_fun_for_chakert(&data,env, tmp,  count);
// 		env_fun_for(&data,env,tmp,  count);
// 		// ft_get_value("PWD", data.env);
// 		// while (tmp[k])
// 		// {	
// 		// 	// printf("%d\n", count);
// 		// 	/* if (k != 0)
// 		// 	{				
// 		// 		str = env_fun_for_chakert(tmp, count);
// 		// 		printf("strstr: %s\n", str);
// 		// 		env_fun( &data, env, str);				
// 		// 	}		 */	
// 		// 	if (/* count == 0 && */ tmp[k]== '$')
// 		// 	{
// 		// 		// printf("hi");
// 		// 		ptr = env_fun_for(tmp,  count);
// 		// 		printf("ptrptr: %s\n", ptr);
// 		// 		env_fun(&data, env, ptr);
// 		// 	}
// 		// 	k++;
// 		// }
// 		add_history (tmp);
// 	}
	return (0);
}
