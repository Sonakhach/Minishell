/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:53:58 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:54:00 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote_double(char *ptr)
{
	int		i;
	char	c;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '"' || ptr[i] == '\'')
		{
			c = ptr[i++];
			while (ptr[i] && ptr[i] != c)
				++i;
			if (ptr[i] == '\0')
			{
				ft_printf(2, "minishell: syntax error near unexpected\
 token `newline'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
