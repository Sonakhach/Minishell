/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:56:26 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:56:27 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

bool	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

bool	is_redirect_in(char c)
{
	if (c == '<')
		return (1);
	return (0);
}

bool	is_redirect_out(char c)
{
	if (c == '>')
		return (1);
	return (0);
}

bool	is_append_in(char c, char d)
{
	return ((c == '<' && d == '<'));
}
