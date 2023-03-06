// Harcer !!!

#include "minishell.h"

char	*ft_strjoin_ft(char const *s1, char c)
{
	char	*ptr;
	int		k;

	k = ft_strlen(s1);
	ptr = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
		*ptr++ = *s1++;
	if (c)
		*ptr++ = c;
	*ptr = '\0';
	return (ptr - k - 1);
}

t_redirect	*redirect_test(t_pipe *pipe)
{
	int 		i;
	t_pipe 		*top;
	t_redirect	*head;

	i = 0;
	top = pipe;
	top->s = (char *)malloc(sizeof(char));
	head = NULL;
	while (top->content[i] != '\0')
	{
		while (is_space(top->content[i]))
			i++;
		if (is_redirect_in(top->content[i]) || is_redirect_out(top->content[i]))
			redirect_f_name_flag(top, &head, &i);
		else
		{
			redirect_to_command(top, &i);
			i--;
		}
		if (top->content[i])
			i++;
	}
	print_list(head);
	return (head);
}


int	redirect_f_name_flag(t_pipe *top, t_redirect **head, int *i)
{
	int		x;
	int		start;
	char	*tmp;

	x = 1;
	// while (top->content[*i] != '\0')
	// {
		// if (is_redirect_in(top->content[*i]) || is_redirect_out(top->content[*i]))
		// {
			if (is_append_in(top->content[*i], top->content[*i + 1]) || is_append_out(top->content[*i], top->content[*i + 1]))
				x++;
			tmp = ft_substr(top->content, *i, x);
			*i += x;
			while (is_space(top->content[*i]))
				(*i)++;
			start = *i;
			while (!ft_strchr(METACHARACTER, top->content[*i]))
				(*i)++;
			ft_t_redirect_add_back(head, new_t_redirect(ft_substr(top->content, start, *i - start), tmp));
			x = 1;
			*i -= 1;
		// }
		// else
		// 	return(1);
		// (*i)++;
	// }
	return (0);
}


// char	*word_from_line(char *line, int *i)
// {

// }

int	redirect_to_command(t_pipe *top, int *i)
{
	int k;
	char *tmp_comand;
	k = 0;
	
	while (top->content[*i] != '\0')
	{
		// while (ft_strchr(METACHARACTER, (top->content[*i])))
		// {
		// 	if ((is_redirect_in(top->content[*i]) || is_redirect_out(top->content[*i])))
		// 		return (0);
		// 	(*i)++;
		// }
		if (top->content[*i] == '\'')
			redirect_to_quote(top,  i, '\'');
		else if (top->content[*i] == '"')
		{
			redirect_to_quote(top,  i, '"');
			printf("aaaaa = %d\n", *i);
		}
		// else if (top->content[*i] == '$')
		// {
		// 	printf("i = %d\n", *i);
		// 	// hendl_dolar(top, top->content, i);
		// 	// hendl_doloar_comand(top, top->content);
		// }
		k = (*i);
		while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
			(*i)++;
		// printf("TMPcmd: %s\n", tmp_comand);
		tmp_comand = ft_substr(top->content, k, *i - k);
		top->s = ft_strjoin(top->s, ft_strtrim(tmp_comand, METACHARACTER));
		top->s = ft_strjoin_ft(top->s, 42);
		printf("cmd: %s\n", top->s);
		if (top->content[*i])
			(*i)++;
	}
	return (1);
}

void	redirect_to_quote(t_pipe *top, int *i, char c)
{
	if (top->content && *i < ft_strlen(top->content))
	{
		if (top->content[*i] == c)
		{
			(*i)++;
			top->s = ft_strjoin(top->s, split_quote(top->content, &(*i), c));
			top->s = ft_strjoin_ft(top->s, 42);
		}
		(*i)++;
	}
}

void	split_s__to_argv(t_pipe *pipe) //  (null) (null) zsh: segmentation fault
{
	int		i;
	t_pipe	*tmp;

	i = 0;
	tmp = pipe;
	tmp->argv = ft_split(tmp->s, 42);
	while (tmp && tmp->s[i])
	{
		printf("%s\n", tmp->argv[i]);
		i++;
	}
}

// void	quotes(char *ptr, int *j)
// {
// 	int	i;

// 	i = *j;
// 	if (i > 0 && (ptr)[i - 1] && (ptr)[i - 1] == 92)
// 		return ;
// 	if ((ptr)[i] && (ptr)[i] == 34)
// 	{
// 		i++;
// 		while ((ptr)[i] && (ptr)[i] != 34)
// 			i++;
// 		if ((ptr)[i])
// 			i++;
// 	}
// 	if ((ptr)[i] && (ptr)[i] == 39)
// 	{
// 		i++;
// 		while ((ptr)[i] && (ptr)[i] != 39)
// 			i++;
// 		if ((ptr)[i])
// 			i++;
// 	}
// 	*j = i;
// }

char *hendl_doloar_comand(t_pipe *pipe, char *test)
{
    int     i;
    int     j;
    int     len;
    char    *ptr = NULL;
    char    *str1;
    char    *str_line;

    i = 0;
    j = 0;
    str_line = ptr;
    len = ft_strlen(test);
    str_line = malloc(sizeof(char)*(len - pipe->len_key_sum + pipe->len_val_sum + 1));   
	if (!str_line)
		return (NULL);
    while (test[j] && (is_redirect_in(test[j]) || is_redirect_out(test[j])))
    {
		printf("mtav?????????????????????????????\n");
        if (/*test[j -1] != '\'' && test[j] == '$' && */(ft_isalpha(test[j+1]) || test[j+1] == '_'))
        {
            j++;
            i = j;
            while((ft_isalpha(test[j]) || test[j] == '_' || ft_isdigit(test[j])))
                j++;
            str1 = ft_substr(test,i,j - i);
            ptr = get_dolar_val(pipe, str1);
	printf("ptr *************: %s\n", ptr);
			if (ptr)
                str_line = ft_strjoin(str_line,ptr);
            j--;
        }
        else
        {
	printf("ptr *************: %s\n", ptr);
            ptr = ft_substr(test, j, 1);
            str_line = ft_strjoin(str_line,ptr);      
        }
        j++;
	}
	printf("str_linie : %s\n", str_line);
    return (str_line);
}


void hendl_dolar(t_pipe *pipe, char *str, int *i)
{
    int k;
    int j;    
    char *str1;
    char *val;

    j = 0;
    while (str[*i])
    {
        if ((ft_isalpha(str[*i + 1]) || str[*i + 1] == '_'))
        {
            (*i)++;
            k = *i; 
            while((ft_isalpha(str[*i]) || str[*i]  == '_' || ft_isdigit(str[*i])))
				{printf("dar\n");
                (*i)++;}
			printf("i_f = %d\n", *i);
            str1 = ft_substr(str, k, *i - k);
			printf("STR1: %s\n", str1);
            pipe->len_key_sum += ft_strlen(str1);
            val = get_dolar_val(pipe, str1);
			printf("val : %s\n", val);
            (*i)--;
        }
        (*i)++;
    }
}

char *get_dolar_val(t_pipe *pipe, char *str1)
{
    t_env	*head;
    char	*str;

    str = NULL;
    head = pipe->head_env;
    while (head)
    {       
        if (ft_strcmp(head->key , str1) == 0)
        {
	printf("doloar\n");
            str = head->val;
            pipe->len_val_sum += ft_strlen(str);
        }
        head = head->next;
    }
			printf("str = %s\n", str);
    return (str);
}