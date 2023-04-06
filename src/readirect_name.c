/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readirect_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:57:33 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:57:36 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*fname(char *str)
{
	int		i;
	int		j;
	char	*ptr;
	char	c;

	i = 0;
	j = 0;
	ptr = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				ptr[j++] = str[i++];
			i++;
		}
		else
			ptr[j++] = str[i];
		if (str[i])
			i++;
	}
	return (ptr);
}

void	expand_redirect_dollar(t_data *data, t_redirect *tmp)
{
	char	*tmp_free;

	while (tmp)
	{
		if (tmp->flag != HEREDOC)
		{
			tmp_free = tmp->f_name;
			tmp->f_name = hendl_doloar_comand(data, tmp->f_name);
			free(tmp_free);
		}
		else
		{
			tmp_free = tmp->f_name;
			tmp->f_name = fname(tmp->f_name);
			free(tmp_free);
		}
		tmp = tmp->next;
	}
}
