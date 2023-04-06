/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_export_sort_by_alphabet.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:53:31 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:53:34 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	buildin_export_all_by_alphabet_inner(t_pipe *pipe)
{
	t_env	*head;
	char	*tmp;
	char	*tmp_val;

	head = pipe->head_env;
	while (head->next)
	{
		if (head->key[0] > head->next->key[0])
		{
			tmp_val = head->val;
			tmp = head->key;
			head->val = head->next->val;
			head->key = head->next->key;
			head->next->val = tmp_val;
			head->next->key = tmp;
		}
		head = head->next;
	}
}

int	buildin_export_sort_by_alphabet(t_pipe *pipe)
{
	t_env	*head;
	int		count;
	int		i;

	count = 0;
	i = 0;
	head = pipe->head_env;
	while (head)
	{
		count++;
		head = head->next;
	}
	while (i < count)
	{
		buildin_export_all_by_alphabet_inner(pipe);
		i++;
	}
	return (1);
}
