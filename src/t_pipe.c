/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:58:54 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:58:56 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*new_t_pipe(char **tmp)
{
	t_pipe	*new_node;

	new_node = malloc(sizeof(t_pipe));
	new_node->argv = tmp;
	new_node->next = NULL;
	return (new_node);
}

t_pipe	*ft_t_pipe_last(t_pipe *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_t_pipe_add_back(t_pipe **lst, t_pipe *new)
{
	t_pipe	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_t_pipe_last(*lst);
	new_node->next = new;
}
