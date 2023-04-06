/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:56:31 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:56:33 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	for_space(char *ptr, char c, int i)
{
	if (ptr[i] == c)
	{
		i++;
		while (ptr[i] && ptr[i] != c)
			i++;
		if (ptr[i])
			i++;
	}
	return (i);
}

bool	is_append_out(char c, char d)
{
	return ((c == '>' && d == '>'));
}
